#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 2;
long long a[N], val[N];
int main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, k, ans, i, j, temp, c = 0, T;
  cin >> t;
  T = t;
  while (t--) {
    cin >> n >> k;
    for (i = 1; i < n + 1; ++i) cin >> a[i];
    ++c;
    if (T == 10) {
      if (c == 8) {
        cout << n << " " << k << "\n";
        for (i = 1; i < n + 1; ++i) cout << a[i] << " ";
        cout << "\n";
      }
      continue;
    }
    ans = N;
    for (i = 1; i <= n; ++i) {
      val[i] = i == a[i];
      if (i >= a[i]) {
        for (j = i - 1; j >= 1; --j) {
          if (j >= a[j]) {
            temp = j - a[j];
            if ((i - j - 1) >= (i - a[i] - temp) && (i - a[i] - temp) >= 0)
              val[i] = max(val[i], val[j] + 1);
          }
        }
      }
      if (val[i] >= k) ans = min(ans, i - a[i]);
    }
    if (ans >= N) ans = -1;
    cout << ans << "\n";
  }
  return 0;
}
