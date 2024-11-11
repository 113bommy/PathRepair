#include <bits/stdc++.h>
using namespace std;
int n, w, x, z, q, u, t, l, r, i, N, m, p, fl;
int tree[100010];
void add(int w, int tem) {
  for (int i = w; i <= N; i += i & (-i)) tree[i] += tem;
}
int fd(int w) {
  int tem = 0;
  for (int i = w; i; i -= i & (-i)) tem += tree[i];
  return tem;
}
int main() {
  scanf("%d%d", &n, &m);
  N = n;
  for (i = 1; i <= n; i++) add(i, 1);
  p = 0;
  while (m--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d", &x);
      if (x > n / 2) {
        z = n - x;
        if (!fl) {
          n = x;
          for (i = x - z + 1; i <= x; i++) {
            u = fd(2 * x - i + 1 + p) - fd(2 * x - i + p);
            add(i + p, u);
          }
        } else {
          for (i = n - x + 1; i <= n - x + z; i++) {
            q = 2 * n - 2 * x - i + 1;
            u = fd(q + p) - fd(q - 1 + p);
            add(i + p, u);
          }
          n = x;
          p += z;
        }
        fl ^= 1;
      } else {
        if (!fl) {
          n -= x;
          for (i = x + 1; i <= 2 * x; i++) {
            u = fd(2 * x - i + 1 + p) - fd(2 * x - i + p);
            add(i + p, u);
          }
          p += x;
        } else {
          for (i = n - 2 * x + 1; i <= n - x; i++) {
            q = 2 * n - 2 * x - i + 1;
            u = fd(q + p) - fd(q - 1 + p);
            add(i + p, u);
          }
          n -= x;
        }
      }
    } else {
      scanf("%d%d", &l, &r);
      l++;
      if (!fl)
        printf("%d\n", fd(r + p) - fd(l - 1 + p));
      else
        printf("%d\n", fd(n - l + 1 + p) - fd(n - r + p));
    }
  }
  return 0;
}
