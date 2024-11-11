#include <bits/stdc++.h>
using namespace std;
int f_max(int a, int b) { return a > b ? a : b; }
int f_min(int a, int b) { return a < b ? a : b; }
int f_abs(int a) { return a > 0 ? a : -a; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  int q, w, e, r;
  int n, flag, i, j, k, m;
  int x0 = 5, y0 = 5, x, y;
  while (~scanf("%d%d%d", &n, &m, &k)) {
    flag = 0;
    m -= 4;
    n -= 4;
    for (i = 0; i < k; i++) {
      scanf("%d%d", &x, &y);
      if (x >= x0 && x <= n && y >= y0 && y <= m)
        continue;
      else
        flag++;
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
