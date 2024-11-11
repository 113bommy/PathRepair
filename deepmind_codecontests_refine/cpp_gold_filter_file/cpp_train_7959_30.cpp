#include <bits/stdc++.h>
#pragma comment(linker, "/stack:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
int f_max(int a, int b) { return a > b ? a : b; }
int f_min(int a, int b) { return a < b ? a : b; }
int f_abs(int a) { return a > 0 ? a : -a; }
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int n, m;
int u, d, l, r;
int x, y;
int main() {
  int q, w, e;
  int i, j, k;
  int ans, len;
  while (~scanf("%d%d", &n, &m)) {
    len = 0x7fffffff;
    r = u = -0x7fffffff;
    l = d = 0x7fffffff;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
      scanf("%d%d", &x, &y);
      u = f_max(u, y - x);
      d = f_min(d, y - x);
      l = f_min(l, x + y);
      r = f_max(r, x + y);
    }
    scanf("%d", &m);
    int mm;
    for (i = 1; i <= m; i++) {
      scanf("%d%d", &x, &y);
      mm = 0;
      mm = f_max(mm, u - (y - x));
      mm = f_max(mm, (y - x) - d);
      mm = f_max(mm, r - (x + y));
      mm = f_max(mm, (x + y) - l);
      if (mm < len) {
        ans = i;
        len = mm;
      }
    }
    printf("%d\n%d\n", len, ans);
  }
  return 0;
}
