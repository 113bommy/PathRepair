#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  string s;
  cin >> s;
  long long int temp = 0;
  long long int ans = 2, c = 0;
  for (long long int i = 0; i < n; i++) {
    if (s[i] == '(')
      temp++;
    else
      temp--;
    if (temp < 0) {
      c++;
      temp = 0;
      ans--;
    }
  }
  temp -= (c);
  if (temp != 0 || ans <= 0)
    cout << "No" << '\n';
  else
    cout << "Yes" << '\n';
}
int32_t main() {
  long long int t = 1;
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (t--) {
    solve();
  }
}
