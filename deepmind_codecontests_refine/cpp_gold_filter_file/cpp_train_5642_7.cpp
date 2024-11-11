#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, k, d;
  cin >> n >> k >> d;
  long long int a[n];
  set<long long int> s;
  map<long long int, long long int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < d; i++) {
    s.insert(a[i]);
    mp[a[i]]++;
  }
  long long int mn = s.size();
  for (int i = d; i < n; i++) {
    s.erase(a[i - d]);
    mp[a[i - d]]--;
    if (mp[a[i - d]] != 0) s.insert(a[i - d]);
    s.insert(a[i]);
    mp[a[i]]++;
    mn = min(mn, (long long int)(s.size()));
  }
  cout << mn << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
