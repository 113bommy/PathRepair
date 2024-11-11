#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+10;
int a[MAXN];
int b[MAXN];
int n,k;
int fac[31];

void init()
{
    for(int i = 0; i < 31; ++i)
        fac[i] = 1<<i;
}

int main()
{
    init();
    scanf("%d %d",&n,&k);
    long long res = 0;
    for(int i = 0; i < n; ++i)
    {
        scanf("%d %d",&a[i],&b[i]);
        if((a[i]&k)==a[i]) res += b[i];
    }
    for(int i = 30; i >= 0; --i)
    {
        if(k&fac[i])
        {
            int tmp = (k^fac[i])|(fac[i]-1);
            //printf("%d\n",tmp);
            int ans = 0;
            for(int j = 0; j < n; ++j)
                if((a[j]&tmp)==a[j]) ans += b[j];
            res = max(res,ans);
        }
    }
    printf("%lld\n",res);
    return 0;
}
