#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 3e5 + 4;
const int maxm = 1e4 + 4;
const double pi = acos(-1.0);
int a[maxn];
int n, m, lt, rt, d;
long long c[maxn];
int sign(long long num) {
  if (num == 0) return 0;
  return num > 0 ? 1 : -1;
}
struct Node {
  int lmax, rmax, maxv;
} node[maxn << 2];
void pushup(int pos, int l, int r) {
  int mid = (l + r) / 2;
  node[pos] = {node[pos << 1].lmax, node[pos << 1 | 1].rmax,
               max(node[pos << 1].maxv, node[pos << 1 | 1].maxv)};
  if (!!c[mid] && !!c[mid + 1] && sign(c[mid]) >= sign(c[mid + 1])) {
    if (node[pos << 1].lmax == mid - l + 1)
      node[pos].lmax += node[pos << 1 | 1].lmax;
    if (node[pos << 1 | 1].rmax == r - mid)
      node[pos].rmax += node[pos << 1].rmax;
    node[pos].maxv =
        max(node[pos].maxv, node[pos << 1].rmax + node[pos << 1 | 1].lmax);
  }
  return;
}
void build(int pos, int l, int r) {
  if (l == r) {
    int tmp = !!c[l];
    node[pos] = {tmp, tmp, tmp};
    return;
  }
  int mid = (l + r) / 2;
  build(pos << 1, l, mid);
  build(pos << 1 | 1, mid + 1, r);
  pushup(pos, l, r);
}
void update(int pos, int l, int r, int k, int d) {
  if (l > k || r < k) return;
  if (l == r) {
    c[k] += d;
    int tmp = !!c[k];
    node[pos] = {tmp, tmp, tmp};
    return;
  }
  int mid = (l + r) / 2;
  update(pos << 1, l, mid, k, d);
  update(pos << 1 | 1, mid + 1, r, k, d);
  pushup(pos, l, r);
  return;
}
int main() {
  int ik, i, j, k, kase;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (i = 1; i < n; ++i) c[i] = a[i + 1] - a[i];
  if (n > 1) build(1, 1, n - 1);
  scanf("%d", &m);
  while (m--) {
    scanf("%d%d%d", &lt, &rt, &d);
    if (n == 1) {
      puts("1");
      continue;
    }
    if (lt != 1) update(1, 1, n - 1, lt - 1, d);
    if (rt != n) update(1, 1, n - 1, rt, -d);
    printf("%d\n", node[1].maxv);
  }
  return 0;
}
