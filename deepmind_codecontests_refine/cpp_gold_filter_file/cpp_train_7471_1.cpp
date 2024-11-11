#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int P = 1000000007;
int main() {
    int s;
    cin >> s;

    int dp[2001] = {};
    dp[0] = 1;

    for (int i = 3; i <= s; i++) {
        dp[i] = (dp[i - 1] + dp[i - 3]) % P;
    }

    cout << dp[s] << endl;

    return 0;
}
