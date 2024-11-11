#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ta, tb, n, m, k;
  cin >> n >> m >> ta >> tb >> k;
  long long a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int j = 0; j < m; j++) cin >> b[j];
  if (k >= n || k >= m)
    cout << -1;
  else {
    long long cancel = 1, ans = -1;
    for (int i = 1; i < n; i++) {
      if (cancel > k) break;
      long long low = 0, high = m - 1, reach = a[i] + ta, index = -1;
      while (low < high) {
        long long mid = low + ((high - low) / 2);
        if (b[mid] < reach)
          low = mid + 1;
        else if (b[mid] > reach)
          high = mid;
        else {
          index = mid;
          break;
        }
      }
      if (index == -1) {
        if (b[low] >= reach) index = low;
      }
      if (index == -1) {
        ans = -1;
        break;
      } else {
        long long remaining = k - cancel, elements = m - index;
        if (remaining >= elements) {
          ans = -1;
          break;
        } else {
          long long dept = b[index + remaining];
          ans = ans = max(ans, dept + tb);
        }
      }
      cancel++;
    }
    cout << ans;
  }
  return 0;
}
