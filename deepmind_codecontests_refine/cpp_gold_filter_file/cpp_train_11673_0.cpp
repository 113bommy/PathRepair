#include <bits/stdc++.h>
using namespace std;
int n, m, h, s[1001], sum = 0, a, b, c, d;
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= m; i++) {
    scanf("%d", s + i);
    sum += s[i];
  }
  double ans = 1;
  a = sum - s[h];
  b = sum - 1 - (n - 1);
  c = sum - 1;
  d = a - (n - 1);
  if (sum < n)
    puts("-1.0");
  else if (sum - s[h] + 1 < n)
    puts("1.0");
  else {
    while (a > 1 || b > 1 || c > 1 || d > 1) {
      if (a > 1) {
        ans *= a--;
      } else if (b > 1) {
        ans *= b--;
      } else {
        while (c > 1) ans /= c--;
        while (d > 1) ans /= d--;
      }
      while (ans > 1) {
        if (c > 1) {
          ans /= c--;
        } else if (d > 1) {
          ans /= d--;
        }
      }
    }
    printf("%f\n", 1 - ans);
  }
  return 0;
}
