#include <bits/stdc++.h>
using namespace std;
long long read() {
  char ch = getchar();
  long long x = 0, pd = 0;
  while (ch < '0' || ch > '9') pd |= ch == '-', ch = getchar();
  while ('0' <= ch && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return pd ? -x : x;
}
const int maxn = 200005;
const long long inf = 1ll << 60;
int n, N, L, R;
struct Node {
  int id, l, r;
} stk[maxn];
long long S;
struct Fac {
  int c, v;
} a[maxn];
bool bad[maxn];
bool cmp(Fac x, Fac y) { return x.v < y.v; }
long long f[maxn], g[maxn], ans;
bool check(int x, int y, int z) {
  long long xf, xg, yf, yg, t;
  if (g[x] >= a[z].c)
    xf = f[x], xg = g[x] - a[z].c;
  else {
    t = (a[z].c - g[x]) / a[x].v + ((a[z].c - g[x]) % a[x].v != 0);
    xf = f[x] + t, xg = g[x] + t * a[x].v - a[z].c;
  }
  if (g[y] >= a[z].c)
    yf = f[y], yg = g[y] - a[z].c;
  else {
    t = (a[z].c - g[y]) / a[y].v + ((a[z].c - g[y]) % a[y].v != 0);
    yf = f[y] + t, yg = g[y] + t * a[y].v - a[z].c;
  }
  return xf < yf || (xf == yf && xg >= yg);
}
int main() {
  n = read(), S = read();
  for (int i = 1; i <= n; i++) a[i].v = read(), a[i].c = read();
  sort(a + 1, a + n + 1, cmp);
  long long minn = inf;
  for (int i = n; i >= 1; i--)
    if (minn <= a[i].c)
      bad[i] = 1;
    else
      minn = a[i].c;
  for (int i = 1; i <= n; i++)
    if (a[i].c)
      bad[i] = 1;
    else
      break;
  for (int i = 1; i <= n; i++)
    if (!bad[i]) a[++N] = a[i];
  L = R = 1, ans = S / a[1].v + (S % a[1].v != 0);
  stk[1] = (Node){1, 2, N};
  for (int i = 2; i <= N; i++) {
    int x = stk[L].id, y;
    if (g[x] >= a[i].c)
      f[i] = f[x], g[i] = g[x] - a[i].c;
    else {
      y = (a[i].c - g[x]) / a[x].v + ((a[i].c - g[x]) % a[x].v != 0);
      f[i] = f[x] + y, g[i] = g[x] + y * a[x].v - a[i].c;
    }
    ans = min(ans, f[i] + (S - g[i]) / a[i].v + ((S - g[i]) % a[i].v != 0));
    ++stk[L].l;
    if (stk[L].l > stk[L].r) ++L;
    if (L <= R && check(stk[R].id, i, stk[R].r)) continue;
    while (L <= R && check(i, stk[R].id, stk[R].l)) --R;
    if (L > R || check(stk[R].id, i, stk[R].r)) {
      stk[R + 1] = (Node){i, L > R ? i + 1 : stk[R].r + 1, n}, ++R;
      continue;
    }
    int _l = stk[R].l - 1, _r = stk[R].r + 1;
    while (_l + 1 < _r) {
      int mid = _l + _r >> 1;
      if (check(i, stk[R].id, mid))
        _r = mid;
      else
        _l = mid;
    }
    stk[R].r = _r - 1, ++R;
    stk[R] = (Node){i, _r, N};
    while (stk[L].l > stk[L].r) ++L;
  }
  printf("%lld\n", ans);
  return 0;
}
