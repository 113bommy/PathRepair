#include <bits/stdc++.h>
using namespace std;
int const MOD = 1e9 + 7;
long long const oo = 2e18;
int const N = 1e7 + 100;
int const M = 1e5 + 100;
int n, m, g[110][110];
int calc(int num) {
  int res = n;
  if (num == n && num % 2 == 0)
    res = min(res, calc(n / 2));
  else if (num == n)
    return n;
  else {
    bool f = true;
    for (int i = 0, j = 2 * num - 1; i < num && j >= num; ++i, --j) {
      for (int k = 0; k < m; ++k)
        if (g[i][k] != g[j][k]) {
          f = false;
          break;
        }
      if (!f) break;
    }
    if (f) res = min(res, num);
    if (num % 2 == 0) res = min(res, calc(num / 2));
  }
  return res;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &g[i][j]);
    }
  }
  printf("%d\n", calc(n));
  return 0;
}
