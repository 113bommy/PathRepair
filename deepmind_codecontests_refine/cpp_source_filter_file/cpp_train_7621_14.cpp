#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;
const int mod = 998244353;
int n, m;
long long de;
int a[maxn], b[maxn], len[maxn << 1], lim[maxn << 1];
long long dp[maxn][maxn << 1], inv[maxn];
inline long long powmod(long long a, long long b) {
  long long res = 1;
  for (; b; b >>= 1) {
    if (b & 1) {
      res = res * a % mod;
    }
    a = a * a % mod;
  }
  return res;
}
inline void init() {
  cin >> n;
  vector<int> has;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    ++b[i];
    has.push_back(a[i]);
    has.push_back(b[i]);
  }
  de = 1;
  for (int i = 1; i <= n; ++i) {
    de *= powmod(b[i] - a[i], mod - 2);
    de %= mod;
  }
  sort(has.begin(), has.end());
  has.erase(unique(has.begin(), has.end()), has.end());
  for (int i = 1; i <= n; ++i) {
    a[i] = lower_bound(has.begin(), has.end(), a[i]) - has.begin() + 1;
    b[i] = lower_bound(has.begin(), has.end(), b[i]) - has.begin() + 1;
  }
  m = has.size();
  for (int i = 1; i <= m - 1; ++i) {
    len[i] = has[i] - has[i - 1];
  }
  inv[1] = 1;
  for (int i = 2; i <= n; ++i) {
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  for (int j = 0; j < m + 5; ++j) {
    dp[0][j] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = a[i]; j < b[i]; ++j) {
      long long C = 1;
      for (int k = 1; k <= i; ++k) {
        if (a[i - k + 1] > j || b[i - k + 1] < j) {
          break;
        }
        C = C * (len[j] + k - 1) % mod * inv[k] % mod;
        dp[i][j] += dp[i - k][j + 1] * C % mod;
        dp[i][j] %= mod;
      }
    }
    for (int j = m - 1; j >= 1; --j) {
      dp[i][j] += dp[i][j + 1];
      dp[i][j] %= mod;
    }
  }
  long long res = dp[n][1] * de % mod;
  cout << res << '\n';
  return 0;
}
