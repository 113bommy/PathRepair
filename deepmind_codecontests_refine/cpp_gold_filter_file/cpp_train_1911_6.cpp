#include <bits/stdc++.h>
using namespace std;
inline int IN() {
  char c;
  register int first = 0;
  for (; (c = getchar()) < 48 && c ^ '-' || c > 57;)
    ;
  bool f = c == '-';
  if (f) (c = getchar());
  for (; c > 47 && c < 58; (c = getchar()))
    first = (first << 3) + (first << 1) + c - 48;
  if (f) first = -first;
  return first;
}
inline void hello() {
  freopen("ha.in", "r", stdin);
  freopen("ha.out", "w", stdout);
}
long long ans;
int n, N, a[500010], lg[500010], h[500010], f[19][500010], mi[19][500010];
inline int rmq(int l, int r) {
  int _ = lg[r - l + 1];
  return h[mi[_][l]] < h[mi[_][r - (1 << _) + 1]] ? mi[_][l]
                                                  : mi[_][r - (1 << _) + 1];
}
int main() {
  n = IN();
  N = n << 1;
  for (int _r = N, i = 2; i <= _r; ++i) lg[i] = lg[i >> 1] + 1;
  for (int _r = n, i = 1; i <= _r; ++i) {
    int first = IN();
    h[i] = max(1, i - first);
    h[i + n] = max(1, i + n - first);
    a[i + n] = min(i + n - 1, first);
    a[i] = min(i - 1, first);
  }
  for (int _r = N, i = 1; i <= _r; ++i) mi[0][i] = i;
  for (int _r = lg[N], i = 0; i < _r; ++i)
    for (register int _ = 1 << i, j = N + 1 - _ * 2; j; --j)
      mi[i + 1][j] = h[mi[i][j]] < h[mi[i][j + _]] ? mi[i][j] : mi[i][j + _];
  for (int _r = N, i = 1; i <= _r; ++i) f[0][i] = rmq(h[i], i);
  for (int _r = lg[N], i = 0; i < _r; ++i)
    for (int _ = 1 << i, j = N; j; --j) f[i + 1][j] = f[i][f[i][j]];
  for (int _r = n, i = 1; i <= _r; ++i) {
    int j = i + n - 1;
    if (j - a[j] <= i)
      ++ans;
    else {
      for (int _l = 0, k = lg[N]; k >= _l; --k)
        if (f[k][j] - a[f[k][j]] > i) ans += 1 << k, j = f[k][j];
      ans += 2;
    }
  }
  printf("%I64d\n", ans);
}
