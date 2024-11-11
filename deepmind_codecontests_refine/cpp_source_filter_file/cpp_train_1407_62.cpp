#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 3e5 + 5;
int n, m, fa[N], siz[N], tp, od, ans[N];
struct node {
  int x, y, z, id;
} q[M], p[M];
struct po {
  int x, y, del;
} st[M];
bool cmp(node a, node b) { return a.z < b.z; }
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
void merge(int x, int y) {
  x = get(x), y = get(y);
  if (x == y) return;
  if (siz[x] > siz[y]) swap(x, y);
  po nw = (po){x, y, 0};
  if ((siz[x] & 1) && (siz[y] & 1)) nw.del = 2, od -= 2;
  st[++tp] = nw;
  fa[x] = y;
  siz[y] += siz[x];
}
void dele() {
  po nw = st[tp];
  od += nw.del;
  siz[nw.y] -= siz[nw.x];
  fa[nw.x] = nw.x;
  tp--;
}
void div(int l, int r, int L, int R) {
  if (l > r) return;
  int las = tp, mid = l + r >> 1, k = -1;
  for (int i = l; i <= mid; i++)
    if (q[i].id < L) merge(q[i].x, q[i].y);
  for (int i = L; i <= R; i++) {
    if (p[i].id <= mid) merge(p[i].x, p[i].y);
    if (od == 0) {
      k = i;
      break;
    }
  }
  while (tp != las) dele();
  if (k == -1) {
    for (int i = l; i <= mid; i++) ans[i] = -1;
    for (int i = l; i <= mid; i++)
      if (q[i].id < L) merge(q[i].x, q[i].y);
    div(mid + 1, r, L, R);
    while (tp != las) dele();
    return;
  }
  ans[mid] = p[k].z;
  for (int i = L; i < k; i++)
    if (p[i].id < l) merge(p[i].x, p[i].y);
  div(l, mid - 1, k, R);
  while (tp != las) dele();
  for (int i = l; i <= mid; i++)
    if (q[i].id < L) merge(q[i].x, q[i].y);
  div(mid + 1, r, L, k);
  while (tp != las) dele();
}
int main() {
  scanf("%d%d", &n, &m);
  od = n;
  if (n & 1) {
    for (int i = 1; i <= m; i++) puts("-1");
    return 0;
  }
  for (int i = 1; i <= m; i++)
    scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z), p[i] = q[i], p[i].id = i;
  sort(p + 1, p + 1 + m, cmp);
  for (int i = 1; i <= m; i++) q[p[i].id].id = i;
  for (int i = 1; i <= n; i++) fa[i] = i, siz[i] = 1;
  div(1, m, 1, m);
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
