#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int N = 0, C = 0;
  char tf = getchar();
  for (; !isdigit(tf); tf = getchar()) C |= tf == '-';
  for (; isdigit(tf); tf = getchar()) N = (N << 1) + (N << 3) + (tf ^ 48);
  return C ? -N : N;
}
const int N = 500010;
int n, m, d[N], t[N << 2], x, y, ans;
struct nc {
  int a, b, c;
} hp[N];
inline bool cmp(nc x, nc y) { return x.b > y.b; }
inline void U(int l, int r, int p) {
  if (l == r) {
    t[p] = max(t[p], y);
    return;
  }
  int m = l + r >> 1;
  x <= m ? U(l, m, p << 1) : U(m + 1, r, p << 1 | 1);
  t[p] = max(t[p << 1], t[p << 1 | 1]);
}
inline int A(int l, int r, int p) {
  if (l <= x && y <= r) return t[p];
  int m = l + r >> 1, as = 0;
  if (x <= m) as = max(as, A(l, m, p << 1));
  if (y > m) as = max(as, A(m + 1, r, p << 1 | 1));
  return as;
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) d[i] = hp[i].a = read();
  for (int i = 1; i <= n; ++i) hp[i].b = read();
  for (int i = 1; i <= n; ++i) hp[i].c = read();
  sort(d + 1, d + n + 1);
  m = unique(d + 1, d + n + 1) - (d + 1);
  for (int i = 1; i <= n; ++i)
    hp[i].a = lower_bound(d + 1, d + m + 1, hp[i].a) - d;
  sort(hp + 1, hp + n + 1, cmp);
  int i, j;
  for (i = 1; i <= n; i = j) {
    for (j = i; j <= n && hp[j].b == hp[i].b; ++j) {
      x = hp[j].a + 1, y = m;
      if (A(1, m, 1) > hp[j].c) ++ans;
    }
    for (; i < j; ++i) {
      x = hp[i].a, y = hp[i].c;
      U(1, n, 1);
    }
  }
  printf("%d\n", ans);
  return 0;
}
