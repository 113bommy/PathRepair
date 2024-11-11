#include <bits/stdc++.h>
using namespace std;
int main() {
  string sec = "", hr = "", str, trial = "";
  cin >> str;
  hr += str.substr(0, 2);
  sec += str.substr(3, 2);
  int res = 0;
  int h, s, t;
  while (1) {
    if (hr[1] == sec[0] && hr[0] == sec[1]) break;
    h = stoi(hr);
    s = stoi(sec);
    t = stoi(hr);
    int rev = 0;
    rev = t % 10;
    rev = (rev * 10) + t / 10;
    t = rev;
    if (t >= s && t <= 60) {
      res += t - s;
      break;
    } else {
      res += 60 - s;
      h++;
      if (h > 23) h = 0;
      s = 0;
      hr = to_string(h);
      sec[0] = '0';
      sec[1] = '0';
    }
  }
  cout << res;
  return 0;
}
