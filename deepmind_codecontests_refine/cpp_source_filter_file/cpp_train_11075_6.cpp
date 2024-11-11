#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m;
set<pair<pair<int, int>, int> > S;
set<pair<int, int> > SS;
string c;
int main() {
  int i, j;
  int x, y;
  cin >> n >> m >> x >> y >> c;
  int dir;
  if (c == "DR")
    dir = 2;
  else if (c == "UR")
    dir = 3;
  else if (c == "DL")
    dir = 4;
  else
    dir = 1;
  int tot = 1;
  int sum = (m + 1) / 2 + (m + (n & 1)) / 2 + (n + 1) / 2 + (n + (m & 1)) / 2 -
            1 - (m & 1) - (n & 1) - ((n & 1) == (m & 1));
  int ans = 1;
  S.insert(make_pair(make_pair(x, y), dir));
  SS.insert(make_pair(x, y));
  bool flag = 0;
  while (1) {
    if (dir == 1) {
      int cnt = min(x - 1, y - 1);
      ans += cnt;
      y -= cnt;
      x -= cnt;
      if (x == 1 && y == 1)
        dir = 2;
      else if (x == 1)
        dir = 4;
      else if (y == 1)
        dir = 3;
    } else if (dir == 2) {
      int cnt = min(m - y, n - x);
      ans += cnt;
      x += cnt;
      y += cnt;
      if (x == n && y == m)
        dir = 1;
      else if (x == n)
        dir = 3;
      else if (y == m)
        dir = 4;
    } else if (dir == 3) {
      int cnt = min(x - 1, m - y);
      ans += cnt;
      x -= cnt;
      y += cnt;
      if (x == 1 && y == m)
        dir = 4;
      else if (x == 1)
        dir = 2;
      else if (y == m)
        dir = 1;
    } else {
      int cnt = min(n - x, y - 1);
      ans += cnt;
      x += cnt;
      y -= cnt;
      if (x == n && y == 1)
        dir = 3;
      else if (x == n)
        dir = 1;
      else if (y == 1)
        dir = 2;
    }
    pair<int, int> pp = make_pair(x, y);
    if (!SS.count(pp)) {
      SS.insert(pp);
      tot++;
    }
    if (tot == sum) break;
    if (S.count(make_pair(pp, dir))) {
      flag = 1;
      break;
    }
    S.insert(make_pair(pp, dir));
  }
  if (flag)
    puts("-1");
  else
    cout << ans << endl;
  return 0;
}
