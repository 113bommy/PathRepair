#include <bits/stdc++.h>
using namespace std;
const int N = 15000 + 9;
struct Point {
  int x, y;
  Point operator-(const Point& b) const { return (Point){x - b.x, y - b.y}; }
} p[N], rec[7], Gp[N];
bool vis[N * 5];
vector<pair<int, int> > edge_pt[5];
map<pair<int, int>, int> mp;
vector<int> G[N];
int n;
int cnt = 0;
bool judge() {
  double xx = (rec[1].x + rec[3].x) * 0.5;
  double yy = (rec[1].y + rec[3].y) * 0.5;
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (p[i].y == p[i + 1].y) continue;
    if (p[i].x < xx) continue;
    int mi = min(p[i].y, p[i + 1].y), mx = max(p[i].y, p[i + 1].y);
    if (yy <= mi || yy > mx) continue;
    ++cnt;
  }
  if (cnt & 1) return 1;
  return cnt & 1;
}
void add(int xa, int ya, int xb, int yb) {
  if (!mp[{xa, ya}]) mp[{xa, ya}] = ++cnt;
  if (!mp[{xb, yb}]) mp[{xb, yb}] = ++cnt;
  int aid = mp[{xa, ya}], bid = mp[{xb, yb}];
  G[aid].push_back(bid);
  if (xa == rec[1].x) edge_pt[1].push_back({ya, aid});
  if (xa == rec[3].x) edge_pt[3].push_back({ya, aid});
  if (ya == rec[2].y) edge_pt[2].push_back({xa, aid});
  if (ya == rec[4].y) edge_pt[4].push_back({xa, aid});
  if (xb == rec[1].x) edge_pt[1].push_back({yb, bid});
  if (xb == rec[3].x) edge_pt[3].push_back({yb, bid});
  if (yb == rec[2].y) edge_pt[2].push_back({xb, bid});
  if (yb == rec[4].y) edge_pt[4].push_back({xb, bid});
}
void build_G() {
  for (int i = 1; i <= n; ++i) {
    if (p[i].x == p[i + 1].x) {
      if (p[i].x <= rec[1].x || p[i].x >= rec[3].x) continue;
      bool up = (p[i].y < p[i + 1].y);
      int mx = max(p[i].y, p[i + 1].y), mi = min(p[i].y, p[i + 1].y);
      mx = min(mx, rec[1].y);
      mi = max(mi, rec[2].y);
      if (mi < mx) {
        if (up)
          add(p[i].x, mi, p[i].x, mx);
        else
          add(p[i].x, mx, p[i].x, mi);
      }
    } else {
      if (p[i].y >= rec[1].y || p[i].y <= rec[3].y) continue;
      bool ri = (p[i].x < p[i + 1].x);
      int mx = max(p[i].x, p[i + 1].x), mi = min(p[i].x, p[i + 1].x);
      mx = min(mx, rec[3].x);
      mi = max(mi, rec[1].x);
      if (mi < mx) {
        if (ri)
          add(mi, p[i].y, mx, p[i].y);
        else
          add(mx, p[i].y, mi, p[i].y);
      }
    }
  }
  if (cnt == 0) {
    if (judge())
      printf("1");
    else
      printf("0");
    exit(0);
  }
  for (int i = 1; i <= 4; ++i) {
    if (mp[{rec[i].x, rec[i].y}]) continue;
    mp[{rec[i].x, rec[i].y}] = ++cnt;
    int x = rec[i].x, y = rec[i].y;
    if (x == rec[1].x) edge_pt[1].push_back({y, cnt});
    if (x == rec[3].x) edge_pt[3].push_back({y, cnt});
    if (y == rec[2].y) edge_pt[2].push_back({x, cnt});
    if (y == rec[4].y) edge_pt[4].push_back({x, cnt});
  }
  for (int i = 1; i <= 4; ++i) {
    sort(edge_pt[i].begin(), edge_pt[i].end());
    if (i == 1 || i == 4) reverse(edge_pt[i].begin(), edge_pt[i].end());
    if (mp[{rec[i].x, rec[i].y}] == 0) mp[{rec[i].x, rec[i].y}] = ++cnt;
    if (mp[{rec[i + 1].x, rec[i + 1].y}] == 0)
      mp[{rec[i + 1].x, rec[i + 1].y}] = ++cnt;
    int s = mp[{rec[i].x, rec[i].y}], e = mp[{rec[i + 1].x, rec[i + 1].y}];
    for (int j = 0; j < edge_pt[i].size(); ++j) {
      if (j == edge_pt[i].size() - 1 && edge_pt[i][j].second != e)
        G[edge_pt[i][j].second].push_back(e);
      if (j == 0 && edge_pt[i][j].second != s)
        G[s].push_back(edge_pt[i][j].second);
      if (j != edge_pt[i].size() - 1)
        G[edge_pt[i][j].second].push_back(edge_pt[i][j + 1].second);
    }
  }
}
bool dfs(int u, int fa) {
  for (auto v : G[u]) {
    if (v == fa) {
      return 1;
    }
    if (vis[v] == 0) {
      vis[v] = 1;
      if (dfs(v, fa)) return 1;
    }
  }
  return 0;
}
int main() {
  int x1, y1, x2, y2;
  scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
  rec[1] = (Point){x1, y1};
  rec[2] = (Point){x1, y2};
  rec[3] = (Point){x2, y2};
  rec[4] = (Point){x2, y1};
  rec[5] = rec[1];
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &p[i].x, &p[i].y);
  p[n + 1] = p[1];
  bool cont = 1;
  for (int i = 1; i <= n; ++i) {
    if (p[i].x < rec[1].x || p[i].x > rec[3].x || p[i].y < rec[2].y ||
        p[i].y > rec[4].y)
      cont = 0;
  }
  if (cont) {
    printf("1");
    return 0;
  }
  build_G();
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) {
    if (!vis[i]) {
      vis[i] = 1;
      if (dfs(i, i)) ++ans;
    }
  }
  printf("%d", ans);
}
