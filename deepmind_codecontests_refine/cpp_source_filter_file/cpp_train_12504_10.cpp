#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long n, k, mx = 0;
  long long a[222222];
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    a[x]++;
    mx = max(mx, x);
  }
  long long t = mx;
  long long ans = 0;
  for (long long i = mx; i >= 0; --i) {
    if (a[i] == n) break;
    if (t < a[i]) {
      ans++;
      t = k;
    }
    t -= a[i];
    a[i - 1] += a[i];
  }
  if (t != k) ans++;
  cout << ans;
  return 0;
}
