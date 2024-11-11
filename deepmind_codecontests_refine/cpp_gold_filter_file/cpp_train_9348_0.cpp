#include<iostream>
#include<vector>
using namespace std;
using i64 = long long;
int main(){
    int N, K;
    cin >> N >> K;

    vector<vector<i64>> dp(N+1, vector<i64>(N+1, 0));
    dp[0][0] = 1;

    const i64 MOD = 1e9 + 7;
    for(int n = 0; n < N; n++){
        for(int r = 0; r <= n; r++){
            dp[n+1][r] = (dp[n+1][r] + dp[n][r]) % MOD;
            dp[n+1][r+1] = (dp[n+1][r+1] + dp[n][r]) % MOD; 
        }
    }

    for(int i = 1; i <= K; i++){
        cout << (dp[K-1][i-1] * dp[N-K+1][i]) % MOD << endl; 
    }
}