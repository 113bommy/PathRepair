#include <bits/stdc++.h>
using namespace std;
int main() {
  char w[5];
  char s[5];
  cin >> w[0] >> w[1] >> w[2] >> w[3] >> w[4];
  cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
  int hw = ((w[0] - '0') * 10) + (w[1] - '0');
  int mw = ((w[3] - '0') * 10) + (w[4] - '0');
  int hs = ((s[0] - '0') * 10) + (s[1] - '0');
  int ms = ((s[3] - '0') * 10) + (s[4] - '0');
  ;
  int fh = hw - hs;
  int fm = mw - ms;
  while (fh < 0 || fm < 0) {
    if (fh < 0) {
      fh += 24;
    }
    if (fm < 0) {
      fm += 60;
      fh -= 1;
    }
  }
  if (fh >= 10) {
    cout << fh << ":";
  } else {
    cout << "0" << fh << ":";
  }
  if (fm >= 10) {
    cout << fm;
  } else {
    cout << "0" << fm;
  }
}
