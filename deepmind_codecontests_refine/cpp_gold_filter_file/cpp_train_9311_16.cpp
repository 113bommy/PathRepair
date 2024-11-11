#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5 + 5;
const long long mod = 1000000007;
long long t;
long long i, j;
long long n, m, k;
long long x, y;
long long a[maxn], s[maxn], e[maxn];
long long ans = -2;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  s[1] = 1;
  e[n] = 1;
  for (i = 2; i <= n; i++) {
    if (a[i] > a[i - 1])
      s[i] = s[i - 1] + 1;
    else
      s[i] = 1;
  }
  for (i = n - 1; i >= 1; i--) {
    if (a[i] < a[i + 1])
      e[i] = e[i + 1] + 1;
    else
      e[i] = 1;
  }
  for (i = 1; i <= n; i++) {
    if (i == 1)
      ans = max(ans, e[i + 1] + 1);
    else {
      if (s[i - 1] + e[i + 1] + 1 > ans && a[i + 1] - a[i - 1] > 1)
        ans = max(ans, s[i - 1] + e[i + 1] + 1);
      else {
        ans = max(ans, s[i - 1] + 1);
        ans = max(ans, e[i + 1] + 1);
      }
    }
  }
  cout << max(ans, *max_element(s + 1, s + n + 1));
}
