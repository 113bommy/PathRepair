#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long arr[31], i;
  arr[0] = 1;
  for (i = 1; i <= 30; i++) arr[i] = arr[i - 1] * 2;
  map<int, bool> mp;
  for (i = 0; i <= 29; i++) mp[arr[i]] = true;
  int t, d, m;
  cin >> t;
  while (t--) {
    cin >> d >> m;
    if (d == 1) {
      cout << 1 % m << endl;
      continue;
    }
    for (i = 0; i <= 30; i++) {
      if (d / arr[i] == 0) break;
    }
    int lastb = i, b[lastb];
    for (i = 0; i < lastb; i++) {
      if (i == (lastb - 1)) {
        b[i] = (d / arr[i]) + (d % arr[i]) + 1;
        continue;
      }
      b[i] = arr[i] + 1;
    }
    int ans = 1;
    for (i = 0; i < lastb; i++) ans = (ans * b[i]) % m;
    ans--;
    if (ans < 0) ans += m;
    cout << ans << endl;
  }
  return 0;
}
