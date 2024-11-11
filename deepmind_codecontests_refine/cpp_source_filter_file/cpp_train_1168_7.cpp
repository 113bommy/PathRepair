#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, p, f = 0, f2 = 0, cnt1 = 0, cnt2 = 0, ans = -1;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        if (!f || f2) cnt1++, f2 = 0;
        f = 1;
      } else {
        if (!f2 || f) cnt2++, f = 0;
        f2 = 1;
      }
    }
    if (s[s.length() - 1] != s[s.length() - 2]) {
      if (s[s.length() - 1] == 'B')
        cnt2--;
      else
        cnt1--;
    }
    f2 = 0, f = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == 'A') {
        f = 1;
        if (f2) {
          if (cnt2 > 0) cnt2--;
          f2 = 0;
        }
        if (a * cnt1 + b * cnt2 <= p) {
          ans = i + 1;
          break;
        }
      } else {
        f2 = 1;
        if (f) {
          if (cnt1 > 0) cnt1--;
          f = 0;
        }
        if (a * cnt1 + b * cnt2 <= p) {
          ans = i + 1;
          break;
        }
      }
    }
    if (ans == -1)
      cout << s.length() << endl;
    else
      cout << ans << endl;
  }
  return 0;
}
