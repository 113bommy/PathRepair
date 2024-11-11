#include <bits/stdc++.h>
using namespace std;
int a[5];
int main() {
  int n;
  while (~scanf("%d", &n)) {
    memset(a, 0, sizeof(a));
    int tmp;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &tmp);
      a[tmp]++;
    }
    int ans = 0;
    if (a[1] == a[2])
      ans = a[1];
    else if (a[1] > a[2]) {
      ans = a[2];
      tmp = a[1] - a[2];
      if (tmp % 3 == 0)
        ans += tmp / 3 * 2;
      else {
        if (tmp % 3 == 1) {
          if (a[2] + a[3] + tmp / 3 >= 1)
            ans += tmp / 3 * 2 + 1;
          else if (a[4] >= 2)
            ans += 2;
          else
            ans = -1;
        } else {
          if (a[2] + a[3] + tmp / 3 >= 2)
            ans += tmp / 3 * 2 + 2;
          else if (a[4] >= 1)
            ans += tmp / 3 * 2 + 2;
          else
            ans = -1;
        }
      }
    } else {
      ans = a[1];
      tmp = a[2] - a[1];
      if (tmp % 3 == 0)
        ans += tmp / 3 * 2;
      else {
        if (tmp % 3 == 1) {
          if (a[4] >= 1)
            ans += tmp / 3 * 2 + 1;
          else if (a[1] + a[3] + tmp / 3 * 2 >= 1)
            ans += tmp / 3 * 2 + 2;
          else
            ans = -1;
        } else
          ans += tmp / 3 * 2 + 2;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
