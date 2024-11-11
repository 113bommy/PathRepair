#include <bits/stdc++.h>
using namespace std;
int n, m, q[100001], p[100001], k[100001];
int to(int x) {
  for (int i = 1; i <= 320; i++) x = p[x];
  return x;
}
int main() {
  int op, x, y;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]), q[p[i]] = i;
  for (int i = 1; i <= n; i++) k[i] = to(i);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      swap(p[x], p[y]);
      swap(q[x], q[y]);
      int tx = to(x), ty = to(y);
      for (int i = 1; i <= 320; i++)
        k[x] = tx, k[y] = ty, x = q[x], y = q[y], tx = q[tx], ty = q[ty];
    } else {
      while (y >= 320) y -= 320, x = k[x];
      while (y) y--, x = p[x];
      printf("%d\n", x);
    }
  }
  return 0;
}
