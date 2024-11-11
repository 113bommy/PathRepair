#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, k;
long long a[2001], c[2001];
long long lpow(long long a, int e) {
  if (e == 0) return 1;
  if (e % 2) {
    long long ret = lpow(a, e / 2);
    return ((ret * ret) % mod * a) % mod;
  } else {
    long long ret = lpow(a, e / 2);
    return (ret * ret) % mod;
  }
}
long long solve(long long a, long long b) {
  long long ret = 1;
  for (int i = 1; i <= b; ++i) {
    ret = (ret * (a - b + i)) % mod;
    ret = (ret * lpow(i, mod - 2)) % mod;
  }
  return ret;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (k == 0) {
    for (int i = 0; i < n; ++i) cout << a[i] << " ";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    c[i] = solve(k - 1 + i, i);
  }
  for (int i = 0; i < n; ++i) {
    long long ans = 0;
    for (int j = 0; j <= i; ++j) ans = (ans + (c[j] * a[i - j]) % mod) % mod;
    cout << ans << " ";
  }
  return 0;
}
