#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, i, j, k, l, m, b, t, sum, sum1, flag, max1, min1, tmp;
  cin >> n >> t;
  long long a[n + 1];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  set<long long> s;
  map<long long, long long> mp;
  for (i = n; i >= 1; i--) {
    s.insert(a[i]);
    mp[i] = s.size();
  }
  for (i = 1; i <= t; i++) {
    cin >> k;
    cout << mp[k] << endl;
  }
  cout << endl;
}
