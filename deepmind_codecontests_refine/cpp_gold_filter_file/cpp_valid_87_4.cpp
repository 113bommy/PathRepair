#include <bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int binpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long int res = binpow(a, b / 2);
  if (b % 2 == 0)
    return (res * res) % mod;
  else
    return ((res * res) % mod * a) % mod;
}
long long int inv(long long int a) {
  return (binpow(a, mod - 2) % mod + mod) % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a;
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    multiset<int> s;
    int ans = 0;
    for (int i = 0; i < m; i++) {
      if (i == 0)
        s.insert(a[i]);
      else {
        auto it = s.lower_bound(a[i]);
        ans += distance(s.begin(), it);
        s.insert(a[i]);
      }
    }
    cout << ans << endl;
  }
}
