#include <stdio.h>
int n;
int main()
{
    scanf("%d", &n);
    int t = N, c = 0;
    while (t > 0) c += t % 10, t /= 10;
    if (n % c ==0) puts("Yes");
    else puts("No");
    return 0;
}