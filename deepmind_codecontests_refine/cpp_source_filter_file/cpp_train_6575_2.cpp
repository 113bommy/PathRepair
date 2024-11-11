#include <bits/stdc++.h>
using namespace std;
inline long long add(long long a, long long b) {
  return ((a % 1000000007) + (b % 1000000007)) % 1000000007;
}
inline long long mul(long long a, long long b) {
  return ((a % 1000000007) * (b % 1000000007)) % 1000000007;
}
inline long long sub(long long a, long long b) {
  return ((a % 1000000007) - (b % 1000000007) + 1000000007) % 1000000007;
}
void solve() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  vector<long long> v;
  for (long long i = n - 1; i >= 0; i--) {
    ans += a[i];
    v.push_back(ans);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ;
  for (long long i = 0; i < k - 1; i++) ans += v[i];
  cout << ans << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  for (long long a = 0; a < t; a++) {
    solve();
  }
}
