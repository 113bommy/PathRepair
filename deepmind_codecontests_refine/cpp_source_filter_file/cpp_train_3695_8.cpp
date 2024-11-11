#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long x = 0, y = 0;
  for (long long i = 0; i < n; i++) {
    if (s[i] == '0')
      x++;
    else
      y++;
  }
  cout << min(x, y) * 2;
  return 0;
}
