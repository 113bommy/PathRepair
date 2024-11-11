#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  int l = s.size();
  vector<int> d(l + 1, 0);
  long long ans = 0, cur = 0, maxi = 0;
  for (int i = 0; i < l; i++) {
    if (s[i] == '+')
      cur++;
    else
      cur--;
    d[i + 1] = cur;
    if (cur < 0 && d[i + 1] < maxi) ans += i + 1;
    maxi = min(maxi, cur);
  }
  cout << ans + l << endl;
  return;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
