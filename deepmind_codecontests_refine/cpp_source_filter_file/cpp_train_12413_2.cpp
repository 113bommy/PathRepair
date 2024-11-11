#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, i;
  cin >> t;
  while (t--) {
    cin >> n;
    set<long long int> s;
    map<long long int, long long int> mp;
    long long int a[n + 1], p, mx = 0;
    for (i = 1; i <= n; i++) {
      cin >> a[i];
      s.insert(a[i]);
      mp[a[i]]++;
    }
    vector<long long int> v;
    for (auto u : mp) {
      mx = max(mx, u.second);
      if (u.second == 1) {
        v.push_back(u.second);
      }
    }
    p = v.size();
    long long int mn1 = min(p - 1, mx);
    long long int mn2 = min(p, mx - 1);
    long long int mx1 = max(mn1, mn2);
    cout << mx1 << endl;
  }
}
