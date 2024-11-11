#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int B_MAX = (int)1e5 + 1;
ll dp[B_MAX];
ll cumsum[B_MAX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t, k;
  cin >> t >> k;
  cumsum[0] = 0;
  dp[0] = 1;
  for (int i = 1; i < B_MAX; ++i) {
    dp[i] = (i < k ? 1 : dp[i - 1] + dp[i - k]) % MOD;
    cumsum[i] = cumsum[i - 1] + dp[i];
  }
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << (cumsum[b] - cumsum[a - 1]) % MOD << endl;
  }
  return 0;
}
