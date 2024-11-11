#include <bits/stdc++.h>
using namespace std;
int a, b, c, n, m, T, x[1000];
int main() {
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d%d", &n, &m);
    int maxx = 0;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &x[i]);
      if (maxx < x[i] - x[i - 1] - 1) maxx = x[i] - x[i - 1] - 1;
    }
    if (maxx % 2 == 0)
      maxx = maxx / 2 + 1;
    else
      maxx = maxx / 2 + 2;
    maxx = max(maxx, max(n - x[m] + 1, x[1]));
    printf("%d\n", maxx);
  }
}
