#include <bits/stdc++.h>
using namespace std;
int n, m, x[10], y[10];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &y[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (x[i] == y[j]) {
        printf("%d\n", x[i]);
        break;
      }
}
