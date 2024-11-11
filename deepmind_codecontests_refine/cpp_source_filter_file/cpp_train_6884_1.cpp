#include <bits/stdc++.h>
using namespace std;
const int M = 1000005;
const int nmax = 200010;
const int MOD = (1e9) + 7;
int n;
string s;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> s;
  int n = ((int)(s.size()));
  s = " " + s;
  int l = 1;
  int r = n;
  while (l <= n && s[l] != '[') l++;
  while (r >= 1 && s[r] != ']') r--;
  if (l > n || r < 1)
    cout << -1 << '\n';
  else {
    int ff = -1, ss = -1;
    for (int i = l + 1; i <= r - 1; i++)
      if (s[i] == ':') {
        ff = i;
        break;
      }
    for (int i = r - 1; i >= l + 1; i--)
      if (s[i] == ':') {
        ss = i;
        break;
      }
    if (ff == ss)
      cout << -1 << '\n';
    else {
      int nr = 0;
      for (int i = ff + 1; i <= ss - 1; i++)
        if (s[i] == '|') nr++;
      cout << n - nr - 4 << '\n';
    }
  }
  return 0;
}
