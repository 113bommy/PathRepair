#include <bits/stdc++.h>
using namespace std;
struct {
  template <typename T>
  inline operator T() {
    T x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c)) (c == '-') && (f = -1), c = getchar();
    while (isdigit(c)) x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return f * x;
  }
} gi;
char s[10];
int n, h;
int main() {
  scanf("%s", s + 1);
  n = gi, h = gi;
  if (s[1] == 'B') return printf("%d\n", n), 0;
  double ans = n, mi = 2, t;
  for (int i = t = 1; i <= h; i++, mi *= 2)
    for (int j = 1; j <= n; j++) {
      ans += (n - j) * 1.0 / (mi * mi) * t *
             (mi - mi / 2.0 * (1.0 + (j - 1) / (mi - 1)));
      t *= (1.0 - 1.0 / mi);
    }
  printf("%.12lf\n", ans);
}
