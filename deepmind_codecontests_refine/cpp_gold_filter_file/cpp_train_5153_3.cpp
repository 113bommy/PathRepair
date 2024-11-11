#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(7);
  size_t n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (size_t i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<long long, long long> f, s;
  for (size_t i = 2; i < n; ++i) {
    ++s[a[i]];
  }
  ++f[a[0]];
  long long ans = 0;
  for (size_t i = 1; i + 1 < n; ++i) {
    if (a[i] % k == 0) {
      ans += f[a[i] / k] * s[a[i] * k];
    }
    ++f[a[i]];
    --s[a[i + 1]];
  }
  cout << ans << "\n";
  return 0;
}
