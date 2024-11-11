#include <bits/stdc++.h>
using namespace std;
int n, x[5], y[5];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
  sort(x + 1, x + n + 1);
  sort(y + 1, y + n + 1);
  if (x[1] == x[n] || y[1] == y[n] || n == 1)
    printf("-1");
  else
    printf("%d", (x[n] - x[1]) * (y[n] - y[1]));
}
