#include <bits/stdc++.h>
int f[105], n, x, g[105], a, b, now;
bool p[105];
int main() {
  scanf("%d%d", &n, &x);
  memset(f, 0, sizeof(f));
  memset(p, 0, sizeof(p));
  for (int i = 1; i <= n; i++) {
    scanf("%d", &g[i]);
    f[g[i]] = i;
  }
  int s = 0;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (g[i]) continue;
    a = 0, b = 0;
    now = i;
    do {
      a++;
      if (now == x) b = a;
      now = f[now];
    } while (now);
    if (b == 0) {
      for (int j = n; j >= 0; j--)
        if (p[j]) p[j + a] = 1;
    } else
      s = b;
  }
  for (int i = 0; i <= n; i++)
    if (p[i]) {
      printf("%d\n", i + s);
    }
  return 0;
}
