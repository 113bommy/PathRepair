#include <bits/stdc++.h>
using namespace std;
const long long FASTIO = []() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}();
signed main() {
  long long n;
  cin >> n;
  set<long long> b, c;
  vector<long long> a(n + 2);
  map<long long, long long> m;
  a[0] = 1e9;
  long long f = 0;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    b.insert(a[i]);
    m[a[i]]++;
    if (m[a[i]] >= 2) f++;
  }
  a[n + 1] = 1e9;
  if (f == 0) {
    cout << 0;
    return 0;
  } else if (f == 1) {
    cout << 1;
    return 0;
  }
  long long ans = 1e9;
  for (long long l = 1; l < n; l++) {
    c = b;
    m[a[l]]--;
    if (m[a[l]] == 0) c.erase(a[l]);
    for (long long r = l + 1; r <= n; r++) {
      m[a[r]]--;
      if (m[a[r]] == 0) c.erase(a[r]);
      if (c.size() == l - 1 + n - r) {
        ans = min(ans, r - l + 1);
      }
    }
    for (long long i = n; i >= l; i--) {
      m[a[i]]++;
    }
  }
  if (ans == 1e9) ans = 1;
  cout << ans;
}
