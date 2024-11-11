#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long int t = 1;
  while (t--) {
    string s;
    cin >> s;
    string s1 = s;
    s1[4] = s1[0];
    s1[3] = s1[1];
    if (s1 > s && s1[3] <= 5)
      cout << s1;
    else {
      long long int x = (s[0] - 48) * 10 + (s[1] - 48);
      x = (x + 1) % 24;
      while (x % 10 >= 6) x = (x + 1) % 24;
      long long int y = (x % 10) * 10 + x / 10;
      if (x < 10) cout << 0;
      cout << x << ":";
      if (y < 10) cout << 0;
      cout << y;
    }
  }
  return 0;
}
