#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  char ch = getchar();
  x = 0;
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - 48, ch = getchar();
}
const int N = 2030, mod = 998244353;
int n, k, res, f[N], dp[N][N];
void work1() {
  f[0] = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = i; j <= n; ++j) ((f[j] += f[j - i]) >= mod && (f[j] -= mod));
  for (int i = 1; i <= n; ++i) ((res += f[i]) >= mod && (res -= mod));
}
void work2() {
  dp[0][0] = 1;
  for (int i = n; i >= 1; --i)
    for (int j = 1; j * i <= n; ++j)
      for (int k = i * j; k <= n; ++k)
        ((dp[j][k] += dp[j - 1][k - i * j]) >= mod && (dp[j][k] -= mod));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j) ((res += dp[i][j]) >= mod && (res -= mod));
}
int a[N], b[N], c[N], m, tp;
int check() {
  int m = 0, s = 0;
  for (int i = 1; i <= tp; ++i) b[++m] = a[i];
  for (int t = 1; t < k; ++t) {
    s = 0;
    int mm = 0;
    for (int i = 1; i <= m; ++i) s += b[i];
    if (s > n) return 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= b[m - i + 1]; ++j) c[++mm] = i;
    for (int i = 1; i <= mm; ++i) b[i] = c[i];
    m = mm;
  }
  s = 0;
  for (int i = 1; i <= m; ++i) s += b[i];
  if (s > n)
    return 0;
  else
    return ++res, 1;
}
int work3(int now, int s) {
  if (s && !check()) return 0;
  for (int i = now; i + s <= n; ++i) {
    a[++tp] = i;
    if (!work3(i, s + i)) return --tp, 1;
    --tp;
  }
  return 1;
}
signed main() {
  read(n), read(k);
  if (k == 1)
    work1();
  else if (k == 2)
    work2();
  else
    work3(1, 0);
  return printf("%d\n", res), 0;
}
