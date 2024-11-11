#include <bits/stdc++.h>
const int N = 2000005;
const long long INF = (long long)1e16;
using namespace std;
vector<long long> f[N];
int t[N][2], d[200], a[N], n, n1, mo, q;
long long sm[N];
template <class I>
void read(I &x) {
  x = 0;
  char ch = getchar();
  I v = 1;
  while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
  if (ch == '-') v = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x = x * v;
}
void build(int k, int l, int r) {
  if (l == r) {
    f[k].push_back(-INF), f[k].push_back(mo - a[l]);
    sm[k] = a[l];
    return;
  }
  int mid = (l + r) >> 1;
  t[k][0] = ++n1, build(t[k][0], l, mid);
  t[k][1] = ++n1, build(t[k][1], mid + 1, r);
  int x = t[k][0], y = t[k][1], rx = f[x].size(), ry = f[y].size();
  f[k].resize(rx + ry - 1, INF);
  for (int i = 0, j = 0; i < rx; ++i) {
    long long xl = f[x][i], xr = (i + 1 != rx) ? f[x][i + 1] - 1 : INF,
              yl = xl + sm[x] - (long long)i * mo,
              yr = xr + sm[x] - (long long)i * mo;
    while (j > 0 && f[y][j] > yl) j--;
    while (j < ry && f[y][j] <= yl) j++;
    if (j) j--;
    while (j < ry && f[y][j] <= yr)
      f[k][i + j] =
          min(f[k][i + j], max(xl, f[y][j] - sm[x] + (long long)i * mo)),
               j++;
  }
  f[k][0] = -INF;
  sm[k] = sm[t[k][0]] + sm[t[k][1]];
}
void find(int k, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    d[++d[0]] = k;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid) find(t[k][0], l, mid, x, y);
  if (y > mid) find(t[k][1], mid + 1, r, x, y);
}
long long query(int x, int y) {
  d[0] = 0;
  find(1, 1, n, x, y);
  long long c = 0;
  for (int i = 1; i <= d[0]; ++i)
    c += sm[d[i]] -
         (long long)mo * (upper_bound(f[d[i]].begin(), f[d[i]].end(), c) -
                          f[d[i]].begin() - 1);
  return c;
}
int main() {
  cin >> n >> q >> mo;
  for (int i = 1; i <= n; ++i) read(a[i]);
  n1 = 1;
  build(1, 1, n);
  for (int i = 1; i <= q; ++i) {
    int x, y;
    read(x), read(y);
    printf("%I64d\n", query(x, y));
  }
}
