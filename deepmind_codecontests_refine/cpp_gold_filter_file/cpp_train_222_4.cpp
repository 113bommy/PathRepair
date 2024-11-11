#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long tests = 1;
  while (tests--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;
    if ((long long)s.length() == 1) {
      cout << "1" << '\n' << s;
      return 0;
    }
    long long y = 0;
    for (long long i = 0; i < (long long)s.length(); i++) {
      if (s[i] == '0') y++;
    }
    if (2 * y != (long long)s.length()) {
      cout << "1" << '\n' << s;
      return 0;
    }
    for (long long i = 0; i < (long long)s.length() - 1; i++) {
      string j = s.substr(0, i + 1);
      string k = s.substr(i + 1, (long long)s.length());
      long long t = 0, x = 0;
      for (long long i = 0; i < (long long)j.length(); i++) {
        if (j[i] == '0') t++;
      }
      for (long long i = 0; i < (long long)k.length(); i++) {
        if (k[i] == '0') x++;
      }
      if (2 * t != (long long)j.length() && 2 * x != (long long)k.length()) {
        cout << "2" << '\n';
        cout << j << " " << k;
        return 0;
      }
    }
    cout << "3" << '\n';
    cout << s[0] << " " << s[1] << " " << s.substr(2, (long long)s.length());
  }
}
