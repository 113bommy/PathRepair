#include <bits/stdc++.h>
using namespace std;
pair<int, int> operator+(const pair<int, int> x, const int y) {
  return make_pair(x.first + y, x.second);
}
const int mxn = 131072, siz = 1, md = 998244353;
int n, k, pl[mxn], pr[mxn], d[mxn], f[mxn], bl[mxn], cnt[512][256], tag[512];
pair<int, int> a[mxn], b[mxn], c[mxn];
void mrg(pair<int, int> *x, int nx, pair<int, int> *y, int ny,
         pair<int, int> *z) {
  int px = 0, py = 0, pz = 0;
  for (; px < nx && py < ny;)
    if (x[px] < y[py])
      z[pz++] = x[px++];
    else
      z[pz++] = y[py++];
  for (; px < nx; z[pz++] = x[px++])
    ;
  for (; py < ny; z[pz++] = y[py++])
    ;
}
void reb(int pos, int l, int r) {
  int mn = n + 1;
  for (int i = l; i <= r; ++i) mn = min(mn, a[i].first);
  for (int i = l; i <= r; ++i) a[i].first -= mn;
  for (int i = 0; i <= siz; ++i) cnt[pos][i] = 0;
  for (int i = l; i <= r; ++i) (cnt[pos][a[i].first] += f[a[i].second]) %= md;
  for (int i = 1; i <= siz; ++i) (cnt[pos][i] += cnt[pos][i - 1]) %= md;
  tag[pos] += mn;
}
void add(int l, int r, int x) {
  int pb = 0, pc = 0;
  for (int i = (bl[l] - 1) * siz + 1; i <= min(bl[l] * siz, n); ++i)
    if (a[i].second < l || a[i].second > r)
      b[pb++] = a[i];
    else
      c[pc++] = a[i] + x;
  mrg(b, pb, c, pc, a + (bl[l] - 1) * siz + 1);
  reb(bl[l], (bl[l] - 1) * siz + 1, min(bl[l] * siz, n));
  if (bl[l] != bl[r]) {
    pb = 0, pc = 0;
    for (int i = (bl[r] - 1) * siz + 1; i <= min(bl[r] * siz, n); ++i)
      if (a[i].second < l || a[i].second > r)
        b[pb++] = a[i];
      else
        c[pc++] = a[i] + x;
    mrg(b, pb, c, pc, a + (bl[r] - 1) * siz + 1);
    reb(bl[r], (bl[r] - 1) * siz + 1, min(bl[r] * siz, n));
  }
  for (int i = bl[l] + 1; i <= bl[r] - 1; ++i) tag[i] += x;
}
void init() {
  for (int i = 1; i <= n; ++i) bl[i] = (i - 1) / siz + 1;
  for (int i = 1; i <= n; ++i) a[i] = make_pair(0, i);
  for (int i = 1; i <= bl[n]; ++i) reb(i, (i - 1) * siz + 1, min(i * siz, n));
}
int main() {
  scanf("%d%d", &n, &k), ++n, f[1] = 1;
  for (int i = 2; i <= n; ++i) scanf("%d", &d[i]);
  init();
  for (int i = 2; i <= n; ++i) {
    if (pr[d[i]]) add(pl[d[i]] + 1, pr[d[i]], -1);
    pl[d[i]] = pr[d[i]], pr[d[i]] = i - 1;
    add(pl[d[i]] + 1, pr[d[i]], 1);
    for (int j = 1; j <= bl[i]; ++j)
      if (k - tag[j] >= 0) (f[i] += cnt[j][min(k - tag[j], siz)]) %= md;
    reb(bl[i], (bl[i] - 1) * siz + 1, min(bl[i] * siz, n));
  }
  printf("%d\n", f[n]);
  return 0;
}
