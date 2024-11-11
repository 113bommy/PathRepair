#include <bits/stdc++.h>
using namespace std;
int p[100007], f[100007], k[100007];
int main() {
  int n, q, t, x, y;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) f[p[i]] = i;
  for (int i = 1; i <= n; i++) {
    int x = i;
    for (int j = 1; j <= 100; j++) x = p[x];
    k[i] = x;
  }
  while (q--) {
    scanf("%d%d%d", &t, &x, &y);
    if (t == 1) {
      swap(p[x], p[y]);
      swap(f[p[x]], f[p[y]]);
      int a = x;
      for (int i = 1; i <= 100; i++) a = p[a];
      for (int i = 1; i <= 100; i++) {
        k[x] = a;
        x = f[x];
        a = f[a];
      }
      a = y;
      for (int i = 1; i <= 100; i++) a = p[a];
      for (int i = 1; i <= 100; i++) {
        k[y] = a;
        y = f[y];
        a = f[a];
      }
    } else {
      while (y >= 100) {
        x = k[x];
        y -= 100;
      }
      while (y) {
        x = p[x];
        y--;
      }
      printf("%d\n", x);
    }
  }
}
