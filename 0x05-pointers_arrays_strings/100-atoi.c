#include "main.h"

int _atoi(char *s)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    // Skip leading whitespace characters
    while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
        i++;

    // Check the sign
    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }

    // Convert the digits to an integer
    while (s[i] >= '0' && s[i] <= '9') {
        // Handle overflow
        if (result > (INT_MAX / 10) || (result == INT_MAX / 10 && (s[i] - '0') > (INT_MAX % 10))) {
            if (sign == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return result * sign;
}
