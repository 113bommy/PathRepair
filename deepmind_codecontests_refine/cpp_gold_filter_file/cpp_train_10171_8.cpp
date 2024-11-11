#include <bits/stdc++.h>
using namespace std;
int n, m;
long double mem[1005][1005];
long double dp(int x, int y) {
  if (mem[x][y] > 0) return mem[x][y];
  if (!x) return mem[0][y] = 1.0 / (y + 1);
  if (!y) return mem[x][0] = 1;
  long double mn = dp(y, x - 1) / (dp(y, x - 1) + 1.0 / (y + 1));
  return mem[x][y] = mn * y / (y + 1) * (1 - dp(y - 1, x)) + 1 - mn;
}
int main() {
  scanf("%d%d", &n, &m), printf("%.9Lf %.9Lf", dp(n, m), 1 - dp(n, m));
}
