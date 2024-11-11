#include <stdio.h>
int main()
{
    int n, a[200001], i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &a[i]);

    printf("%d", a[n-1]);

    for(i = n-3; i >= 0; i-=2) printf(" %d", a[i]);

    if(n&1) for (i = 1; i <= n-2; i+=2) printf(" %d", a[i]);
    else for(i = 0; i <= n-2; i+=2) printf(" %d", a[i]);
}
