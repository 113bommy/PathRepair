#include <bits/stdc++.h>
using namespace std;
inline int qr() {
  int res = 0, f = 0, c = getchar();
  while (!isdigit(c)) f |= c == 45, c = getchar();
  while (isdigit(c)) res = res * 10 + c - 48, c = getchar();
  return f ? -res : res;
}
const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int fa[M], siz[M], stk[M], top, n, m, cnt, ans[M * 4];
struct Edge {
  int u, v, w;
} e[M * 3];
map<int, vector<int> > C;
int findf(int x) { return x == fa[x] ? x : fa[x] = findf(fa[x]); }
inline int merge(int x, int y) {
  int fx = findf(x), fy = findf(y);
  if (fx == fy) return 0;
  if (siz[fx] > siz[fy]) swap(fx, fy);
  cnt -= (siz[fx] & 1);
  cnt -= (siz[fy] & 1);
  siz[fy] += siz[fx];
  cnt += (siz[fy] & 1);
  fa[fx] = fy;
  stk[++top] = fx;
  return 1;
}
inline void undo(int x) {
  while (x--) {
    int u = stk[top], v = fa[u];
    cnt -= (siz[v] & 1);
    siz[v] -= siz[u];
    cnt += (siz[v] & 1) + (siz[u] & 1);
    fa[u] = u;
    top--;
  }
}
void solve(int tl, int tr, int vl, int vr) {
  if (vl > vr || tl > tr) return;
  int base = 0, backup1 = 0, res = vr, mid = (tl + tr) / 2;
  for (int i = tl; i <= mid; i++)
    if (e[i].w < vl) base += merge(e[i].u, e[i].v);
  for (auto it = C.lower_bound(vl), ed = C.upper_bound(vr); it != ed; it++)
    for (int tim : it->second)
      if (tim <= mid) {
        if (cnt) backup1 += merge(e[tim].u, e[tim].v);
        if (!cnt) {
          res = e[tim].w;
          goto end;
        }
      }
end:;
  ans[mid] = res;
  undo(backup1);
  solve(mid + 1, tr, vl, res);
  undo(base);
  base = 0;
  for (auto it = C.lower_bound(vl), ed = C.lower_bound(res); it != ed; it++)
    for (int tim : it->second)
      if (tim < tl) base += merge(e[tim].u, e[tim].v);
  solve(tl, mid - 1, res, vr);
  undo(base);
}
int main() {
  memset(ans, 0x3f, sizeof ans);
  n = qr(), m = qr();
  for (int t = 1; t <= n; ++t) fa[t] = t, siz[t] = 1;
  cnt = n;
  for (int t = 1; t <= m; ++t)
    e[t].u = qr(), e[t].v = qr(), e[t].w = qr(), C[e[t].w].push_back(t);
  solve(1, m, 1, INF);
  for (int t = 1; t <= m; ++t) printf("%d\n", ans[t] == INF ? -1 : ans[t]);
  return 0;
}
