#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  int f[5] = {a, b, c, d, e}, mn = a + b + c + d + e, ans = a + b + c + d + e;
  sort(f, f + 5);
  map<int, int> mp;
  for (int i = 0; i < 5; i++) {
    mp[f[i]]++;
    if (mp[f[i]] == 2)
      ans = min(ans, mn - f[i] * 2);
    else if (mp[f[i]] == 3)
      ans = min(ans, mn - f[i] * 3);
  }
  cout << ans << endl;
}
