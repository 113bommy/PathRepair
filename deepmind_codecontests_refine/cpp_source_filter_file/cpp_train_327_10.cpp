#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int ans = 1;
  while (b > 0) {
    if (b % 2 != 0) {
      ans = ((ans) * (a));
    }
    a = ((a) * (a));
    b = b / 2;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long int l = 0, r = 0, t = 0, d = 0;
    long long int lenl = 0, lenr = 0, lent = 0, lend = 0;
    long long int x = 0, y = 0;
    for (long long int i = 0; i < s.length(); i++) {
      if (s[i] == 'W') {
        y++;
        t = max(t, y);
      } else if (s[i] == 'S') {
        y--;
        d = min(d, y);
      } else if (s[i] == 'A') {
        x--;
        l = min(x, l);
      } else {
        x++;
        r = max(x, r);
      }
      lenl = max(lenl, x - l);
      lenr = max(lenr, r - x);
      lent = max(lent, t - y);
      lend = max(lend, y - d);
    }
    long long int ans = (r - l + 1) * (t - d + 1);
    if ((r - l) > 1 && lenl != lenr) {
      ans = min(ans, (r - l) * (t - d + 1));
    } else if ((t - d) > 1 && lent != lend) {
      ans = min(ans, (t - d) * (r - l + 1));
    }
    cout << ans << endl;
  }
  return 0;
}
