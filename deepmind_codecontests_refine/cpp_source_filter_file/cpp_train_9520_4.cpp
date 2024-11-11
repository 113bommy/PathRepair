#include <bits/stdc++.h>
using namespace std;
const int maxd = 100000;
double a[101], ans, p, s;
int n, i, j;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  ans = 0;
  p = 1;
  s = 0;
  if (a[n - 1] > 0.5)
    ans = a[n - 1];
  else
    for (i = n - 2; i >= 0; i--) {
      p *= (1 - a[i]);
      s += a[i] / (1 - a[i]);
      if (ans < p * s)
        ans = p * s;
      else
        break;
    }
  printf("%.12f", ans);
}
