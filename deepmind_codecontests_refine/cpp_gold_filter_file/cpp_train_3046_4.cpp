#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, m, i, ans = 0, k, x, y, z = 0, z1 = 0;
    cin >> n >> k;
    map<long long int, long long int> mp;
    for (i = 0; i < n; i++) {
      cin >> x;
      x = x % k;
      if (x == 0) continue;
      mp[k - x]++;
    }
    map<long long int, long long int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
      z1 = (it->second);
      if (z1 >= z) {
        z = z1;
        ans = it->first;
      }
    }
    if (ans == 0)
      cout << ans << endl;
    else {
      ans += (z - 1ll) * k;
      ans++;
      cout << ans << endl;
    }
    mp.clear();
  }
  return 0;
}
