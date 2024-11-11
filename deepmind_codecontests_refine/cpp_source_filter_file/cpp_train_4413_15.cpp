#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, i, s, t;
  cin >> n;
  vector<long long> v(n);
  for (i = 0; i < n; i++) cin >> v[i];
  cin >> s >> t;
  if (s == t)
    cout << 0;
  else {
    long long d1 = 0, d2 = 0;
    if (s < t) {
      for (i = s - 1; i < t - 1; i++) d1 += v[i];
      for (i = t - 1; i < n; i++) d2 += v[i];
      for (i = 0; i < s; i++) d2 += v[i];
    } else {
      for (i = t - 1; i < s - 1; i++) d1 += v[i];
      for (i = s - 1; i < n; i++) d2 += v[i];
      for (i = 0; i < t; i++) d2 += v[i];
    }
    cout << min(d1, d2);
  }
  return 0;
}
