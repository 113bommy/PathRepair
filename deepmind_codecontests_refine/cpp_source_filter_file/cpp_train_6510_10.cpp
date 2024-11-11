#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  map<long, long> mp;
  for (long i = 1; i <= n; i++) {
    long val;
    cin >> val;
    mp[val]++;
  }
  long m;
  cin >> m;
  long aa[m + 1], bb[m + 1];
  for (long i = 1; i <= m; i++) cin >> aa[i];
  for (long i = 1; i <= m; i++) cin >> bb[i];
  long xx = 0, yy = 0, ans;
  for (long i = 1; i <= m; i++) {
    if (mp[aa[i]] == xx && mp[bb[i]] > yy) {
      yy = mp[bb[i]];
      ans = i;
    }
    if (mp[aa[i]] > xx) {
      xx = mp[aa[i]];
      yy = mp[bb[i]];
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
