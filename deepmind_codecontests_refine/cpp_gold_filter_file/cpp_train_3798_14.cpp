#include <bits/stdc++.h>
const int NUM = 200010;
const double EPS = 1e-10, PI = acos(-1.0);
using namespace std;
int n, m, k, q;
int ans[NUM];
struct node {
  int x1, x2;
  int y1, y2;
  int c;
  bool operator<(const node b) const {
    if (x1 == b.x1) return c < b.c;
    return x1 < b.x1;
  }
} x[2 * NUM], y[2 * NUM];
int nx, ny;
int minpos[4 * NUM];
void update(int p, int l, int r, int x, int y) {
  if (l == r) {
    minpos[p] = y;
    return;
  }
  int mid = (l + r) >> 1;
  if (x <= mid)
    update((p << 1), l, mid, x, y);
  else
    update((p << 1 | 1), mid + 1, r, x, y);
  minpos[p] = min(minpos[(p << 1)], minpos[(p << 1 | 1)]);
}
int query(int p, int l, int r, int x, int y) {
  if (x <= l && r <= y) return minpos[p];
  int mid = (l + r) >> 1;
  int pos = 1000000007;
  if (x <= mid) pos = min(pos, query((p << 1), l, mid, x, y));
  if (y > mid) pos = min(pos, query((p << 1 | 1), mid + 1, r, x, y));
  return pos;
}
void solve(node a[], int an, int w) {
  int i;
  memset(minpos, -1, sizeof(minpos));
  sort(a, a + an);
  for (i = 0; i < an; i++) {
    if (a[i].c == -1) {
      update(1, 1, w, a[i].y1, a[i].x1);
    } else {
      int x = query(1, 1, w, a[i].y1, a[i].y2);
      if (x < a[i].x2 || x == 1000000007) ans[a[i].c]++;
    }
  }
}
int main() {
  int i, j;
  scanf("%d%d%d%d", &n, &m, &k, &q);
  int x1, x2, y1, y2;
  nx = ny = 0;
  memset(ans, 0, sizeof(ans));
  for (i = 0; i < k; i++) {
    scanf("%d%d", &x1, &y1);
    x[nx++] = (node){x1, 0, y1, 0, -1};
    y[ny++] = (node){y1, 0, x1, 0, -1};
  }
  for (i = 0; i < q; i++) {
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x[nx++] = (node){x2, x1, y1, y2, i};
    y[ny++] = (node){y2, y1, x1, x2, i};
  }
  solve(x, nx, m);
  solve(y, ny, n);
  for (i = 0; i < q; i++) {
    if (ans[i] == 2)
      puts("NO");
    else
      puts("YES");
  }
  return 0;
}
