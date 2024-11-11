#include <bits/stdc++.h>
long long min(long long a, long long b) { return a < b ? a : b; }
int *oh[500][500], *ot[500][500], *ox[500][500], oo[500][500];
void link(int i, int j, int h, int t, int x) {
  int o = oo[i][j]++;
  if (o >= 2 && (o & o - 1) == 0) {
    oh[i][j] = (int *)realloc(oh[i][j], o * 2 * sizeof *oh[i][j]);
    ot[i][j] = (int *)realloc(ot[i][j], o * 2 * sizeof *ot[i][j]);
    ox[i][j] = (int *)realloc(ox[i][j], o * 2 * sizeof *ox[i][j]);
  }
  oh[i][j][o] = h, ot[i][j][o] = t, ox[i][j][o] = x;
}
long long *st_, *lz_;
int h_, n_;
void put(int i, long long x) {
  st_[i] += x;
  if (i < n_) lz_[i] += x;
}
void pus(int i) {
  if (lz_[i]) {
    put(i << 1, lz_[i]), put(i << 1 | 1, lz_[i]);
    lz_[i] = 0;
  }
}
void pul(int i) {
  if (!lz_[i]) st_[i] = min(st_[i << 1], st_[i << 1 | 1]);
}
void push(int i) {
  int h;
  for (h = h_; h > 0; h--) pus(i >> h);
}
void pull(int i) {
  while (i > 1) pul(i >>= 1);
}
void update(int l, int r, long long x) {
  int l_ = l += n_, r_ = r += n_;
  push(l_), push(r_);
  for (; l <= r; l >>= 1, r >>= 1) {
    if ((l & 1) == 1) put(l++, x);
    if ((r & 1) == 0) put(r--, x);
  }
  pull(l_), pull(r_);
}
void update1(int i, long long x) {
  push(i += n_);
  st_[i] = x;
  pull(i);
}
long long query(int l, int r) {
  long long x;
  push(l += n_), push(r += n_);
  x = 0x3f3f3f3f3f3f3f3fLL;
  for (; l <= r; l >>= 1, r >>= 1) {
    if ((l & 1) == 1) x = min(x, st_[l++]);
    if ((r & 1) == 0) x = min(x, st_[r--]);
  }
  return x;
}
int main() {
  static long long xx[500][500], st[500][(1 << 9) * 2], lz[500][(1 << 9) * 2],
      sti[(1 << 9) * 2], lzi[(1 << 9) * 2];
  int n, m, k, i, j;
  scanf("%d%d%d", &n, &m, &k);
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) {
      oh[i][j] = (int *)malloc(2 * sizeof *oh[i][j]);
      ot[i][j] = (int *)malloc(2 * sizeof *ot[i][j]);
      ox[i][j] = (int *)malloc(2 * sizeof *ox[i][j]);
    }
  while (k--) {
    int d, t, x;
    int meet1, meet2, meet3, meet4;
    scanf("%d%d%d%d%d", &i, &j, &d, &t, &x);
    meet1 = meet2 = meet3 = meet4 = 0;
    if (i + j >= t && (i + j) % 4 == t % 4) xx[i][j] += x, meet1 = 1;
    if (i + j >= t && (i + j) % 4 == (t + 1) % 4)
      xx[i + d][j - d] += x, meet2 = 1;
    if (i + j + d >= t && (i + j + d) % 4 == (t + 2) % 4)
      xx[i + d][j] += x, meet3 = 1;
    if (i + j + d >= t && (i + j + d) % 4 == (t + 2) % 4)
      xx[i][j + d] += x, meet4 = 1;
    if (meet1 && meet3) link(i + d, j, i, 0, x);
    if (meet1 && meet4) link(i, j + d, j, 1, x);
    if (meet2 && meet3) link(i + d, j, j - d, 1, x);
  }
  h_ = 0;
  while (1 << h_ < n || 1 << h_ < m) h_++;
  n_ = 1 << h_;
  for (i = 0; i < n; i++) {
    memset(sti, 0, n_ * 2 * sizeof *sti);
    memset(lzi, 0, n_ * 2 * sizeof *lzi);
    for (j = 0; j < m; j++) {
      int o;
      long long x;
      for (o = 0; o < oo[i][j]; o++) {
        int h = oh[i][j][o], t = ot[i][j][o], x = ox[i][j][o];
        if (t == 0)
          st_ = st[j], lz_ = lz[j], update(0, h, -x);
        else
          st_ = sti, lz_ = lzi, update(0, h, -x);
      }
      if (i == 0 && j == 0)
        x = 0;
      else {
        x = 0x3f3f3f3f3f3f3f3fLL;
        if (i > 0) st_ = st[j], lz_ = lz[j], x = min(x, query(0, i - 1));
        if (j > 0) st_ = sti, lz_ = lzi, x = min(x, query(0, j - 1));
      }
      st_ = st[j], lz_ = lz[j], update1(i, x), update(0, i, xx[i][j]);
      st_ = sti, lz_ = lzi, update1(j, x), update(0, j, xx[i][j]);
    }
  }
  st_ = st[m - 1], lz_ = lz[m - 1];
  printf("%lld\n", query(n - 1, n - 1));
  return 0;
}
