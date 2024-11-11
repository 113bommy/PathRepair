#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
ll dp[2005][2005];
int a[2005],b[2005];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(int i=1; i<=m; i++)
        scanf("%d",&b[i]);
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
           dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1])%mod;
            if(a[i]==b[j])
                dp[i][j]=(dp[i][j]+dp[i-1][j-1]+1)%mod;


        }
    }

    printf("%lld\n",(dp[n][m]%mod+1+mod)%mod);
    return 0;
}
