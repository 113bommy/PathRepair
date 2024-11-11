#include <bits/stdc++.h>
using namespace std;
long long cnt(long long s, long long k) {
  if (s == k) return 0;
  long long t = s / k, c = s % k + 1;
  t++;
  return c * ((t - 1) / 2 + 1) + (k - c) * (t / 2) - 1;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long T, s, n, k;
  cin >> T;
  while (T--) {
    cin >> s >> n >> k;
    cout << (cnt(s, k) >= n ? "NO" : "YES") << '\n';
  }
  return 0;
}
