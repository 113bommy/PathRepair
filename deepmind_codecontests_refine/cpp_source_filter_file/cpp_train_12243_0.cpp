#include <bits/stdc++.h>
using namespace std;
int tim[17];
int main() {
  tim[0] = 1 * 60 + 10;
  tim[1] = 2 * 60 + 20;
  tim[2] = 3 * 60 + 30;
  tim[3] = 4 * 60 + 40;
  tim[4] = 5 * 60 + 50;
  tim[5] = 10 * 60 + 1;
  tim[6] = 11 * 60 + 11;
  tim[7] = 12 * 60 + 21;
  tim[8] = 13 * 60 + 31;
  tim[9] = 14 * 60 + 41;
  tim[10] = 15 * 60 + 51;
  tim[11] = 20 * 60 + 2;
  tim[12] = 21 * 60 + 12;
  tim[13] = 22 * 60 + 22;
  tim[14] = 23 * 60 + 36;
  tim[15] = 24 * 60;
  int i, j, chk, l, n;
  string s;
  int s1, s2, s3, h;
  cin >> s;
  l = s.size();
  for (i = 0, chk = 1, j = l - 1; i < l / 2; i++, j--) {
    if (s[i] != s[j]) chk = 0;
  }
  if (chk == 1)
    cout << "0";
  else {
    n = ((s[0] - '0') * 10 + (s[1] - '0')) * 60 + (s[3] - '0') * 10 +
        (s[4] - '0');
    for (i = 0; i < 16; i++) {
      if (tim[i] > n) {
        h = tim[i];
        break;
      }
    }
    cout << h - n;
  }
}
