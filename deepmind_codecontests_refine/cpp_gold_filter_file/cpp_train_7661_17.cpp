#include <bits/stdc++.h>
using namespace std;
const int _ = 1e2;
const int maxn = 5e5 + _;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x;
}
struct edge {
  int x, y, l, r;
  edge() {}
  edge(int X, int Y, int L, int R) { x = X, y = Y, l = L, r = R; }
};
struct cmp {
  bool operator()(const edge &x, const edge &y) { return x.l > y.l; }
};
priority_queue<edge, vector<edge>, cmp> q;
struct node {
  int y, r, next;
} a[4 * maxn];
int len, last[2][maxn];
void ins(int op, int x, int y, int r) {
  a[++len].y = y;
  a[len].r = r;
  a[len].next = last[op][x];
  last[op][x] = len;
}
int f[2][maxn];
int main() {
  int n, m, x, y, l, r;
  edge p;
  n = read(), m = read();
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    x = read(), y = read(), l = read(), r = read() - 1;
    if (l == r)
      q.push(edge(x, y, l, r)), q.push(edge(y, x, l, r));
    else {
      p = edge(x, y, l, r - (r - l) % 2);
      q.push(p);
      p = edge(y, x, l, r - (r - l) % 2);
      q.push(p);
      p = edge(x, y, l + 1, r - (r - l - 1) % 2);
      q.push(p);
      p = edge(y, x, l + 1, r - (r - l - 1) % 2);
      q.push(p);
    }
  }
  memset(f, -63, sizeof(f));
  f[0][1] = 0;
  while (!q.empty()) {
    p = q.top();
    q.pop();
    int x = p.x, y = p.y, op = p.l & 1;
    if (f[op][x] >= p.l) {
      if (y == n) {
        printf("%d\n", p.l + 1);
        return 0;
      }
      f[op ^ 1][y] = max(f[op ^ 1][y], p.r + 1);
      for (int k = last[op ^ 1][y]; k; k = a[k].next)
        if (p.l + 1 <= a[k].r) q.push(edge(y, a[k].y, p.l + 1, a[k].r));
      last[op ^ 1][y] = 0;
    } else
      ins(op, x, y, p.r);
  }
  puts("-1");
  return 0;
}
