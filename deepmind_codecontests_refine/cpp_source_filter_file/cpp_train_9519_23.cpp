#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, d, n, m, k;
  scanf("%d", &c);
  scanf("%d", &d);
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  int g = n * m - k, ans = 0;
  while (g) {
    int a = g / n;
    int c1 = c * a;
    int c2 = d * a * n;
    if (a == 0) {
      c1 = c;
      c2 = g * d;
      g = 0, ans += min(c1, c2);
    } else
      g -= (a * n), ans += min(c1, c2);
  }
  cout << ans << endl;
}
