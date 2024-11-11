#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  if (s == "12:00") {
    cout << "0 0" << '\n';
    return 0;
  }
  int rh = ((int)s[0] - 48) * 10 + ((int)s[1] - 48);
  if (rh == 12) rh = 0;
  int rm = ((int)s[3] - 48) * 10 + ((int)s[4] - 48);
  cout << (rh)*30 + (double)rm / 2 << ' ' << rm * 6 << '\n';
}
