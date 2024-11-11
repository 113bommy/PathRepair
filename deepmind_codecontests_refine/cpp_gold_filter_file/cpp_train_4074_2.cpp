#include <bits/stdc++.h>
using namespace std;
int a[500007];
int main() {
  int T;
  scanf("%d", &T);
  for (auto i_test = (1); i_test <= (T); ++i_test) {
    int n;
    scanf("%d", &n);
    int ans = 1000000007;
    for (auto i = (1); i <= (7); ++i) scanf("%d", &a[i]);
    int sum = 0;
    for (auto i = (1); i <= (7); ++i) sum += a[i];
    for (auto i = (1); i <= (7); ++i) {
      for (auto j = (1); j <= (7); ++j) {
        int n_ = n;
        for (auto k = (i); k <= (j); ++k) n_ -= a[k];
        if (n_ == 0) ans = min(ans, j - i + 1);
      }
    }
    for (auto i = (1); i <= (7); ++i) {
      for (auto j = (1); j <= (7); ++j) {
        if (a[i] && a[j]) {
          int n_ = n;
          for (auto k = (i); k <= (7); ++k) n_ -= a[k];
          for (auto k = (1); k <= (j); ++k) n_ -= a[k];
          if (n_ % sum == 0) {
            int res = (n_ / sum) * 7;
            ans = min(ans, res + (7 - i + 1) + j);
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
