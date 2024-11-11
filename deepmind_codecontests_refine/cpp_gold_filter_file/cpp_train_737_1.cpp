#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n;
  cin >> n;
  vector<long long> v;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    v.push_back(x);
  }
  if (v[0] != 0) {
    cout << 1 << endl;
    return 0;
  }
  set<long long> s = {0, 1};
  long long ans = 2;
  for (long long i = 1; i < n; i++) {
    if (s.count(v[i]) == 0) {
      cout << ans << endl;
      return 0;
    }
    s.insert(v[i] + 1);
    ans++;
  }
  cout << -1 << endl;
  return 0;
}
