#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream& operator>>(istream& is, vector<T>& v) {
  for (auto& i : v) is >> i;
  return is;
}
template <typename T>
ostream& operator<<(ostream& os, vector<T> v) {
  for (auto& i : v) os << i << '\n';
  return os;
}
uint64_t modpow(uint64_t base, uint64_t exp, uint64_t modulus) {
  base %= modulus;
  uint64_t result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
void solve() {
  int64_t n, m;
  cin >> n >> m;
  vector<int64_t> a(n);
  cin >> a;
  vector<int64_t> b(n);
  cin >> b;
  int64_t missing = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) missing++;
    if (b[i] == 0) missing++;
  }
  int64_t nom = 0;
  vector<vector<int64_t>> dp(n + 1, vector<int64_t>(2, 0));
  dp[0][0] = 1;
  dp[0][1] = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0 && b[i] > 0) {
      if (a[i] > b[i]) {
        dp[i + 1][1] = dp[i][1] + dp[i][0];
        if (dp[i + 1][1] > 1000000007LL) dp[i + 1][1] -= 1000000007LL;
      } else if (a[i] == b[i]) {
        dp[i + 1][0] = dp[i][0];
        dp[i + 1][1] = dp[i][1];
      } else {
        dp[i + 1][1] = dp[i][1];
      }
    }
    if (a[i] > 0 && b[i] == 0) {
      dp[i + 1][1] = m * dp[i][1] + (a[i] - 1) * dp[i][0];
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] %= 1000000007LL;
    }
    if (a[i] == 0 && b[i] > 0) {
      dp[i + 1][1] = m * dp[i][1] + (m - b[i]) * dp[i][0];
      dp[i + 1][0] = dp[i][0];
      dp[i + 1][1] %= 1000000007LL;
    }
    if (a[i] == 0 && b[i] == 0) {
      int64_t ap = ((m - 1) * m / 2) % 1000000007LL;
      int64_t m2 = (m * m) % 1000000007LL;
      dp[i + 1][1] = m2 * dp[i][1] + ap * dp[i][0];
      dp[i + 1][0] = m * dp[i][0];
      dp[i + 1][0] %= 1000000007LL;
      dp[i + 1][1] %= 1000000007LL;
    }
  }
  nom = dp[n][1];
  int64_t den = modpow(m, missing, 1000000007LL);
  int64_t invden = modpow(den, 1000000007LL - 2, 1000000007LL);
  int64_t res = nom * invden;
  res %= 1000000007LL;
  cout << res << endl;
};
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
};
