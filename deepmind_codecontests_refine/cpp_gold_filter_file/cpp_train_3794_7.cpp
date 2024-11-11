#include <bits/stdc++.h>
using namespace std;
long long c[65][65], m, k;
long long cal(long long x) {
  long long i, j, res = 0, num = 0;
  for (i = 62; i >= 0; i--) {
    if (x & (1LL << i)) {
      if (k - num >= 0)
        res += c[i][k - num];
      else
        break;
      num++;
    }
  }
  return res;
}
int main() {
  long long i, j, le, ri, mid, cnt, ans;
  for (i = 0; i <= 64; i++) c[i][0] = 1;
  for (i = 1; i <= 64; i++) {
    for (j = 1; j <= i; j++) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
  }
  while (cin >> m >> k) {
    le = 1;
    ri = 1LL << 62;
    while (le <= ri) {
      mid = (le + ri) >> 1;
      cnt = cal(2 * mid) - cal(mid);
      if (m <= cnt) {
        ans = mid;
        ri = mid - 1;
      } else
        le = mid + 1;
    }
    cout << ans << endl;
  }
}
