#include <bits/stdc++.h>
int main() {
  int n, m, a, b, p, q;
  double w;
  scanf("%d %lf %d", &n, &w, &m);
  int flag = 1;
  for (int i = 1; i <= m - 2; i++) {
    if ((i * n) % m != 0 && ((i * n) / m == ((i + 1) * n) / m)) {
      flag = 0;
      break;
    }
  }
  if (!flag)
    printf("NO");
  else {
    printf("YES\n");
    for (int i = 0; i < m; i++) {
      a = i * n;
      b = (i + 1) * n;
      p = a / m;
      q = b / m;
      if (q * m == b) q--;
      if (p == q)
        printf("%d %.6lf\n", p + 1, (w * n) / m);
      else {
        printf("%d %.6lf ", p + 1, (w * ((p + 1) * m - a)) / m);
        for (int j = p + 1; j < q; j++) {
          printf("%d %.6lf ", j + 1, w);
        }
        printf("%d %.6lf\n", q + 1, (w * (b - q * m)) / m);
      }
    }
  }
}
