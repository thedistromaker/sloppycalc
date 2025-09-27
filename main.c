// warning_tsunami_calc.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int implicit_func();           // implicit int
int never_defined(int);        // declared but never defined

int main() {
    char buf[32];
    int x, y;
    char op;

    unsigned int u = -100;     // signed -> unsigned conversion
    int unused_var;            // unused variable
    int shadow = 1;
    {
        int shadow = 2;        // variable shadowing
        printf("Shadowed: %d\n", shadow);
    }

    int* ptr = NULL;
    *ptr = 5;                  // deref null pointer (undefined but compiles)
    
    long l = 1e20;             // implicit conversion warning
    float f = l;               // truncation

    printf("Warning Tsunami Calculator (type 'quit')\n");

    while (1) {
        printf("> ");
        gets(buf);             // deprecated/unsafe

        if (strcmp(buf, "quit") == 0)
            break;

        sscanf(buf, "%d %c %d", &x, &op, &y); // ignoring return

        switch(op) {
        case '+':
            printf("%d\n", x + y);
        case '-':                  // fallthrough
            printf("%d\n", x - y);
        case '*':
            printf("%d\n", x * y);
            break;
        case '/':
            printf("%d\n", x / y); // no div by zero check
            break;
        default:
            printf("Unknown op\n");
        }

        int arr[5];
        arr[10] = 42;            // out-of-bounds
    }

    char* str = "Hello";
    str[0] = 'h';                // modifying string literal

    return;                       // missing return value
}

// implicit function definition (C23)
implicit_func() {
    return 123;
}
