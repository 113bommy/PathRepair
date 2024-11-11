#include <bits/stdc++.h>
using namespace std;
int g[1000005];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    g[x]++;
    g[y]++;
  }
  if (n < 3) {
    puts("0");
  } else {
    long long ans = n;
    long long ansx = 0;
    ans = ans * (ans - 1) * (ans - 2) / 6;
    for (int i = 1; i <= n; i++) {
      long long x = g[i];
      long long y = n;
      x = (y - 1 - x) * x;
      ansx = ansx + x;
    }
    ansx /= 2;
    ans = ans - ansx;
    printf("%I64d\n", ans);
  }
  return 0;
}
