#include <stdio.h>

void main()
{
char a,b;
scanf("%c%c", &a, &b);
if (a == '9' || b == '9') printf("yes");
else printf("no");
}