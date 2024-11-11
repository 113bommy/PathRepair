#include <bits/stdc++.h>
using namespace std;
int cal(char a, char b) { return (a - '0') * 10 + b - '0'; }
int lucky(int h, int m) {
  if (h % 10 == 7 || m % 10 == 7) return 1;
  return 0;
}
int main() {
  int x;
  string s;
  cin >> x;
  cin >> s;
  int h = cal(s[0], s[1]);
  cin >> s;
  int m = cal(s[0], s[1]);
  int h1 = h, m1 = m, ans = 0;
  while (!lucky(h1, m1)) {
    ans++;
    if (m1 >= x)
      m1 -= x;
    else {
      m1 = 60 - (m - x);
      if (h1)
        h1--;
      else
        h1 = 23;
    }
  }
  cout << ans << endl;
  return 0;
}
