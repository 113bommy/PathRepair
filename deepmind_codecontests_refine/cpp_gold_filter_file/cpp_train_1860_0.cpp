#include <bits/stdc++.h>
using namespace std;

int n, m;
int memo[310][310][310];
const int MOD = 1000000007;

long long dp(int i, int ma, int all){
    if(i == m) return ma == n ? 1 : 0;
    if(memo[i][ma][all] != -1) return memo[i][ma][all];

    return memo[i][ma][all] = (dp(i+1, all, all)*ma%MOD + dp(i+1, ma, all)*(all-ma)%MOD + dp(i+1, ma, all+1)*(n-all)%MOD) % MOD;
}

signed main(){
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 1, 1) << endl;
    return 0;
}