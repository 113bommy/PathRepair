#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int ans = 0;
  map<long long int, long long int> mp, ml;
  long long int n, m;
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    mp[i % 5]++;
  }
  for (long long int i = 1; i <= m; i++) {
    ml[i % 5]++;
  }
  for (long long int i = 1; i <= n; i++) {
    long long int rem = (5 - i % 5) % 5;
    ans += ml[rem];
  }
  cout << ans << endl;
}
