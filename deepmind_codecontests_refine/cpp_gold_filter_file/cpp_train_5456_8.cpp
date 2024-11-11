#include <bits/stdc++.h>
using namespace std;
double a[2008];
int main() {
  int cou = 0, n, i;
  double ans = 0, tmp;
  scanf("%d", &n);
  n *= 2;
  for (i = 0; i < n; i++) {
    scanf("%lf", &tmp);
    if (tmp - (int)tmp < 1e-8)
      cou++;
    else
      ans += tmp - (int)tmp - 0.5;
  }
  ans = abs(ans);
  if (cou % 2 == 1) {
    ans -= 0.5;
    ans = abs(ans);
    cou--;
  }
  if (cou > 0) {
    if (ans - cou * 0.5 >= 0)
      ans -= cou * 0.5;
    else {
      cou -= (int)(ans / 0.5);
      ans = ans - 0.5 * (int)(ans / 0.5);
      if (cou % 2 == 1) {
        ans = abs(ans - 0.5);
      }
    }
  }
  printf("%.3lf", ans);
  return 0;
}
