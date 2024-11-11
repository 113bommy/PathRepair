#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string r, w;
  r = s.substr(0, 2);
  w = s.substr(3, 2);
  float a, b;
  istringstream(r) >> a;
  istringstream(w) >> b;
  float ans = (a / 12 * 360) + float(b / 2);
  float anss = b / 60 * 360;
  if (ans == 360) {
    ans = 0;
  }
  cout << ans << " " << anss;
}
