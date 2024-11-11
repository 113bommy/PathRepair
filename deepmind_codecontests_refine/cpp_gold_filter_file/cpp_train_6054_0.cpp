#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
const long long inf = 0x3f3f3f3f;
const long long mod = 1000000007;
template <typename T>
inline void read(T &x) {
  int f = 1;
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  x *= f;
  return;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x);
  read(args...);
}
int n, m;
long long dp[N][N];
int main() {
  ios::sync_with_stdio(0);
  int i, j;
  cin >> n;
  n *= 2;
  dp[0][0] = 1;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] %= mod;
    }
    for (j = n - 1; j >= 0; j--) {
      dp[i][j] += dp[i - 1][j + 1];
      dp[i][j] %= mod;
    }
  }
  long long ans = 0;
  for (i = 1; i <= n; i++) {
    if (!(i & 1)) continue;
    for (j = 0; j <= n; j++) {
      if (j > (n - i)) break;
      ans += dp[i][j];
      ans %= mod;
    }
  }
  cout << ans;
  return 0;
}
