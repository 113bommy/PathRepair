#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005], c[200005];
map<int, int> mp;
int main() {
  int n, m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mp[a[i]]++;
  }
  cin >> m;
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < m; i++) cin >> c[i];
  int ans, v = 0, vv = 0;
  for (int i = 0; i < m; i++) {
    if (mp[b[i]] > v) {
      v = mp[b[i]];
      ans = i + 1;
      vv = mp[c[i]];
    }
    if (mp[b[i]] == v and mp[c[i]] > vv) {
      vv = mp[c[i]];
      ans = i + 1;
    }
  }
  cout << ans << endl;
  return 0;
}
