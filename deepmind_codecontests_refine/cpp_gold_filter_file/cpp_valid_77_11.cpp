#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int N = 10000007;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const double pi = acos(-1.0);
inline int read() {
  int x;
  scanf("%d", &x);
  return x;
}
struct Node {
  int mn, key;
  bool operator<(const Node& b) const {
    if (mn == b.mn) return key < b.key;
    return mn < b.mn;
  }
};
int T, n, m;
int dp[2][N];
int ksm(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b <<= 1;
  }
  return res;
}
void solve() {
  n = read(), m = read();
  dp[0][1] = 1;
  long long pre = 0;
  for (int i = (1); i <= (n); ++i) {
    dp[1][i] = (0ll + dp[1][i] + dp[1][i - 1]) % m;
    if (i > 1) dp[0][i] = dp[1][i];
    dp[0][i] = (0ll + dp[0][i] + pre) % m;
    int l = 1, r = 2 * i;
    while (r <= n) {
      dp[1][r] = (0ll + dp[1][r] + dp[0][i]) % m;
      dp[1][r + l + 1] = (0ll + dp[1][r + l + 1] + m - dp[0][i]) % m;
      ++l;
      r += i;
    }
    pre = (0ll + dp[0][i] + pre) % m;
  }
  printf("%d\n", dp[0][n]);
}
signed main() { solve(); }
