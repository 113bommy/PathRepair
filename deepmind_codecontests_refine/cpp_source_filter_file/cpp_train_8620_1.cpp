#include <bits/stdc++.h>

using namespace std;

int N;
int arr[22][22];
long long pre[1<<22];
long long dp[1<<22];
long long MOD = 1000000007;

int main(){
    cin >> N;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    dp[0] = 1;
    for(int i = 1; i<1<<N; i++){
        int j = __builtin_popcount-1;
        for(int k = 0; k<N; k++){
            if(arr[j][k] && ((1<<k)&i)){
                dp[i] += dp[i^(1<<k)];
            }
        }
        dp[i] %= MOD;
    }
    cout << dp[(1<<N)-1] << endl;
}
