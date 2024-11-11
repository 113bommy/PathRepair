#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, t, sx, sy, ex, ey, tt = -1;
  cin >> t >> sx >> sy >> ex >> ey;
  string s;
  cin >> s;
  for (i = 0; i < t; i++) {
    if (s[i] == 'S' && sy > ey) {
      sy = sy - 1;
    } else if (s[i] == 'N' && sy < ey) {
      sy = sy + 1;
    } else if (s[i] == 'E' && sx < ex) {
      sx = sx + 1;
    } else if (s[i] == 'W' && sx > ex) {
      sx = sx - 1;
    }
    if (sx == ex && sy == ey) {
      tt = i + 1;
      break;
    }
  }
  cout << tt << endl;
  return 0;
}
