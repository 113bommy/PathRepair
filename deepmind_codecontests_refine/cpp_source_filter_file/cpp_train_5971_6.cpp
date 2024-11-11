#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    m = min(m, n / 2);
    int l = 0, r = n, ans;
    while (l <= r) {
      int mid = l + r >> 1;
      long long res = (long long)mid * m, x = n, y = 1;
      for (int i = 0; i <= mid && res >= 0 && x; i++) {
        int k = min(x, y);
        x -= k;
        res -= k * i;
        y = y * (mid - i) / (i + 1);
      }
      if (res < 0 || x)
        l = mid + 1;
      else {
        r = mid - 1;
        ans = mid;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
