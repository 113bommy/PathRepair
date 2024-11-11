#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 2e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  vector<long long> b(n);
  map<long long, long long> mp;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; ++i) {
    cin >> b[i];
    mp[b[i]]++;
  }
  vector<long long> c(n);
  for (long long i = 0; i < n; i++) {
    long long x = a[i];
    long long target = (n - x % n) % n;
    auto it = mp.lower_bound(target);
    long long res;
    if (it != mp.end())
      res = it->first;
    else
      res = mp.begin()->first;
    c[i] = res;
    mp[res]--;
    if (mp[res] == 0) mp.erase(res);
  }
  for (long long i = 0; i < n; i++) {
    cout << (a[i] + c[i]) % n << " ";
  }
  return 0;
}
