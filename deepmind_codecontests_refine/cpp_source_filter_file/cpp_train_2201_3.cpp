#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
  int t = 0;
  h1 = (s1[0] - '0') * 10 + (s1[1] - '0');
  m1 = (s1[3] - '0') * 10 + (s1[4] - '0');
  h2 = (s2[0] - '0') * 10 + (s2[1] - '0');
  m2 = (s2[3] - '0') * 10 + (s2[4] - '0');
  int yu = 0;
  int ans1 = 0, ans2 = 0;
  yu = (h1 + h2) % 2;
  ans1 = (h1 + h2) / 2;
  ans2 = (m1 + m2) / 2;
  if (yu == 1) ans2 += 30;
  if (ans2 > 60) {
    ans2 -= 60;
    ans1++;
  }
  if (ans1 / 10 == 0) {
    cout << "0" << ans1 << ":";
    if (ans2 / 10 == 0) {
      cout << "0" << ans2 << endl;
    } else
      cout << ans2 << endl;
  }
  if (ans1 / 10 != 0) {
    cout << ans1 << ":";
    if (ans2 / 10 == 0)
      cout << "0" << ans2 << endl;
    else
      cout << ans2 << endl;
  }
  return 0;
}
