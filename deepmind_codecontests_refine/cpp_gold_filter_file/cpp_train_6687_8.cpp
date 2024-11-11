#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long t;
  cin >> t;
  while (t--) {
    long long d, m;
    cin >> d >> m;
    vector<long long> v;
    long long val = 1ll;
    while (1) {
      if (val <= d)
        v.push_back(val);
      else {
        if (d > 0ll) v.push_back(d);
        break;
      }
      d -= val;
      val *= 2ll;
    }
    long long ans = v[0] % m;
    for (long long i = 1; i < v.size(); i++)
      ans = (ans + v[i] + ans * v[i]) % m;
    cout << ans << "\n";
  }
}
