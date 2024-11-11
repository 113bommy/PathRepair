#include <bits/stdc++.h>
using namespace std;
const int N = 100009;
int point[N], f[N][30], dep[N], n, m, head[N], cnt, root, DFN[N], Index, siz[N],
    rev[N];
long long sum[N * 4], add[N * 4];
struct Edge {
  int nxt, to;
} g[N * 2];
void ADD(int k, long long v, int l, int r) {
  sum[k] += 1LL * (r - l + 1) * v, add[k] += v;
}
void push_down(int k, int mid, int l, int r) {
  ADD(k << 1, add[k], l, mid), ADD(k << 1 | 1, add[k], mid + 1, r);
  add[k] = 0;
}
void Modify(int k, int l, int r, int x, int y, int v) {
  if (l >= x && r <= y) {
    ADD(k, v, l, r);
    return;
  }
  int mid = l + r >> 1;
  push_down(k, mid, l, r);
  if (mid >= x) Modify(k << 1, l, mid, x, y, v);
  if (mid < y) Modify(k << 1 | 1, mid + 1, r, x, y, v);
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
long long Querysum(int k, int l, int r, int x, int y) {
  if (l >= x && r <= y) return sum[k];
  int mid = l + r >> 1;
  long long res = 0;
  push_down(k, mid, l, r);
  if (mid >= x) res += Querysum(k << 1, l, mid, x, y);
  if (mid < y) res += Querysum(k << 1 | 1, mid + 1, r, x, y);
  return res;
}
void A(int from, int to) {
  g[++cnt].nxt = head[from];
  g[cnt].to = to;
  head[from] = cnt;
}
void init() {
  scanf("%d %d", &n, &m);
  int x, y;
  for (int i = 1; i <= n; i++) scanf("%d", &point[i]);
  for (int i = 1; i < n; i++) scanf("%d %d", &x, &y), A(x, y), A(y, x);
}
void dfs(int x, int fa) {
  DFN[x] = ++Index, siz[x] = 1, rev[Index] = x;
  for (int i = head[x]; i; i = g[i].nxt) {
    int v = g[i].to;
    if (v == fa) continue;
    dep[v] = dep[x] + 1;
    f[v][0] = x;
    dfs(v, x);
    siz[x] += siz[v];
  }
}
int get(int x, int k) {
  for (int i = 20; i >= 0; i--)
    if (k >= 1 << i) k -= 1 << i, x = f[x][i];
  return x;
}
int LCA(int x, int y) {
  if (dep[x] != dep[y]) {
    if (dep[x] < dep[y]) swap(x, y);
    x = get(x, dep[x] - dep[y]);
  }
  if (x == y) return x;
  for (int i = 20; i >= 0; i--)
    if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
  return f[y][0];
}
int Get_Root(int x, int y) {
  if (dep[x] < dep[y]) swap(x, y);
  int L = LCA(x, y), Root = DFN[root];
  if (L == y) {
    if (Root < DFN[y] || Root > DFN[y] + siz[y] - 1) return y;
    return LCA(x, root);
  }
  if (Root >= DFN[x] && Root <= DFN[x] + siz[x] - 1) return x;
  if (Root >= DFN[y] && Root <= DFN[y] + siz[y] - 1) return y;
  int Lx = LCA(root, x), Ly = LCA(root, y);
  if (Root < DFN[L] || Root > DFN[L] + siz[L] - 1 || (Lx == L && Ly == L))
    return L;
  if (Lx == L) return Ly;
  return Lx;
}
void Modify_2(int R, int v) {
  if (R == root)
    Modify(1, 1, n, 1, Index, v);
  else if (DFN[root] < DFN[R] || DFN[root] > DFN[R] + siz[R] - 1)
    Modify(1, 1, n, DFN[R], DFN[R] + siz[R] - 1, v);
  else {
    Modify(1, 1, n, 1, Index, v);
    int x = get(root, dep[root] - dep[R] - 1);
    Modify(1, 1, n, DFN[x], DFN[x] + siz[x] - 1, -v);
  }
}
long long Querysum_2(int R) {
  long long res = 0;
  if (R == root)
    res += Querysum(1, 1, n, 1, Index);
  else if (DFN[root] < DFN[R] || DFN[root] > DFN[R] + siz[R] - 1)
    res += Querysum(1, 1, n, DFN[R], DFN[R] + siz[R] - 1);
  else {
    res += Querysum(1, 1, n, 1, Index);
    int x = get(root, dep[root] - dep[R] - 1);
    res -= Querysum(1, 1, n, DFN[x], DFN[x] + siz[x] - 1);
  }
  return res;
}
void build(int k, int l, int r) {
  if (l == r) {
    sum[k] = point[rev[l]];
    return;
  }
  int mid = l + r >> 1;
  build(k << 1, l, mid);
  build(k << 1 | 1, mid + 1, r);
  sum[k] = sum[k << 1] + sum[k << 1 | 1];
}
void work() {
  dfs(1, -1);
  for (int j = 1; j <= 20; j++)
    for (int i = 1; i <= n; i++) f[i][j] = f[f[i][j - 1]][j - 1];
  build(1, 1, n);
  int opt, x, y, z;
  root = 1;
  while (m--) {
    scanf("%d", &opt);
    if (opt == 1)
      scanf("%d", &root);
    else if (opt == 2) {
      scanf("%d %d %d", &x, &y, &z);
      int R = Get_Root(x, y);
      Modify_2(R, z);
    } else
      scanf("%d", &x), printf("%lld\n", Querysum_2(x));
  }
}
int main() {
  init();
  work();
  return 0;
}
