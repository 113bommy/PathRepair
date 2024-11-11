#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(1e5) + 123;
const long long inf = (long long)(1e18);
const int INF = (int)(1e9);
long long ans, cnt, n, a[maxn];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], cnt += a[i];
  cnt = cnt / n;
  for (int i = 1; i < n; ++i) {
    if (a[i] > cnt) {
      ans = ans + a[i] - cnt;
      a[i + 1] += cnt - a[i];
    } else if (a[i] < cnt) {
      ans = ans + cnt - a[i];
      a[i + 1] += a[i] - cnt;
    }
    a[i] = cnt;
  }
  cout << ans;
  return 0;
}
