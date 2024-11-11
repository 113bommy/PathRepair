#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], dp1[100005], dp2[100005], first[100005], second[100005],
    p, t, ans = 1000000000000000005;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > p)
      t = 0;
    else
      t = p - a[i] + 1;
    p = a[i] + t;
    dp1[i] = dp1[i - 1] + t;
    first[i] = p;
  }
  p = 0;
  for (int i = n; i >= 1; i--) {
    if (a[i] > p)
      t = 0;
    else
      t = p - a[i] + 1;
    p = a[i] + t;
    dp2[i] = dp2[i + 1] + t;
    second[i] = p;
  }
  for (int i = 1; i < n; i++) {
    if (first[i] <= second[i + 1]) {
      t = second[i + 1] - first[i] + 1;
    } else
      t = 0;
    ans = min(ans, dp1[i] + dp2[i + 1]);
  }
  ans = min(ans, dp1[n]);
  ans = min(ans, dp2[1]);
  cout << ans;
}
