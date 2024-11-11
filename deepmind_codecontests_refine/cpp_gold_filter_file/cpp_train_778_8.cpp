#include <bits/stdc++.h>
using namespace std;
const int N = 1.6e6 + 5;
int n, m;
struct edge {
  int x, y, z, t;
} b[N];
vector<int> e[N];
int fi[N], nt[N], to[N], tot = 1;
void link(int x, int y) { nt[++tot] = fi[x], to[tot] = y, fi[x] = tot; }
int td, pr[N], sf[N];
int cmpe(int x, int y) { return b[x].z < b[y].z; }
void build_graph() {
  td = m * 2;
  for (int i = 1, B = n; i <= B; i++) {
    for (int j = e[i].size() - 1, B = 0; j >= B; j--) {
      int x = e[i][j];
      sf[j] = ++td;
      if (j < e[i].size() - 1) link(sf[j], sf[j + 1]);
      link(sf[j], 2 * x);
    }
    for (int j = 0, B = e[i].size(); j < B; j++) {
      int x = e[i][j];
      pr[j] = ++td;
      if (j > 0) link(pr[j], pr[j - 1]);
      link(pr[j], 2 * x);
      if (j > 0) link(2 * x - 1, pr[j - 1]);
      if (j < e[i].size() - 1) link(2 * x - 1, sf[j + 1]);
    }
    sort(e[i].begin(), e[i].end(), cmpe);
    for (int j = 1, B = e[i].size(); j < B; j++) {
      int x = e[i][j], y = e[i][j - 1];
      if (j > 1 && b[x].z == b[y].z && b[x].z == b[e[i][j - 2]].z) {
        printf("No\n");
        exit(0);
      }
      if (b[x].z == b[y].z) {
        link(2 * x, 2 * y - 1);
        link(2 * y, 2 * x - 1);
      }
    }
  }
}
int ntot, nfi[N], ntd;
void save() {
  for (int i = 1, B = td; i <= B; i++) nfi[i] = fi[i];
  ntot = tot;
}
void cancel() {
  for (int i = 1, B = td; i <= B; i++) fi[i] = nfi[i];
  tot = ntot;
}
int dfn[N], low[N], dfn0;
int z[N], z0, bz[N], bl[N], bl0;
void dg(int x) {
  dfn[x] = low[x] = ++dfn0;
  bz[x] = 1;
  z[++z0] = x;
  for (int i = fi[x]; i; i = nt[i]) {
    int y = to[i];
    if (!dfn[y])
      dg(y), low[x] = min(low[x], low[y]);
    else if (bz[y])
      low[x] = min(low[x], dfn[y]);
  }
  if (low[x] >= dfn[x]) {
    ++bl0;
    do bz[z[z0]] = 0, bl[z[z0]] = bl0;
    while (z[z0--] != x);
  }
}
int pd(int mi) {
  for (int i = 1, B = m; i <= B; i++)
    if (b[i].t > mi) {
      link(2 * i - 1, 2 * i);
    }
  for (int i = 1, B = td; i <= B; i++) dfn[i] = low[i] = 0;
  dfn0 = bl0 = 0;
  for (int i = 1, B = td; i <= B; i++)
    if (!dfn[i]) dg(i);
  int ky = 1;
  for (int i = 1, B = m; i <= B; i++)
    if (bl[2 * i] == bl[2 * i - 1]) ky = 0;
  cancel();
  return ky;
}
vector<int> w[N];
int cr[N], r[N], dl[N], d[N], d0;
void turpo() {
  d0 = 0;
  for (int i = 1, B = td; i <= B; i++)
    if (!r[i]) d[++d0] = i;
  for (int i = 1; i <= d0; i++) {
    int x = d[i];
    if (!cr[i]) {
      cr[i] = 1;
      cr[dl[i]] = 2;
    }
    for (int j = 0, B = w[x].size(); j < B; j++) {
      int y = w[x][j];
      if (!(--r[y])) d[++d0] = y;
    }
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1, B = m; i <= B; i++) {
    scanf("%d %d %d %d", &b[i].x, &b[i].y, &b[i].z, &b[i].t);
    e[b[i].x].push_back(i);
    e[b[i].y].push_back(i);
  }
  build_graph();
  save();
  int ans = -1;
  {
    for (int l = 0, r = 1e9; l <= r;) {
      int mi = l + r >> 1;
      if (pd(mi))
        ans = mi, r = mi - 1;
      else
        l = mi + 1;
    }
  }
  if (ans == -1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for (int i = 1, B = m; i <= B; i++)
    if (b[i].t > ans) {
      link(2 * i - 1, 2 * i);
    }
  for (int i = 1, B = td; i <= B; i++) dfn[i] = low[i] = 0;
  dfn0 = bl0 = 0;
  for (int i = 1, B = td; i <= B; i++)
    if (!dfn[i]) dg(i);
  for (int i = 1, B = td; i <= B; i++) {
    for (int j = fi[i]; j; j = nt[j]) {
      int x = bl[i], y = bl[to[j]];
      if (x != y) {
        w[y].push_back(x);
        r[x]++;
      }
    }
  }
  for (int i = 1, B = m; i <= B; i++) {
    int x = bl[2 * i], y = bl[2 * i - 1];
    dl[x] = y;
    dl[y] = x;
  }
  turpo();
  int ans2 = 0;
  for (int i = 1, B = m; i <= B; i++)
    if (cr[bl[2 * i - 1]] == 1) ans2++;
  printf("%d %d\n", ans, ans2);
  for (int i = 1, B = m; i <= B; i++)
    if (cr[bl[2 * i - 1]] == 1) printf("%d ", i);
  printf("\n");
}
