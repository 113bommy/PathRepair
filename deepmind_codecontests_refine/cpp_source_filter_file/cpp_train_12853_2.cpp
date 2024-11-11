#include <bits/stdc++.h>
using namespace std;
long long bin_pow(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long t = bin_pow(a, b / 2);
    return t * t % 1000000007;
  } else
    return a * bin_pow(a, b - 1) % 1000000007;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t = 1, n, m, k = 0, x = 0, y = 0, z = 0, sum = 0, l = 0, r = 0,
            ans = 0, mn = LLONG_MAX, mx = LLONG_MIN;
  cin >> n >> m;
  vector<string> s(n), v(n, ""), f(n);
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    z = 1;
    for (int j = 0; j < n; j++) f[j] = v[j] + s[j][i];
    for (int j = 1; j < n; j++) {
      if (f[j] < f[j - 1]) z = 0;
    }
    if (z == 1) {
      for (int j = 0; j < n; j++) v[j] = f[j];
    } else
      ans++;
  }
  cout << ans;
  return 0;
}
