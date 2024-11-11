#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, x, y, n, d = 0, m, t, z;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long c1 = 0, c2 = 0, c3 = 0;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == 'R')
        c1++;
      else if (s[i] == 'P')
        c2++;
      else
        c3++;
    }
    if (c1 == c2 && c2 == c3)
      cout << s << '\n';
    else {
      long long mn = 3e9;
      string ans;
      mn = min({c1, c2, c3});
      if (mn == c1) {
        for (i = 0; i < s.size(); i++) {
          ans += 'P';
        }
      } else if (mn == c2) {
        for (i = 0; i < s.size(); i++) {
          ans += 'S';
        }
      } else {
        for (i = 0; i < s.size(); i++) {
          ans += 'R';
        }
      }
      cout << ans << '\n';
    }
  }
}
