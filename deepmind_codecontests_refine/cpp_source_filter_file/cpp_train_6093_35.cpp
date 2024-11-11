#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int M = 1005;
const int md = 1000000007;
long long n, k, i, ans, h, e, d[N], a[N], p[N];
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  long long pruf = 0;
  long long step = 1;
  for (i = 0; i <= n; ++i) cin >> a[i], pruf += a[i] * step, step *= 2;
  p[n] = a[n];
  for (i = n - 1; i >= 0; --i) {
    p[i] = 2 * p[i + 1] + a[i];
    if (abs(p[i]) > 2 * k) {
      h = i;
      break;
    }
  }
  e = n + 1;
  if (abs(a[0]) % 2 == 0) {
    d[1] = -a[0] / 2;
    for (i = 2; i <= n; ++i) {
      if (abs(d[i - 1] - a[i - 1]) % 2 == 1) {
        e = i;
        break;
      }
      d[i] = (d[i - 1] - a[i - 1]) / 2;
    }
  } else
    e = 1;
  for (i = h; i <= e - 1; ++i) {
    if (i == n) {
      if (abs(d[i] <= k && d[i] != 0)) ++ans;
      break;
    }
    if (abs(d[i] - p[i] + a[i]) <= k) ++ans;
  }
  cout << ans;
}
