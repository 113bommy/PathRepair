#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
int n, m, fa[N], sz[N], o[2], ans[N], id[N];
struct edge {
  int u, v, w, id;
  bool operator<(const edge& tp) const { return w < tp.w; }
} e[N], E[N];
int find(int x) { return fa[x] == x ? x : find(fa[x]); }
struct dsu {
  int p[N], pa[N], top;
  void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);
    p[++top] = y, pa[top] = x, fa[y] = x;
    --o[sz[x] & 1], --o[sz[y] & 1], sz[x] += sz[y], ++o[sz[x] & 1];
  }
  void pop() {
    int x = pa[top], y = p[top];
    --top;
    --o[sz[x] & 1], sz[x] -= sz[y], ++o[sz[x] & 1], ++o[sz[y] & 1];
    fa[y] = y;
  }
} S;
void cdq(int l, int r, int ansl, int ansr) {
  if (l > r || ansl > ansr) return;
  int mid = (l + r) >> 1, precnt = S.top;
  ans[mid] = ansr + 1;
  for (int i = l; i <= mid; ++i) {
    if (id[i] >= ansl) continue;
    S.merge(e[i].u, e[i].v);
  }
  for (int i = ansl; i <= ansr; ++i) {
    if (E[i].id > mid) continue;
    S.merge(E[i].u, E[i].v);
    if (!o[1]) {
      ans[mid] = i;
      break;
    }
  }
  while (S.top > precnt) S.pop();
  for (int i = ansl; i < ans[mid]; ++i) {
    if (E[i].id >= l) continue;
    S.merge(E[i].u, E[i].v);
  }
  cdq(l, mid - 1, ans[mid], ansr);
  while (S.top > precnt) S.pop();
  for (int i = l; i <= mid; ++i) {
    if (id[i] >= ansl) continue;
    S.merge(e[i].u, e[i].v);
  }
  cdq(mid + 1, r, ansl, min(ansr, ans[mid]));
  if (ans[mid] == ansr + 1) ans[mid] = -1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i)
    scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), e[i].id = i, E[i] = e[i];
  sort(E + 1, E + m + 1);
  for (int i = 1; i <= m; ++i) id[E[i].id] = i;
  for (int i = 1; i <= n; ++i) fa[i] = i, sz[i] = 1, ++o[1];
  memset(ans, -1, sizeof(ans));
  cdq(1, m, 1, m);
  for (int i = 1; i <= m; ++i)
    ~ans[i] ? printf("%d\n", E[ans[i]].w) : puts("-1");
  return 0;
}
