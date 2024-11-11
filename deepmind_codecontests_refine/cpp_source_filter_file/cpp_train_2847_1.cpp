#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, ans, ax, ay, x, y, vis[250005], _x, _y;
queue<int> qx, qy;
long long dis[250005];
vector<int> allh;
vector<long long> alld;
struct nd {
  int x, y, sx, sy;
} b[250005];
struct bit {
  set<pair<int, int> > a[250005];
  void add(int x, int y) {
    int i;
    for (i = x; i <= m; i += (i & -i)) a[i].insert(make_pair(b[y].y, y));
  }
  void query(int x, int y) {
    int i;
    for (i = x; i; i -= (i & -i)) {
      while (!a[i].empty() && a[i].begin()->first <= y) {
        if (vis[a[i].begin()->second]) {
          a[i].erase(a[i].begin());
          continue;
        }
        vis[a[i].begin()->second] = 1;
        qx.push(b[a[i].begin()->second].sx);
        qy.push(b[a[i].begin()->second].sy);
        ans++;
        a[i].erase(a[i].begin());
      }
    }
  }
} t;
int main() {
  scanf("%d%d%d%d%d", &ax, &ay, &_x, &_y, &n);
  for ((i) = 1; (i) <= (n); ++(i)) {
    scanf("%d%d%d%d%d", &x, &y, &b[i].x, &b[i].sx, &b[i].sy);
    dis[i] = 1ll * (x - ax) * (x - ax) + 1ll * (y - ay) * (y - ay);
    allh.push_back(b[i].x);
    alld.push_back(dis[i]);
  }
  sort(allh.begin(), allh.end());
  allh.resize(unique(allh.begin(), allh.end()) - allh.begin());
  sort(alld.begin(), alld.end());
  alld.resize(unique(alld.begin(), alld.end()) - alld.begin());
  for ((i) = 1; (i) <= (n); ++(i)) {
    b[i].x = upper_bound(allh.begin(), allh.end(), b[i].x) - allh.begin();
    b[i].sx = upper_bound(allh.begin(), allh.end(), b[i].sx) - allh.begin();
    b[i].y = upper_bound(alld.begin(), alld.end(), dis[i]) - alld.begin();
    b[i].sy = upper_bound(alld.begin(), alld.end(), 1ll * b[i].sy * b[i].sy) -
              alld.begin();
  }
  _x = upper_bound(allh.begin(), allh.end(), _x) - allh.begin();
  _y = upper_bound(alld.begin(), alld.end(), 1ll * _y * _y) - alld.begin();
  qx.push(_x);
  qy.push(_y);
  m = alld.size();
  for ((i) = 1; (i) <= (n); ++(i)) t.add(b[i].x, i);
  while (!qx.empty()) {
    t.query(qx.front(), qy.front());
    qx.pop();
    qy.pop();
  }
  cout << ans << endl;
  return 0;
}
