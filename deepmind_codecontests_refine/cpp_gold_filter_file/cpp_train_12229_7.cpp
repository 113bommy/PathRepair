#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T sqr(T x) {
  return x * x;
}
const double EPS = 1e-6;
const int INF = 0x3fffffff;
const long long LINF = INF * 1ll * INF;
const double PI = acos(-1.0);
using namespace std;
char g[505][505];
int cnt[505];
int dp[505][505];
int C[505][505];
int mod;
void Add(int &ans, int v) {
  ans += v;
  if (ans >= mod) ans -= mod;
}
int main(void) {
  int n, m;
  scanf("%d %d %d", &n, &m, &mod);
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
  }
  for (int i = 0; i < (m); ++i) {
    scanf("%s", g[i]);
    for (int j = 0; j < (n); ++j) cnt[j] += g[i][j] - '0';
  }
  int cnt0 = 0, cnt1 = 0;
  for (int i = 0; i < (n); ++i) {
    if (cnt[i] > 2) {
      puts("0");
      return 0;
    }
    if (cnt[i] == 1)
      cnt1++;
    else if (cnt[i] == 0)
      cnt0++;
  }
  dp[cnt0][cnt1] = 1;
  for (int j = cnt0; j >= 0; j--) {
    for (int k = n; k >= 0; k--) {
      if (j >= 2) Add(dp[j - 2][k + 2], 1ll * C[j][2] * dp[j][k] % mod);
      if (k >= 2) Add(dp[j][k - 2], 1ll * C[k][2] * dp[j][k] % mod);
      if (j && k)
        Add(dp[j - 1][k], 1ll * C[k][1] * C[j][1] % mod * dp[j][k] % mod);
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}
