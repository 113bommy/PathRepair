#include <bits/stdc++.h>
using namespace std;
int a[200001], n;
int main() {
  long long k, s = 0, h = 0;
  cin >> n >> k;
  int p = n, q = 0, ans = 0;
  for (int i = 0; i <= n; i++) cin >> a[i];
  while (abs(s = s * 2 + a[p--]) <= 3 * k && p >= 0)
    ;
  while (q <= p && (h = h / 2 + a[q]) % 2 != 1) q++;
  s += h / 2;
  while (q > p && s != 0 && q <= n) {
    if (q == n && s == a[n]) break;
    if (abs(a[q++] - s) <= k) ans++;
    if (s % 2) break;
    s /= 2;
  }
  cout << ans << endl;
  return 0;
}
