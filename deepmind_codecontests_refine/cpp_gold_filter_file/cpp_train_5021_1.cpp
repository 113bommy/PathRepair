#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long int n, sum = 0, ans = 0, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  for (long long int i = 0; i < s.size(); i++) {
    if (s[i] == '(')
      sum++;
    else
      sum--;
    if (sum < 0) cnt = 1;
    ans += cnt;
    if (sum == 0) cnt = 0;
  }
  if (sum == 0)
    cout << ans;
  else
    cout << -1;
  return 0;
}
