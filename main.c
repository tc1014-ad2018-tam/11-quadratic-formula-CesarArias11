/* This program will give the user the result of the quadratic formula, calculated from three variables given by the user.
 * The program is made to accept numbers only, but in case there's a number and then a string in the same input, it will
 * keep only the number.
 * Once the variables are validated, the program will throw two results, one result or none, depending on the value of
 * the discriminant.
 *
 * Author: César Alejandro Arias Perales
 * Date: October 4th, 2018
 * Mail: a01411995@itesm.mx
 */

 // Predefined functions necessary for the program.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
// This are the necessary variables
// The first three of them are for the validation of the variables, the rest of them are related with the quadratic formula.
    char entrada1[30];
    char entrada2[30];
    char entrada3[30];
    char *residuo;
    double a;
    double b;
    double c;
    double discriminant;
    double root1;
    double root2;

// This is how the value 'a' is validated.
    printf("Give me a: \n");
    fgets(entrada1, strlen(entrada1), stdin);
    a = strtod(entrada1, &residuo);

// This is how the value 'b' is validated.
    printf("Give me b: \n");
    fgets(entrada2, strlen(entrada2), stdin);
    b = strtod(entrada2, &residuo);

// This is how the value 'c' is validated.
    printf("Give me c: \n");
    fgets(entrada3, strlen(entrada3), stdin);
    c = strtod(entrada3, &residuo);

// If one of them is not valid, the program will tell the user.
    if ((strlen(entrada1) == strlen(residuo)) || (strlen(entrada2) == strlen(residuo)) || (strlen(entrada3) == strlen(residuo)) )   {
        printf("Check your inputs, one is not a number.");
// If all of them are valid, it will start to check the numeric values.
    } else {
// The value of 'a' can't be zero because there's a division in the quadratic formula including this variable.
// So there's no point of doing anything else if 'a' = 0
        if ( a == 0) {
            printf("The value of 'a' can't be zero.");
        } else {
// The value of the discriminant is essential for the quadratic formula, which value is given by the following expression.
            discriminant = b*b-4*a*c;
// In this case, there will be two results for the quadratic formula.
            if (discriminant > 0) {
                root1=(-b+sqrt(discriminant))/(2*a);
                root2=(-b-sqrt(discriminant))/(2*a);
                printf("The value of 'a' is: %lf, the value of 'b' is: %lf and the value of 'c' is %lf\n", a,b ,c);
                printf("So then, x1: %.4lf and x2: %.4lf", root1,root2);
// In this case, there's only one result.
            } else if (discriminant == 0) {
                root1 = (-b)/(2*a);
                printf("The value of 'a' is: %lf, the value of 'b' is: %lf and the value of 'c' is %lf\n", a,b ,c);
                printf("The discriminant equals 0, reason why there's only one value, which is: %.4lf", root1);
// When the discriminant is less than zero (negative) there's no answer.
            } else {
                printf("The value of 'a' is: %lf, the value of 'b' is: %lf and the value of 'c' is %lf\n", a,b ,c);
                printf("The discriminant is less than 0. There's no real value for x.");
            }
        }
    }
    
    return 0;
}