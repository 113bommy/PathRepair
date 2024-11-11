#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, sx, sy, ex, ey;
  cin >> t >> sx >> sy >> ex >> ey;
  long long int n = 0, s = 0, e = 0, w = 0;
  if (ex - sx > 0)
    e += ex - sx;
  else
    w += sx - ex;
  if (ey - sy > 0)
    n += ey - sy;
  else
    s += sy - ey;
  char dir;
  for (long long int i = 1; i <= t; ++i) {
    cin >> dir;
    if (dir == 'N' && n)
      n--;
    else if (dir == 'S' && s)
      s--;
    else if (dir == 'E' && e)
      e--;
    else if (dir == 'W' && w)
      w--;
    if (!n && !s && !e && !w) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
