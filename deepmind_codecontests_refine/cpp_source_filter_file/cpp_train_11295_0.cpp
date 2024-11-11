#include <bits/stdc++.h>
using namespace std;
int n, q;
struct opt {
  int tp, dir, x, y, len, ans;
} op[100000];
struct data_structure {
  int n, m, data[5005][10005];
  void init(int N, int M) {
    n = N;
    m = M;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) data[i][j] = 0;
    return;
  }
  inline int lb(int x) { return x & (-x); }
  void upd(int x, int y, int k) {
    if (x > n || y > m) return;
    for (int i = x; i <= n; i += lb(i))
      for (int j = y; j <= m; j += lb(j)) data[i][j] += k;
    return;
  }
  void update(int l, int r, int d, int u, int k) {
    l = max(l, 0);
    d = max(d, 0);
    r = min(r, n);
    u = min(u, m);
    upd(l, d, k);
    upd(r + 1, u + 1, k);
    upd(l, u + 1, -k);
    upd(r + 1, d, -k);
    return;
  }
  int query(int x, int y) {
    int res = 0;
    for (int i = x; i > 0; i -= lb(i))
      for (int j = y; j > 0; j -= lb(j)) res += data[i][j];
    return res;
  }
} ds;
int main(void) {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &op[i].tp);
    if (op[i].tp == 1)
      scanf("%d%d%d%d", &op[i].dir, &op[i].x, &op[i].y, &op[i].len);
    else
      scanf("%d%d", &op[i].x, &op[i].y);
    op[i].ans = 0;
  }
  ds.init(n, n + n + 1);
  for (int i = 0; i < q; i++) {
    int x = op[i].x, y = op[i].y, len = op[i].len;
    if (op[i].tp == 1 && op[i].dir == 1) ds.update(x, n, x + y, x + y + len, 1);
    if (op[i].tp == 1 && op[i].dir == 4) ds.update(1, x, x + y - len, x + y, 1);
    if (op[i].tp == 2) op[i].ans += ds.query(x, x + y);
  }
  ds.init(n, n + n + 1);
  for (int i = 0; i < q; i++) {
    int x = op[i].x, y = op[i].y, len = op[i].len;
    if (op[i].tp == 1 && op[i].dir == 1)
      ds.update(1, y - 1, x + y, x + y + len, -1);
    if (op[i].tp == 1 && op[i].dir == 4)
      ds.update(y + 1, n, x + y - len, x + y, -1);
    if (op[i].tp == 2) op[i].ans += ds.query(y, x + y);
  }
  ds.init(n, n + n + 1);
  for (int i = 0; i < q; i++) {
    int x = op[i].x, y = op[i].y, len = op[i].len;
    if (op[i].tp == 1 && op[i].dir == 2)
      ds.update(x, n, x - y + n, x - y + n + len, 1);
    if (op[i].tp == 1 && op[i].dir == 3)
      ds.update(1, x, x - y + n - len, x - y + n, 1);
    if (op[i].tp == 2) op[i].ans += ds.query(x, x - y + n);
  }
  ds.init(n, n + n + 1);
  for (int i = 0; i < q; i++) {
    int x = op[i].x, y = op[i].y, len = op[i].len;
    if (op[i].tp == 1 && op[i].dir == 2)
      ds.update(y + 1, n, x - y + n, x - y + n + len, -1);
    if (op[i].tp == 1 && op[i].dir == 3)
      ds.update(1, y - 1, x - y + n - len, x - y + n, -1);
    if (op[i].tp == 2) {
      op[i].ans += ds.query(y, x - y + n);
      printf("%d\n", op[i].ans);
    }
  }
  return 0;
}
