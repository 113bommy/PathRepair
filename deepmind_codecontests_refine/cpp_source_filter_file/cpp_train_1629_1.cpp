#include <bits/stdc++.h>
using namespace std;
const int N = 200010, M = 1 << 20 | 5;
int n, cnt, G[N];
struct edge {
  int t, nx;
} E[N << 1];
char a[N];
long long ans[N], cans[N];
inline void addedge(int x, int y) {
  E[++cnt].t = y;
  E[cnt].nx = G[x];
  G[x] = cnt;
  E[++cnt].t = x;
  E[cnt].nx = G[y];
  G[y] = cnt;
}
int mx, rt, tot, clk, vis[N], ct[M], ti[M], size[N];
void pfs(int x, int f) {
  ans[x] += cans[x];
  cans[x] = 0;
  for (int i = G[i]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) pfs(E[i].t, x);
}
void getsz(int x, int f) {
  size[x] = 1;
  for (int i = G[x]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) {
      getsz(E[i].t, x);
      size[x] += size[E[i].t];
    }
}
void getrt(int x, int f) {
  int mn = 0;
  for (int i = G[x]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) {
      getrt(E[i].t, x);
      mn = max(mn, size[E[i].t]);
    }
  mn = max(mn, tot - size[x]);
  if (mn < mx) mx = mn, rt = x;
}
void Q(int x, int f, int s) {
  s ^= 1 << (a[x] - 'a');
  ans[rt] += (clk == ti[s]) * ct[s];
  for (int i = 0; i < 20; i++)
    if (clk == ti[s ^ (1 << i)]) ans[rt] += ct[s ^ (1 << i)];
  for (int i = G[x]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) Q(E[i].t, x, s);
}
void add(int x, int f, int y, int s) {
  s ^= 1 << (a[x] - 'a');
  if (ti[s] != clk) ti[s] = clk, ct[s] = 0;
  ct[s] += y;
  for (int i = G[x]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) add(E[i].t, x, y, s);
}
void upd(int x, int f, int s) {
  s ^= 1 << (a[x] - 'a');
  cans[x] += (ti[s] == clk) * ct[s];
  for (int i = 0; i < 20; i++)
    if (ti[s ^ (1 << i)] == clk) cans[x] += ct[s ^ (1 << i)];
  for (int i = G[x]; i; i = E[i].nx)
    if (E[i].t != f && !vis[E[i].t]) {
      upd(E[i].t, x, s);
      cans[x] += cans[E[i].t];
    }
}
void solve(int x) {
  getsz(x, 0);
  ++clk;
  mx = 1 << 30;
  tot = size[x];
  getrt(x, 0);
  int cur = rt;
  vis[cur] = 1;
  ct[1 << (a[rt] - 'a')] = 1;
  ti[1 << (a[rt] - 'a')] = clk;
  ans[cur]++;
  for (int i = G[rt]; i; i = E[i].nx)
    if (!vis[E[i].t]) Q(E[i].t, rt, 0), add(E[i].t, rt, 1, 1 << (a[rt] - 'a'));
  for (int i = G[rt]; i; i = E[i].nx)
    if (!vis[E[i].t]) {
      add(E[i].t, rt, -1, 1 << (a[rt] - 'a'));
      upd(E[i].t, rt, 0);
      add(E[i].t, rt, 1, 1 << (a[rt] - 'a'));
      pfs(E[i].t, rt);
    }
  for (int i = G[cur]; i; i = E[i].nx)
    if (!vis[E[i].t]) solve(E[i].t);
}
int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i++) scanf("%d%d", &x, &y), addedge(x, y);
  scanf("%s", a + 1);
  solve(1);
  for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
  return 0;
}
