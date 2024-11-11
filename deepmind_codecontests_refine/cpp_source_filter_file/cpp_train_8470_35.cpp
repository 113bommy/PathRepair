#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, in = 0;
  int s[4];
  cin >> y;
  y++;
  for (int i = y; i <= 9000; i++) {
    int q = 10000;
    in = i;
    for (int j = 0; j < 4; j++) {
      q = q / 10;
      s[j] = in / q;
      in = (int)i % (int)q;
    }
    if (s[0] != s[1] && s[2] != s[0] && s[0] != s[3] && s[1] != s[2] &&
        s[1] != s[3] && s[2] != s[3])
      break;
    else
      continue;
  }
  cout << s[0] << s[1] << s[2] << s[3];
  return 0;
}
