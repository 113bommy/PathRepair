#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N, A;
    cin >> N >> A;
    vector<int> x(N);
    rep(i, 0, N) cin >> x[i], x[i] -= A;
    vector<vector<long long>> dp(N + 1, vector<long long>(5555));
    int g = 2500;
    dp[0][g] = 1;
    rep(i, 0, N) rep(j, -g, g) {
        dp[i + 1][j + g] += dp[i][j + g];
        dp[i + 1][j + g + x[i]] += dp[i][j + g];
    }
    cout << dp[N][g] - 1 << endl;
    return 0;
}
