#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-6;
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
const int maxn = 2e5 + 10;
struct pnt {
  int x, y, del;
  pnt(int xx = 0, int yy = 0, int dd = 0) {
    x = xx;
    y = yy;
    del = dd;
  }
};
vector<pnt> vp;
int n, p[2], mx, on[maxn], d[maxn], fa[maxn];
long long ans = 0;
vector<int> edg[maxn];
void dfs1(int u, int f, int dis, int pos) {
  if (dis > mx) {
    p[pos] = u;
    mx = dis;
  }
  d[u] = dis;
  fa[u] = f;
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == f) continue;
    dfs1(v, u, dis + 1, pos);
  }
}
void dfs2(int u, int f, int d1, int d2) {
  for (int i = 0; i < edg[u].size(); i++) {
    int v = edg[u][i];
    if (v == f || on[v]) continue;
    dfs2(v, u, d1 + 1, d2 + 1);
  }
  if (on[u]) {
    if (fa[u] != u) dfs2(fa[u], u, d1 + 1, d2 - 1);
    ans += d1;
    if (u != p[1]) vp.push_back(pnt(p[1], u, u));
    return;
  }
  if (d1 > d2) {
    ans += d1;
    vp.push_back(pnt(p[1], u, u));
  } else {
    ans += d2;
    vp.push_back(pnt(p[0], u, u));
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v;
    scanf("%d", &u);
    scanf("%d", &v);
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  mx = -1;
  dfs1(1, 1, 0, 0);
  mx = -1;
  dfs1(p[0], p[0], 0, 1);
  on[p[0]] = 1;
  for (int i = p[1]; i != p[0]; i = fa[i]) {
    on[i] = 1;
  }
  dfs2(p[1], p[1], 0, d[p[1]]);
  printf("%I64d\n", ans);
  for (int i = 0; i < vp.size(); i++) {
    printf("%d %d %d\n", vp[i].x, vp[i].y, vp[i].del);
  }
  return 0;
}
