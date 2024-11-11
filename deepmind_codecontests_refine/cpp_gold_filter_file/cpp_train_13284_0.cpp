#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 88;
const int inf = 1e9 + 88;
const int logn = 22;
const int maxa = 3e6 + 88;
const long long infll = 1e18 + 88;
const char sgl[5] = {'a', 'e', 'i', 'o', 'u'};
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const char sep = 'a' - 1;
const double eps = 1e-9;
int readint() {
  long long cur;
  scanf("%I64d", &cur);
  return cur;
}
int sum(int a, int b) { return (1ll * a + 1ll * b + mod) % mod; }
int umn(int a, int b) { return (1ll * a * b) % mod; }
int g[maxn], a[maxn];
bool used[maxn];
int timer;
int dp[388][388];
int f[maxn], c[388][388];
bool sq(int a, int b) {
  long long s = 1ll * a * b;
  long long l = 0, r = maxn;
  while (l < r) {
    long long mid = (l + r + 1) / 2;
    if (mid * mid > s)
      r = mid - 1;
    else
      l = mid;
  }
  return l * l == s;
}
void solve() {
  int n, i, j, k, q;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  f[0] = 1;
  for (i = 1; i < 388; i++) f[i] = umn(f[i - 1], i);
  for (i = 0; i < 388; i++) c[0][i] = 1;
  for (i = 1; i < 388; i++)
    for (j = 1; j <= i; j++) c[j][i] = sum(c[j][i - 1], c[j - 1][i - 1]);
  for (i = 0; i < n; i++)
    if (!used[i]) {
      used[i] = true;
      g[timer] = 1;
      for (j = i + 1; j < n; j++)
        if (sq(a[i], a[j])) g[timer]++, used[j] = true;
      timer++;
    }
  dp[0][0] = 1;
  int all = 1;
  for (i = 0; i < timer; i++) {
    for (j = 0; j <= all; j++)
      if (dp[i][j] != 0) {
        for (k = 1; k <= min(g[i], all); k++)
          for (q = 0; q <= min(k, j); q++)
            dp[i + 1][j - q + g[i] - k] =
                sum(dp[i + 1][j - q + g[i] - k],
                    umn(f[g[i]],
                        umn(c[q][j], umn(c[k - 1][g[i] - 1],
                                         umn(dp[i][j], c[k - q][all - j])))));
      }
    all += g[i];
  }
  cout << dp[timer][0];
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
