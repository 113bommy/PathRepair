#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
map<int, int> M;
int m = 0, b[1200], n, k, a[100010], cnt[1200] = {0}, f[1200][1200] = {0};
int F[100010], number = 0;
void TRY(int x) {
  m++;
  b[m] = x;
  if (1ll * x * 10 + 4 < 1000000001) TRY(x * 10 + 4);
  if (1ll * x * 10 + 7 < 1000000001) TRY(x * 10 + 7);
}
int POW(int x, int y) {
  int res = 1;
  for (; y; y >>= 1) {
    if (y & 1) res = 1LL * res * x % mod;
    x = 1LL * x * x % mod;
  }
  return res;
}
int C(int x, int y) {
  if (x > y) return 0;
  if (x == 0) return 1;
  int res = F[y];
  res = 1LL * res * POW(F[x], mod - 2) % mod;
  res = 1LL * res * POW(F[y - x], mod - 2) % mod;
  return res;
}
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  TRY(4);
  TRY(7);
  sort(b + 1, b + 1 + m);
  for (int i = 1; i <= m; ++i) M[b[i]] = i;
  for (int i = 1; i <= n; ++i)
    if (M.count(a[i]) > 0)
      cnt[M[a[i]]]++;
    else
      number++;
  for (int i = 0; i <= m; ++i) f[i][0] = 1;
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= k; ++j)
      f[i][j] = (f[i - 1][j] + 1LL * f[i - 1][j - 1] * cnt[i]) % mod;
  F[0] = 1;
  for (int i = 1; i <= 100000; ++i) F[i] = (1LL * F[i - 1] * i) % mod;
  int ans = 0;
  for (int j = 0; j <= k; ++j) add(ans, 1LL * C(j, number) * f[m][k - j] % mod);
  printf("%d", ans);
  return 0;
}
