#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int f[N][20], n, t, c, ans;
inline void fr(int &num) {
  num = 0;
  char c = getchar();
  int p = 1;
  while (c < '0' || c > '9') c == '-' ? p = -1, c = getchar() : c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - '0', c = getchar();
  num *= p;
}
inline int Max(register int p, register int q) { return p > q ? p : q; }
int main() {
  fr(n), fr(c), fr(t);
  for (register int i = 1; i <= n; ++i) fr(f[i][0]);
  for (register int j = 1; (1 << j - 1) <= n; ++j)
    for (register int i = 1; i + (1 << j) - 1 <= n; ++i)
      f[i][j] = Max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
  int k = log2(t);
  for (register int i = 1; i + t - 1 <= n; ++i)
    ans += (Max(f[i][k], f[i + t - (1 << k)][k]) <= c ? 1 : 0);
  printf("%d", ans);
  return 0;
}
