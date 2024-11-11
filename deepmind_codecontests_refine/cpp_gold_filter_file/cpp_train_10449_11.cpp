#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn = 1e5 + 100;
struct node {
  int x, y;
} p[maxn];
int x[maxn], y[maxn];
int cnt[10];
int a[10], num[10];
vector<int> tree[maxn * 4];
bool cmp(node a, node b) { return a.x < b.x; }
void build(int rt, int l, int r) {
  for (int i = l; i <= r; i++) {
    tree[rt].push_back(p[i].y);
  }
  sort(tree[rt].begin(), tree[rt].end());
  if (l == r) return;
  int mid = (l + r) / 2;
  build(rt * 2, l, mid);
  build(rt * 2 + 1, mid + 1, r);
}
int query(int rt, int l, int r, int xx, int yy) {
  if (r <= xx) {
    return upper_bound(tree[rt].begin(), tree[rt].end(), yy) - tree[rt].begin();
  }
  int mid = (l + r) / 2;
  int res = query(rt * 2, l, mid, xx, yy);
  if (xx > mid) res += query(rt * 2 + 1, mid + 1, r, xx, yy);
  return res;
}
void gao() {
  int x0 = num[1] + num[2] + num[3];
  int x1 = x0 + num[4] + num[5] + num[6];
  int y0 = num[1] + num[4] + num[7];
  int y1 = num[2] + num[5] + num[8] + y0;
  if (x[x0] == x[x0 + 1] || x[x1] == x[x1 + 1] || y[y0] == y[y0 + 1] ||
      y[y1] == y[y1 + 1])
    return;
  if (query(1, 1, n, x0, y[y0]) == num[1] &&
      query(1, 1, n, x0, y[y1]) == num[1] + num[2] &&
      query(1, 1, n, x1, y[y0]) == num[1] + num[4] &&
      query(1, 1, n, x1, y[y1]) == num[1] + num[2] + num[4] + num[5]) {
    printf("%.8f %.8f\n%.8f %.8f\n", 0.5 + x[x0], 0.5 + x[x1], 0.5 + y[y0],
           0.5 + y[y1]);
    exit(0);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    scanf("%d%d", &p[i].x, &p[i].y), x[i] = p[i].x, y[i] = p[i].y;
  for (int i = 1; i <= 9; i++) scanf("%d", cnt + i);
  sort(x + 1, x + 1 + n);
  sort(y + 1, y + 1 + n);
  sort(p + 1, p + 1 + n, cmp);
  build(1, 1, n);
  for (int i = 1; i <= 9; i++) a[i] = i;
  for (int i = 1; i <= 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9; i++) {
    for (int j = 1; j <= 9; j++) {
      num[j] = cnt[a[j]];
    }
    gao();
    next_permutation(a + 1, a + 1 + 9);
  }
  printf("-1");
  return 0;
}
