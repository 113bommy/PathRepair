#include <bits/stdc++.h>
using namespace std;
const int maxn = (1 << 9) + 5;
inline long long gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  long long sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
int m, n, x[maxn], y[maxn];
long long a[maxn][maxn], b[maxn][maxn];
int main() {
  m = gi();
  for (int i = 0; i < (1 << m); ++i)
    for (int j = 0; j < (1 << m); ++j) a[i][j] = gi();
  n = gi();
  for (int i = 0; i < n; ++i) x[i] = gi(), y[i] = gi();
  int S = (1 << m) - 1, ans = 0;
  for (int t = 0; t < n; ++t) {
    memset(b, 0, sizeof(b));
    for (int k = 0; k < n; ++k)
      for (int i = 0; i < (1 << m); ++i)
        for (int j = 0; j < (1 << m); ++j)
          b[(i + x[k]) & S][(j + y[k]) & S] ^= a[i][j];
    memcpy(a, b, sizeof(b));
    for (int k = 0; k < n; ++k) x[k] = (x[k] << 1) & S, y[k] = (y[k] << 1) & S;
  }
  for (int i = 0; i < (1 << m); ++i)
    for (int j = 0; j < (1 << m); ++j) ans += a[i][j] != 0;
  printf("%d\n", ans);
  return 0;
}
