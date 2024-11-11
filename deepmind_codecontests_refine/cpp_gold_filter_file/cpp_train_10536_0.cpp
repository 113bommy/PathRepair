#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    long long int l = 0, r = 0, u = 0, d = 0;
    for (char c : str) {
      if (c == 'L') {
        l++;
      } else if (c == 'R') {
        r++;
      } else if (c == 'U') {
        u++;
      } else {
        d++;
      }
    }
    long long int anslen = 0;
    string ans;
    if (l == 0 || r == 0) {
      long long int minn = min(u, d);
      if (minn >= 1) {
        anslen = 2;
        ans.push_back('U');
        ans.push_back('D');
      }
    } else if (u == 0 || d == 0) {
      long long int minn = min(l, r);
      if (minn >= 1) {
        anslen = 2;
        ans.push_back('L');
        ans.push_back('R');
      }
    } else {
      long long int min1 = min(u, d), min2 = min(l, r);
      anslen = 2 * (min1 + min2);
      for (long long int i = 0; i < min1; i++) {
        ans.push_back('U');
      }
      for (long long int i = 0; i < min2; i++) {
        ans.push_back('L');
      }
      for (long long int i = 0; i < min1; i++) {
        ans.push_back('D');
      }
      for (long long int i = 0; i < min2; i++) {
        ans.push_back('R');
      }
    }
    cout << anslen << "\n";
    cout << ans << "\n";
  }
}
