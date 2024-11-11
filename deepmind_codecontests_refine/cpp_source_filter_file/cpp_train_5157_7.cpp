#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[1002][2];
  for (int i = 0; i < n; i++) scanf("%d %d", &a[i][0], &a[i][1]);
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (a[i][0] - a[i - 1][0] == 0) {
      if (a[i][1] - a[i - 1][1] > 0) {
        if (a[i + 1][0] - a[i][0] < 0) ans++;
      } else {
        if (a[i + 1][0] - a[i][0] > 0) ans++;
      }
    } else if (a[i][0] - a[i - 1][0] > 0) {
      if (a[i + 1][1] - a[i][1] > 0) ans++;
    } else {
      if (a[i + 1][1] - a[i][1] < 0) ans++;
    }
  }
  printf("%d\n", ans);
  return 0;
}
