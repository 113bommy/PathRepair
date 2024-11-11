#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long &x : a) cin >> x;
  map<long long, long long> mp;
  set<long long> s;
  for (long long i = 0; i < k; ++i) {
    if (mp[a[i]]) {
      s.erase(a[i]);
      mp[a[i]]++;
    } else {
      mp[a[i]]++;
      s.insert(a[i]);
    }
  }
  for (long long i = 0; i + k <= n; ++i) {
    if (s.empty())
      cout << "Nothing\n";
    else
      cout << *(s.rbegin()) << '\n';
    if (i + k < n) {
      if (mp[a[i]] == 1) {
        s.erase(a[i]);
      }
      mp[a[i]]--;
      if (mp[a[i]] == 1) {
        s.insert(a[i]);
      }
      if (mp[a[i]]) {
        s.erase(a[i + k]);
        mp[a[i + k]]++;
      } else {
        mp[a[i + k]]++;
        s.insert(a[i + k]);
      }
    }
  }
}
