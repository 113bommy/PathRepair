#include <bits/stdc++.h>
using namespace std;
int n, a[10], ans;
int main() {
  scanf("%d", &n);
  int t;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    a[t]++;
  }
  if (a[1] >= a[2]) {
    a[1] -= a[2];
    a[3] += a[2];
    ans += a[2];
    a[2] = 0;
  } else {
    a[2] -= a[1];
    a[3] += a[1];
    ans += a[1];
    a[1] = 0;
  }
  a[3] += a[1] / 3;
  ans += 2 * (a[1] / 3);
  a[1] %= 3;
  a[3] += 2 * a[2] / 3;
  ans += 2 * (a[2] / 3);
  a[2] %= 3;
  if (a[1]) {
    if (a[1] == 1)
      if (a[3]) {
        ans++;
        a[1] = 0;
      } else if (a[4] > 1) {
        ans += 2;
        a[1] = 0;
      }
    if (a[1] == 2)
      if (a[3] > 1) {
        ans += 2;
        a[1] = 0;
      } else if (a[4]) {
        ans += 2;
        a[1] = 0;
      }
  }
  if (a[2]) {
    if (a[2] == 1)
      if (a[4]) {
        ans++;
        a[2] = 0;
      } else if (a[3] > 1) {
        ans += 2;
        a[2] = 0;
      }
    if (a[2] == 2) {
      ans += 2;
      a[2] = 0;
    }
  }
  if (a[1] == 0 && a[2] == 0)
    printf("%d", ans);
  else
    printf("-1");
  return 0;
}
