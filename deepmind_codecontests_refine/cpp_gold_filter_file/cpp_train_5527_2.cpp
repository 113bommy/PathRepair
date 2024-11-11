#include <bits/stdc++.h>
using namespace std;
int res[100005], a[100005];
int main() {
  std::ios::sync_with_stdio(false);
  int n, m, i, ans = 0, val1 = 0, val2, val, prev;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans = a[0];
  res[0] = a[0];
  for (i = 1; i < n; i++) {
    res[i] = res[i - 1];
    if (i % 2 == 0) {
      ans += a[i] - a[i - 1];
      res[i] += a[i] - a[i - 1];
    }
  }
  if (n % 2 == 0) {
    val1 = m - a[n - 1];
    ans += m - a[n - 1];
  }
  prev = 0;
  a[n] = m;
  res[n] = ans;
  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      if (a[i] - prev > 1) {
        val = res[n - 1] - res[i] + val1;
        val = m - a[i] - val;
        val2 = res[i];
        val2--;
        val2 += val;
        ans = max(ans, val2);
      }
      if (a[i] + 1 < a[i + 1]) {
        val = res[n - 1] - res[i + 1] + val1;
        val = m - a[i + 1] - val;
        val2 = res[i];
        val2 += a[i + 1] - a[i] - 1;
        val2 += val;
        ans = max(ans, val2);
      }
    }
    prev = a[i];
  }
  cout << ans << endl;
}
