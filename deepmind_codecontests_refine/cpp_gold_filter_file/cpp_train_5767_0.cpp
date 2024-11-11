#include <bits/stdc++.h>
using namespace std;
int t, sx, sy, ex, ey;
string s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> t >> sx >> sy >> ex >> ey >> s;
  for (int i = 0; i < t; i++) {
    if (s[i] == 'S' && sy > ey) {
      sy--;
    } else if (s[i] == 'N' && sy < ey) {
      sy++;
    } else if (s[i] == 'E' && sx < ex) {
      sx++;
    } else if (s[i] == 'W' && sx > ex) {
      sx--;
    }
    if (sx == ex && sy == ey) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  cout << -1 << "\n";
  return 0;
}
