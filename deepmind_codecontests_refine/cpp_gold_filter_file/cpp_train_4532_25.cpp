#include <bits/stdc++.h>
using namespace std;
int r, c, n, m, x[100], y[100], ans;
int main() {
  scanf("%d%d%d%d", &r, &c, &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= c; j++)
      for (int ii = i; ii <= r; ii++)
        for (int jj = j; jj <= c; jj++) {
          int tmp = 0;
          for (int k = 1; k <= n; k++)
            if (i <= x[k] && x[k] <= ii && j <= y[k] && y[k] <= jj) tmp++;
          if (tmp >= m) ans++;
        }
  printf("%d", ans);
}
