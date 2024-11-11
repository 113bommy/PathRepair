#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v, vl;
  Edge() {}
  Edge(int _u, int _v, int _vl) : u(_u), v(_v), vl(_vl) {}
} edge[300010];
int odd, n, m, f[100010], siz[100010], rk[300010], ans[300010];
vector<int> v1, v2, v3, v4;
struct Query {
  int val, id;
  Query() {}
  Query(int _vl, int _id) : val(_vl), id(_id) {}
} q[300010];
bool cmp1(Query _, Query __) { return _.val < __.val; }
void uni(int x, int y) {
  while (f[x] != x) x = f[x];
  while (f[y] != y) y = f[y];
  if (x == y) return;
  if (siz[x] < siz[y]) swap(x, y);
  if ((siz[x] & 1) && (siz[y] & 1))
    v1.push_back(2), odd -= 2;
  else
    v1.push_back(0);
  v2.push_back(x), v3.push_back(siz[x]), siz[x] += siz[y];
  v4.push_back(y), f[y] = x;
}
void back(int sz) {
  while ((int)(v1.size()) > sz) {
    odd += v1.back();
    v1.pop_back();
    siz[v2.back()] = v3.back();
    v2.pop_back(), v3.pop_back();
    f[v4.back()] = v4.back();
    v4.pop_back();
  }
}
void divide(int l, int r, int L, int R) {
  if (l > r) return;
  if (L > R) return;
  int mid = (l + r) >> 1, Mid = -1, mem = v1.size();
  for (int i = l; i <= mid; i++)
    if (rk[i] < L) uni(edge[i].u, edge[i].v);
  for (int i = L; i <= R; i++)
    if (q[i].id <= mid) {
      uni(edge[q[i].id].u, edge[q[i].id].v);
      if (odd == 0) {
        Mid = i;
        break;
      }
    }
  back(mem);
  if (Mid == -1) {
    for (int i = l; i <= mid; i++) ans[i] = -1;
    for (int i = l; i <= mid; i++)
      if (rk[i] < L) uni(edge[i].u, edge[i].v);
    divide(mid + 1, r, L, R);
    back(mem);
    return;
  }
  ans[mid] = q[Mid].val;
  for (int i = L; i < Mid; i++)
    if (q[i].id < l) uni(edge[q[i].id].u, edge[q[i].id].v);
  divide(l, mid - 1, Mid, R);
  back(mem);
  for (int i = l; i <= mid; i++)
    if (rk[i] < L) uni(edge[i].u, edge[i].v);
  divide(mid + 1, r, L, Mid - 1);
  back(mem);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, v;
    scanf("%d%d%d", &x, &y, &v);
    edge[i] = Edge(x, y, v);
    q[i] = Query(v, i);
  }
  sort(q + 1, q + m + 1, cmp1);
  for (int i = 1; i <= m; i++) rk[q[i].id] = i;
  q[m + 1].val = 1 << 30;
  odd = n;
  for (int i = 1; i <= n; i++) f[i] = i, siz[i] = 1;
  divide(1, m, 1, m);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
