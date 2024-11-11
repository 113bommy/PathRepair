#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 50000;
const int MAXFLAV = 50000;
const int MAXQ = 50000;
const int MAXS = 4 * MAXN;
struct Q {
  int kind, x, flav;
};
struct E {
  int t, x, by;
  E() {}
  E(int t, int x, int by) : t(t), x(x), by(by) {}
};
int n, nflav, nq, fixedprice;
int initflav[MAXN];
int par[MAXN];
int flavcost[MAXFLAV];
Q q[MAXQ];
int flav[MAXN];
vector<E> e[MAXFLAV];
double ret[MAXQ];
int nret;
int s1[MAXS];
long long s2[MAXS];
int slazy[MAXS];
void sapply(int x, int l, int r, int by) {
  int cnt = r - l + 1;
  s2[x] += (long long)2 * s1[x] * by + (long long)cnt * by * by;
  s1[x] += cnt * by;
  slazy[x] += by;
}
void spush(int x, int l, int m, int r) {
  if (slazy[x] != 0)
    sapply(2 * x + 1, l, m, slazy[x]), sapply(2 * x + 2, m + 1, r, slazy[x]),
        slazy[x] = 0;
}
void spull(int x) {
  s1[x] = s1[2 * x + 1] + s1[2 * x + 2];
  s2[x] = s2[2 * x + 1] + s2[2 * x + 2];
}
void smod(int x, int l, int r, int L, int R, int BY) {
  if (L <= l && r <= R) {
    sapply(x, l, r, BY);
  } else {
    int m = l + (r - l) / 2;
    spush(x, l, m, r);
    if (L <= m) smod(2 * x + 1, l, m, L, R, BY);
    if (m + 1 <= R) smod(2 * x + 2, m + 1, r, L, R, BY);
    spull(x);
  }
}
vector<int> ch[MAXN];
int sz[MAXN];
int heavy[MAXN];
int hroot[MAXN], hidx[MAXN], nh;
void dfs1(int at) {
  sz[at] = 1, heavy[at] = -1;
  for (int i = (0); i < (((int)(ch[at]).size())); ++i) {
    int to = ch[at][i];
    dfs1(to);
    sz[at] += sz[to];
    if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
  }
}
void dfs2(int at) {
  if (par[at] == -1 || heavy[par[at]] != at) {
    for (int x = at; x != -1; x = heavy[x]) hroot[x] = at, hidx[x] = nh++;
  }
  for (int i = (0); i < (((int)(ch[at]).size())); ++i) {
    int to = ch[at][i];
    dfs2(to);
  }
}
void inithld() {
  for (int i = (0); i < (n); ++i)
    if (par[i] != -1) ch[par[i]].push_back(i);
  dfs1(0);
  nh = 0;
  dfs2(0);
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  memset(slazy, 0, sizeof(slazy));
}
double calc(int f) {
  double ac1 = 1.0 * s1[0] / n * flavcost[f],
         ac2 = 1.0 * s2[0] / n * flavcost[f] * flavcost[f];
  double ret = (ac2 - (long long)2 * fixedprice * ac1 +
                (long long)fixedprice * fixedprice);
  return ret;
}
void modify(int at, int by) {
  while (at != -1) {
    smod(0, 0, nh - 1, hidx[hroot[at]], hidx[at], by);
    at = par[hroot[at]];
  }
}
void run() {
  scanf("%d%d%d%d", &n, &nflav, &nq, &fixedprice);
  for (int i = (0); i < (n); ++i) scanf("%d", &initflav[i]), --initflav[i];
  par[0] = -1;
  for (int i = (1); i < (n); ++i) scanf("%d", &par[i]), --par[i];
  for (int i = (0); i < (nflav); ++i) scanf("%d", &flavcost[i]);
  for (int i = (0); i < (nq); ++i) {
    scanf("%d", &q[i].kind);
    if (q[i].kind == 1)
      scanf("%d%d", &q[i].x, &q[i].flav), --q[i].x, --q[i].flav;
    if (q[i].kind == 2) scanf("%d", &q[i].flav), --q[i].flav;
  }
  inithld();
  for (int i = (0); i < (n); ++i) flav[i] = initflav[i];
  for (int i = (0); i < (n); ++i) e[flav[i]].push_back(E(-1, i, +1));
  nret = 0;
  for (int i = (0); i < (nq); ++i) {
    if (q[i].kind == 1) {
      int x = q[i].x;
      if (flav[x] != q[i].flav) {
        e[flav[x]].push_back(E(i, x, -1));
        flav[x] = q[i].flav;
        e[flav[x]].push_back(E(i, x, +1));
      }
    }
    if (q[i].kind == 2) e[q[i].flav].push_back(E(i, nret++, 0));
  }
  for (int i = (0); i < (n); ++i) e[flav[i]].push_back(E(nq, i, -1));
  for (int i = (0); i < (nflav); ++i) {
    for (int j = (0); j < (((int)(e[i]).size())); ++j) {
      if (e[i][j].by == 0) {
        ret[e[i][j].x] = calc(i);
      } else {
        modify(e[i][j].x, e[i][j].by);
      }
    }
  }
  for (int i = (0); i < (nret); ++i) printf("%.15lf\n", ret[i]);
}
int main() {
  run();
  return 0;
}
