#include <bits/stdc++.h>
bool a[100000 * 2 + 1], aa[100000 + 1];
int b[100000 * 2 + 1], c[100000 * 2 + 1], h[100000 + 1], n, m, i, x, y;
int go(int k) {
  aa[k] = 1;
  int i, t, x = 0;
  for (i = h[k]; i; i = b[i])
    if (!a[i]) {
      a[i > m ? i - m : i + m] = 1;
      if (t = aa[c[i]] ? 0 : go(c[i]))
        printf("%d %d %d\n", k, c[i], t);
      else if (x)
        printf("%d %d %d\n", x, k, c[i]), x = 0;
      else
        x = c[i];
    }
  return x;
}
int main() {
  scanf("%d%d", &n, &m);
  if (m & 1) {
    puts("No solution");
    return 0;
  }
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    b[i] = h[x];
    c[i] = y;
    h[x] = i;
    b[i + m] = h[y];
    c[i + m] = x;
    h[y] = i + m;
  }
  go(1);
  return 0;
}
