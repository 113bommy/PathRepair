#include <bits/stdc++.h>
using namespace std;
int n, c, a[7] = {100002, 100002, 100002, 100002, 100002, 100002, 100002}, p,
          ans;
string s;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c >> s;
    p = 0;
    for (int j = 0; j < s.size(); j++)
      if (s[j] == 'A')
        p += 1;
      else if (s[j] == 'B')
        p += 10;
      else
        p += 100;
    if (p == 1) {
      a[0] = min(a[0], c);
    } else if (p == 10) {
      a[1] = min(a[1], c);
    } else if (p == 100) {
      a[2] = min(a[2], c);
    } else if (p == 11) {
      a[3] = min(a[3], c);
      a[0] = min(a[0], c);
      a[1] = min(a[1], c);
    } else if (p == 101) {
      a[4] = min(a[4], c);
      a[0] = min(a[0], c);
      a[2] = min(a[2], c);
    } else if (p == 110) {
      a[5] = min(a[5], c);
      a[1] = min(a[0], c);
      a[2] = min(a[2], c);
    } else {
      a[6] = min(a[6], c);
    }
  }
  ans = min(min(a[0] + a[1] + a[2], a[0] + a[5]),
            min(a[1] + a[4], min(a[2] + a[3], a[6])));
  if (ans > 100000)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
