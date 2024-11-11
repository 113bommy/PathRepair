#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, top, Q;
int a[200010], b[200010], c[200010];
struct P {
  int op, x, y, val, id;
} p[200010 * 5], tmp[200010 * 5];
int ans[200010];
struct BIT {
  int t[200010];
  int lowbit(int x) { return x & (-x); }
  void modi(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i)) t[i] += y;
  }
  int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += t[i];
    return res;
  }
} B;
void work(P a, int x) {
  if (a.op != x) return;
  if (a.op == 1)
    ans[a.id] += B.query(a.y) * a.val;
  else
    B.modi(a.y, a.val);
}
void solve(int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  solve(l, mid);
  solve(mid + 1, r);
  int p1 = l, p2 = mid + 1, pos = l;
  while (p1 <= mid && p2 <= r) {
    if (p[p1].x <= p[p2].x) {
      work(p[p1], 2);
      tmp[pos++] = p[p1++];
    } else {
      work(p[p2], 1);
      tmp[pos++] = p[p2++];
    }
  }
  while (p1 <= mid) work(p[p1], 2), tmp[pos++] = p[p1++];
  while (p2 <= r) work(p[p2], 1), tmp[pos++] = p[p2++];
  for (int i = l; i <= mid; i++)
    if (p[i].op == 2) B.modi(p[i].y, -p[i].val);
  for (int i = l; i <= r; i++) p[i] = tmp[i];
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) a[read()] = i;
  for (int i = 1; i <= n; i++) b[i] = read(), c[b[i]] = i;
  for (int i = 1; i <= n; i++) p[++top] = (P){2, a[i], c[i], 1, 0};
  for (int i = 1; i <= m; i++) {
    int op = read();
    if (op == 1) {
      ++Q;
      int x1 = read(), x2 = read(), y1 = read(), y2 = read();
      p[++top] = (P){1, x2, y2, 1, Q};
      p[++top] = (P){1, x2, y1 - 1, -1, Q};
      p[++top] = (P){1, x1 - 1, y2, -1, Q};
      p[++top] = (P){1, x1 - 1, y1 - 1, 1, Q};
    } else {
      int x = read(), y = read();
      int u = b[x], v = b[y];
      p[++top] = (P){2, a[u], c[u], -1, i};
      p[++top] = (P){2, a[v], c[v], -1, i};
      swap(b[x], b[y]);
      swap(c[u], c[v]);
      p[++top] = (P){2, a[u], c[u], 1, i};
      p[++top] = (P){2, a[v], c[v], 1, i};
    }
  }
  solve(1, top);
  for (int i = 1; i <= Q; i++) printf("%d\n", ans[i]);
  return 0;
}
