#include<cstdio>

int n, m, x, y, ans = 0;
int main()
{
    scanf(%d%d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        ans ^= x ^ y;
    }
    if(!ans) printf("YES\n"); else printf("NO\n");
    return 0;
}
