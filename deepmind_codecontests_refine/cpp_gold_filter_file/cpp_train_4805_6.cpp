#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() { return getchar(); }
inline int read() {
  int x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, q, a[MAXN];
char s[MAXN];
int sum[MAXN << 2], lMax[MAXN << 2], lMin[MAXN << 2], rMax[MAXN << 2],
    rMin[MAXN << 2], lv[MAXN << 2], rv[MAXN << 2], val[MAXN << 2],
    ans[MAXN << 2];
inline void pushup(int x) {
  sum[x] = sum[x << 1] + sum[x << 1 | 1];
  lMax[x] = max(lMax[x << 1], lMax[x << 1 | 1] + sum[x << 1]),
  lMin[x] = min(lMin[x << 1], lMin[x << 1 | 1] + sum[x << 1]);
  rMax[x] = max(rMax[x << 1 | 1], rMax[x << 1] + sum[x << 1 | 1]),
  rMin[x] = min(rMin[x << 1 | 1], rMin[x << 1] + sum[x << 1 | 1]);
  lv[x] = max(max(lv[x << 1], lv[x << 1 | 1] - sum[x << 1]),
              val[x << 1] + lMax[x << 1 | 1]);
  rv[x] = max(max(rv[x << 1 | 1], rv[x << 1] + sum[x << 1 | 1]),
              val[x << 1 | 1] - rMin[x << 1]);
  val[x] = max(val[x << 1] + sum[x << 1 | 1], val[x << 1 | 1] - sum[x << 1]);
  ans[x] =
      max(max(ans[x << 1], ans[x << 1 | 1]),
          max(rv[x << 1] + lMax[x << 1 | 1], lv[x << 1 | 1] - rMin[x << 1]));
}
inline void Build(int x, int l, int r) {
  if (l == r) {
    sum[x] = a[l], lMax[x] = rMax[x] = max(a[l], 0),
    lMin[x] = rMin[x] = min(a[l], 0), ans[x] = rv[x] = lv[x] = val[x] = 1;
    return;
  }
  int mid = l + r >> 1;
  Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r), pushup(x);
}
inline void Mdy(int x, int l, int r, int p, int v) {
  if (l == r) {
    sum[x] = v, lMax[x] = rMax[x] = max(v, 0), lMin[x] = rMin[x] = min(v, 0),
    ans[x] = rv[x] = lv[x] = val[x] = 1;
    return;
  }
  int mid = l + r >> 1;
  p <= mid ? Mdy(x << 1, l, mid, p, v) : Mdy(x << 1 | 1, mid + 1, r, p, v);
  pushup(x);
}
int main() {
  n = (read() - 1) << 1, q = read(), scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) a[i] = s[i] == '(' ? 1 : -1;
  Build(1, 1, n), cout << ans[1] << '\n';
  for (int x, y; q--;) {
    x = read(), y = read(), a[x] != a[y]       ? Mdy(1, 1, n, x, a[y]),
    Mdy(1, 1, n, y, a[x]), swap(a[x], a[y]), 0 : 0, cout << ans[1] << "\n";
  }
  return 0;
}
