#include <bits/stdc++.h>
const int INF = 2147483647;
int main() {
  int n, m, i, j, a, b, x[2], y[2], ans = INF;
  scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &a, &b);
  x[0] = x[1] = y[0] = y[1] = -1;
  if ((i - 1) % a == 0) x[0] = (i - 1) / a;
  if ((j - 1) % b == 0) y[0] = (j - 1) / b;
  if ((n - i) % a == 0) x[1] = (n - i) / a;
  if ((m - j) % b == 0) y[1] = (m - j) / b;
  for (int k = 0; k < 2; k++)
    for (int l = 0; l < 2; l++)
      if (x[k] != -1 && y[l] != -1 && x[k] % 2 == y[l] % 2 &&
          !(x[k] != y[l] &&
            ((i + a > n && i - a < 1) || (j + b > n && j - b < 1))))
        ans = std::min(ans, std::max(x[k], y[l]));
  if (ans == INF)
    puts("Poor Inna and pony!");
  else
    printf("%d\n", ans);
  return 0;
}
