#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = maxn * 20;
long long st[maxm], siz[maxm], sum[maxm];
int n;
int fa[maxn << 1], maxr[maxn << 1], minl[maxn << 1], A[maxn], B[maxn];
int now;
int L[maxm], R[maxm], RT[maxn];
long long ans;
void build(int &x, int l, int r, int px) {
  if (!x) x = ++now;
  ++siz[x], sum[x] += px;
  if (l == r) return;
  int mid = (l + r) >> 1;
  if (px <= mid)
    build(L[x], l, mid, px);
  else
    build(R[x], mid + 1, r, px);
}
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(int &x, int y, int l, int r) {
  if (!x || !y) {
    x = x + y;
    return;
  }
  if (l == r) {
    st[x] = st[x] + st[y] + sum[x] * siz[y];
    siz[x] += siz[y], sum[x] += sum[y];
    return;
  }
  int mid = (l + r) >> 1;
  merge(L[x], L[y], l, mid);
  merge(R[x], R[y], mid + 1, r);
  st[x] = st[L[x]] + st[R[x]] + sum[L[x]] * siz[R[x]];
  siz[x] = siz[L[x]] + siz[R[x]], sum[x] = sum[L[x]] + sum[R[x]];
}
void solve(int x, int y) {
  ans -= st[RT[x]] + st[RT[y]] + (long long)(minl[y] - minl[x]) * sum[RT[y]];
  merge(RT[x], RT[y], 1, n);
  ans += st[RT[x]];
  fa[y] = x, minl[x] = min(minl[x], minl[y]), maxr[x] = max(maxr[x], maxr[y]);
}
void update(int x, int y) {
  int p = find(x - 1), q = find(x + 1), u = find(x);
  build(RT[u], 1, n, y);
  if (RT[p]) u = find(x), solve(p, u);
  if (RT[q]) u = find(x), solve(u, q);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= 4e5; ++i) fa[i] = i, minl[i] = i, maxr[i] = i;
  for (int i = 1; i <= n; ++i) scanf("%d%d", &A[i], &B[i]);
  for (int i = 1; i <= n; ++i) {
    int u = find(A[i]);
    int pos = RT[u] ? maxr[u] + 1 : u;
    ans += (long long)(pos - A[i]) * B[i];
    update(pos, B[i]);
    printf("%lld\n", ans);
  }
  return 0;
}
