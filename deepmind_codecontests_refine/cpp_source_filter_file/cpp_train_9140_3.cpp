#include <bits/stdc++.h>
using namespace std;

int N;
double p[3000],dp[3000][3000];
int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++)
        scanf("%lf",&p[i]);
    dp[0][0]=1.0;
    for(int i=1; i<=N; i++)
    {
        dp[i][0]=dp[i-1][0]*(1-p[i]);
        for(int j=1; j<=i; j++)
            dp[i][j]=p[i]*dp[i-1][j-1]+(1-p[i])*dp[i-1][j];
    }
    for(int i=N; i>N/2; i--)
        ans+=dp[N][i];
    printf("0.9f\n",ans);
}
