#include<bits\stdc++.h>
using namespace std;

#define mod 1000000007

typedef long long ll;

ll N;
ll dp[100][5] = {0};

int main()
{
    scanf("%lld",&N);
    dp[61][0] = 1;
    for(int i = 60; i >= 0; i--)
    {
        ll mem = (N >> i) & 1;
        dp[i][2] += dp[i + 1][2] * 3;
        if(mem)
        {
            dp[i][2] += dp[i + 1][1] * 2;
            dp[i][1] += dp[i + 1][1];
            dp[i][1] += dp[i + 1][0];
            dp[i][0] += dp[i + 1][0];
        }
        else
        {
            dp[i][2] += dp[i + 1][1];
            dp[i][1] += dp[i + 1][1];
            dp[i][0] += dp[i + 1][1];
            dp[i][0] += dp[i + 1][0];
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i][2] %= mod;
    }
    printf("%lld\n",(dp[0][0] + dp[0][1] + dp[0][2]) % mod);
    return 0;
}
