#include <bits/stdc++.h>
using namespace std;
const int N = 303;
map<int, int> colors;
map<int, vector<pair<int, int> > > geo;
map<pair<int, int>, int> spiralDelta;
int geoColor[N][N], pColor[N][N];
int p[N * N * 2], w[N * N * 2], n, m;
pair<int, int> now;
long long ans = 0;
inline int getColor(int color) {
  int conv;
  if (color == 0) return 0;
  if (colors.find(color) != colors.end()) {
    conv = colors[color];
  } else
    colors[color] = conv = colors.size() + 1;
  return conv;
}
void initSpiral() {
  int x = 0, y = 0;
  int dy = 0, dx = -1;
  int curDist = 0, maxDist = 2;
  bool first = true;
  for (int i = 0; i < N * N; i++) {
    spiralDelta[make_pair(x, y)] = i;
    x += dx;
    y += dy;
    curDist++;
    if (curDist + 1 == maxDist) {
      if (not first) {
        maxDist++;
      }
      first = !first;
      curDist = 0;
      if (dx == 0) {
        dx = (dy < 0 ? -1 : 1);
        dy = 0;
      } else {
        dy = (dx < 0 ? 1 : -1);
        dx = 0;
      }
    }
  }
}
inline bool cmp(pair<int, int> a, pair<int, int> b) {
  a.first -= now.first;
  a.second -= now.second;
  b.first -= now.first;
  b.second -= now.second;
  return spiralDelta[a] < spiralDelta[b];
}
inline int getParent(int color) {
  if (color == p[color]) return color;
  w[p[color]] += w[color];
  w[color] = 0;
  return p[color] = getParent(p[color]);
}
inline void merge(int slave, int master) {
  ans += w[slave];
  p[slave] = master;
  p[master] = master;
  w[master] += w[slave];
  w[slave] = 0;
}
int main() {
  cin.sync_with_stdio(false);
  int cur, startx, starty;
  initSpiral();
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> cur;
      int conv = getColor(cur);
      pColor[i][j] = conv;
      p[conv] = conv;
      w[conv]++;
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      cin >> cur;
      if (cur != -1) {
        int conv = getColor(cur);
        geo[pColor[i][j]].push_back(make_pair(i, j));
        geoColor[i][j] = conv;
        p[conv] = conv;
      }
    }
  cin >> startx >> starty;
  startx--;
  starty--;
  queue<pair<int, int> > q;
  q.push(make_pair(startx, starty));
  while (not q.empty()) {
    now = q.front();
    q.pop();
    int color = geoColor[now.first][now.second];
    int panelColor = getParent(pColor[now.first][now.second]);
    if (panelColor != 0 and panelColor != color) {
      sort(geo[panelColor].begin(), geo[panelColor].end(), cmp);
      for (pair<int, int> &next : geo[panelColor]) {
        q.push(next);
      }
      geo[panelColor].clear();
      merge(panelColor, color);
    }
  }
  cout << ans << endl;
  return 0;
}
