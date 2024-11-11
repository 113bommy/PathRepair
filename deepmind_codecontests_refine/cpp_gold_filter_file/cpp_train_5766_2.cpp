#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
set<pair<int, int> > S;
string ch;
vector<pair<int, int> > dag1[maxn << 1], dag2[maxn << 1], dag;
int n, m, k;
long long ans;
int sx, sy;
int dx[] = {1, -1, 1, -1};
int dy[] = {1, -1, -1, 1};
int mx[] = {2, 3, 0, 1};
int my[] = {3, 2, 1, 0};
bool ok(int x, int y, int dir) {
  return (x + y == sx + sy && dir >= 2) || (x - y == sx - sy && dir <= 1);
}
void go(int x, int y, int dir) {
  int id = (dir <= 1) ? x - y + m + 1 : x + y;
  dag = (dir <= 1) ? dag2[id] : dag1[id];
  vector<pair<int, int> >::iterator it =
      lower_bound(dag.begin(), dag.end(), make_pair(x, y));
  if (dir == 0 || dir == 2) it--;
  int tx, ty;
  tx = it->first;
  ty = it->second;
  if (sx > min(x, tx) && sx < max(x, tx) && ok(x, y, dir)) {
    ans += abs(sx - x);
    return;
  }
  ans += abs(x - tx);
  bool g1 = S.count(make_pair(tx + dx[dir], ty)),
       g2 = S.count(make_pair(tx, ty + dy[dir]));
  if (g1 == g2) {
    x = tx + dx[dir];
    y = ty + dy[dir];
    dir ^= 1;
  } else if (g1) {
    x = tx;
    y = ty + dy[dir];
    dir = mx[dir];
  } else if (g2) {
    x = tx + dx[dir];
    y = ty;
    dir = my[dir];
  }
  if (x == sx && y == sy) return;
  go(x, y, dir);
}
int main() {
  int i;
  cin >> n >> m >> k;
  int x, y;
  while (k--) {
    cin >> x >> y;
    S.insert(make_pair(x, y));
  }
  for (i = 0; i <= n + 1; i++)
    S.insert(make_pair(i, 0)), S.insert(make_pair(i, m + 1));
  for (i = 0; i <= m + 1; i++)
    S.insert(make_pair(0, i)), S.insert(make_pair(n + 1, i));
  set<pair<int, int> >::iterator it;
  for (it = S.begin(); it != S.end(); it++) {
    x = it->first;
    y = it->second;
    dag1[x + y].push_back(*it);
    dag2[x - y + m + 1].push_back(*it);
  }
  cin >> sx >> sy >> ch;
  int dir;
  if (ch == "NW")
    dir = 0;
  else if (ch == "SE")
    dir = 1;
  else if (ch == "NE")
    dir = 2;
  else
    dir = 3;
  go(sx, sy, dir);
  go(sx, sy, dir ^ 1);
  cout << (ans >> 1) << endl;
  return 0;
}
