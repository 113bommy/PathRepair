#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
const long long oo = 1ll << 61;
int nx[N], n, m;
long long a[N], k;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = n; i; i--)
    if (a[i] != 1)
      nx[i] = i + 1;
    else if (i < n && a[i + 1] == 1)
      nx[i] = nx[i + 1];
    else
      nx[i] = i + 1;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    long long p = 1, s = 0;
    for (int j = 1; j <= n; j = nx[j])
      if (a[j] == 1) {
        long long len = nx[j] - j;
        if (p % k == 0) {
          long long x = p / k - s;
          if (x >= 1 && x <= len) ans++;
        }
        s += len;
      } else {
        if (p > oo / a[j]) break;
        p *= a[j];
        s += a[j];
        if (p % k == 0 && p / k == s) ans++;
      }
  }
  cout << ans << endl;
  return 0;
}
