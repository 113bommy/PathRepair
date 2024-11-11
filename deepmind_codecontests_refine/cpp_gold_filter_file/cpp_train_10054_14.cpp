#if not LOCAL
#define NDEBUG 1
#endif // LOCAL
#include<bits/stdc++.h>

template <typename T>
void maximize(T& a, T b) { if (a<b) a=b; };

int main()
{
        std::ios_base::sync_with_stdio(0); std::cin.tie(0);

        int n; std::cin>>n;

        int64_t preSum[n+1][4]; //preSum[i][j]: the prefix sum (1..i) on column j
        memset(preSum, 0, sizeof(preSum));

        for (int i=1; i<4; ++i) {
                for (int j=1; j<=n; ++j) {
                        int x; std::cin>>x;
                        preSum[j][i]=preSum[j][i-1]+x;
                }
        }

        int64_t dp[n+1][4];
        memset(dp, 0, sizeof(dp));

        for (int i=1; i<=n; ++i) {
                for (int j=1; j<4; ++j) {
                        dp[i][j]=-1e15;
                }
        }
        dp[1][1]=preSum[1][1];
        dp[1][2]=preSum[1][2];
        dp[1][3]=preSum[1][3];
        
        int64_t cur=preSum[1][3];
        for (int i=2; i<=n; ++i) {
                for (int j=1; j<4; ++j) {
                        for (int k=1; k<4; ++k) {
                                maximize(dp[i][j], dp[i-1][k]+preSum[i][std::max(j, k)]-preSum[i][std::min(j, k)-1]);
                        }
                }

                cur+=preSum[i][3];
                maximize(dp[i][1], cur);
                maximize(dp[i][3], cur);

                maximize(cur, dp[i-1][1]+preSum[i][3]);
                maximize(cur, dp[i-1][3]+preSum[i][3]);
        }

        std::cout<<dp[n][3];

        return 0;
}
