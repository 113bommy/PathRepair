#include <bits/stdc++.h>
using namespace std;
inline long long read(long long num = 0, char c = 0) {
  while (c > '9' || c < '0') c = getchar();
  while (c >= '0' && c <= '9') num = num * 10 + c - 48, c = getchar();
  return num;
}
struct node {
  int x, y, val, num;
  void in() { x = read(), y = read(), val = read(); }
} p[500010];
int f[2005], n, m, q, l, r;
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
bool cmp(node a, node b) { return a.val > b.val; }
int work() {
  for (register int i = 1; i <= m; ++i) {
    if (p[i].x >= l && p[i].y <= r) {
      if (find(p[i].x) == find(p[i].y)) {
        return p[i].val;
      } else {
        f[find(p[i].x + n)] = f[find(p[i].y)];
        f[find(p[i].y + n)] = f[find(p[i].x)];
      }
    }
  }
  return -1;
}
int main() {
  n = read(), m = read(), q = read();
  for (register int i = 1; i <= m; ++i) p[i].in(), p[i].num = i;
  sort(p + 1, p + 1 + m, cmp);
  for (register int i = 1; i <= q; ++i) {
    l = read(), r = read();
    for (register int i = 1; i <= 2 * n; ++i) f[i] = i;
    printf("%d\n", work());
  }
  return 0;
}
