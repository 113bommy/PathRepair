#include <bits/stdc++.h>
using namespace std;
long long a[120004];
map<long long, long long> mp;
int main() {
  ios::sync_with_stdio(false);
  int n, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  int ans = 0, c;
  long long po;
  for (i = 0; i < n; i++) {
    c = 0;
    po = 1;
    while (po <= 2000000000) {
      if (mp.find(po - a[i]) != mp.end()) {
        if ((a[i] == po - a[i] && mp[a[i]] > 1) || (a[i] != po - a[i])) {
          c++;
          break;
        }
      }
      po = po * 2LL;
    }
    if (c == 0) {
      ans++;
    }
  }
  cout << ans;
  return 0;
}
