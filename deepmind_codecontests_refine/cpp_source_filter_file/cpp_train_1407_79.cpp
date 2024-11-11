#include <bits/stdc++.h>
using namespace std;
int fa[100005], siz[100005], stk[100005], top, n, m, cnt, ans[100005 * 4];
struct Edge {
  int u, v, w;
} e[100005 * 3];
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
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    (x *= 10) += ch - '0';
    ch = getchar();
  }
  return x * f;
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
  n = read(), m = read();
  cnt = n;
  memset(ans, 0x3f3f3f3f, sizeof(ans));
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  for (int i = 1; i <= m; i++)
    e[i].u = read(), e[i].v = read(), e[i].w = read(), C[e[i].w].push_back(i);
  solve(1, m, 1, 0x3f3f3f3f);
  for (int i = 1; i <= m; i++)
    printf("%d\n", ans[i] == 0x3f3f3f3f ? -1 : ans[i]);
  return 0;
}
