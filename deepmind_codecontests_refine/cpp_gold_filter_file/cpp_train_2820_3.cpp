#include <bits/stdc++.h>
using namespace std;
struct data {
  long long u, v, w;
  data(long long u = 0, long long v = 0, long long w = 0) : u(u), v(v), w(w) {}
  bool operator<(data a) { return w < a.w; }
};
const long long M = 3e5 + 7;
const long long MOD = 998244353;
const long long MAX = 1e9 + 7;
long long C[1010][1010];
int n;
long long dp[1010], a[1010];
void solve() {
  C[0][0] = 1;
  for (int i = (1); i <= (1005); i++) {
    C[i][0] = 1;
    for (int j = (1); j <= (i); j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
  }
  cin >> n;
  for (int i = (1); i <= (n); i++) cin >> a[i];
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (i - 1); j++) {
      if (i - j >= a[j] && a[j] > 0) {
        dp[i] += (dp[j - 1] + 1) * C[i - j][a[j]] % MOD;
        dp[i] %= MOD;
      }
    }
  }
  cout << dp[n];
}
int main() {
  ios::sync_with_stdio(0);
  solve();
  return 0;
}
