#include <bits/stdc++.h>
using namespace std;
long long int t, n, m, q, l, r;
pair<long long int, long long int> p[100005];
int main() {
  long long int i, j, k, a, b, c, ans, mid, e, f;
  cin >> n;
  m = -1;
  for (i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
    if (p[i].first > m) {
      m = p[i].first;
    }
  }
  ans = m;
  for (mid = m;; mid++) {
    e = 0;
    for (i = 1; i <= n; i++) {
      a = mid - p[i].first;
      b = p[i].second;
      if (a < 0) {
        break;
      } else {
        c = 1;
        j = 0;
        while (j <= a) {
          if (c >= b) {
            e++;
            break;
          }
          j++;
          c = c * 4;
        }
      }
    }
    if (e == n) {
      ans = mid;
      break;
    }
  }
  cout << ans;
  return 0;
}
