#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt3, cnt4, ans = -1, ans1, q;
  scanf("%d", &n);
  int a[4] = {0, 0, 0, 0}, b[4];
  for (int i = 0; i < n; i++) {
    scanf("%d", &q);
    if (q > 0) a[q - 1]++;
  }
  int s = a[0] * 1 + a[1] * 2 + a[2] * 3 + a[3] * 4;
  for (int i = 0; i <= s / 4; i++)
    if ((s - i * 4) % 3 == 0) {
      cnt3 = (s - i * 4) / 3;
      cnt4 = i;
      for (int i = 0; i < 4; i++) b[i] = a[i];
      if (cnt4 >= b[3]) {
        cnt4 -= b[3];
        b[3] = 0;
      } else {
        b[3] -= cnt4;
        cnt4 = 0;
      }
      if (cnt3 >= b[2]) {
        cnt3 -= b[2];
        b[2] = 0;
      } else {
        b[2] -= cnt3;
        cnt3 = 0;
      }
      if (cnt3 && cnt4)
        ans1 = cnt3 * 3 + cnt4 * 4 - min(cnt3 + cnt4, b[1]) * 2 -
               min(cnt3 + cnt4 - min(cnt3 + cnt4, b[1]), b[0]) * 1;
      else if (cnt3)
        ans1 = cnt3 * 3 - min(cnt3, b[3]) * 3 -
               min(cnt3 - min(cnt3, b[3]), b[1]) * 2 -
               min(cnt3 - min(cnt3, b[3]) - min(cnt3 - min(cnt3, b[3]), b[1]),
                   b[0]) *
                   1;
      else
        ans1 = cnt4 * 4 - min(cnt4, b[2]) * 3 -
               min(cnt4 - min(cnt4, b[2]), b[1]) * 2 -
               min(cnt4 - min(cnt4, b[2]) - min(cnt4 - min(cnt4, b[2]), b[1]),
                   b[0]) *
                   1;
      if (ans == -1 || ans1 < ans) ans = ans1;
    }
  printf("%d", ans);
  return 0;
}
