#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000007;
const long long _INF = 10000000007;
vector<int> edge[2000];
int cap[2000][2000], flow, dist[2000], p[2000];
int _src, _snk;
void augment(int u, int minEdge) {
  if (u == _src) {
    flow = minEdge;
    return;
  }
  if (p[u] != -1) {
    augment(p[u], min(minEdge, cap[p[u]][u]));
    cap[p[u]][u] -= flow;
    cap[u][p[u]] += flow;
  }
  return;
}
int maxflow(int src, int snk) {
  _src = src, _snk = snk;
  int ret = 0;
  while (1) {
    flow = 0;
    queue<int> q;
    q.push(src);
    for (int i = 0; i < 2000; i++) {
      dist[i] = INF;
      p[i] = -1;
    }
    dist[src] = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      if (u == snk) break;
      for (int i = 0; i < edge[u].size(); i++) {
        int v = edge[u][i];
        if (cap[u][v] > 0 && dist[v] == INF) {
          dist[v] = dist[u] + 1;
          q.push(v);
          p[v] = u;
        }
      }
    }
    augment(snk, INF);
    if (flow == 0) break;
    ret += flow;
  }
  return ret;
}
void addEdge(int u, int v, int w, int x = 0) {
  edge[u].push_back(v);
  edge[v].push_back(u);
  cap[u][v] += w;
  cap[v][u] += x;
}
int n, m, males, females;
char grid[25][25];
pair<int, int> cellid[25][25];
struct Scayger {
  int id, sx, sy;
  long long tm;
  Scayger(int id, int x, int y, long long t) : id(id), sx(x), sy(y), tm(t) {}
};
vector<Scayger> male, female;
long long movingTime[2 * 25 * 25][25][25];
int dr[] = {0, 0, -1, 1};
int dc[] = {-1, 1, 0, 0};
void bfs(Scayger& sc) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      movingTime[sc.id][i][j] = _INF;
    }
  }
  movingTime[sc.id][sc.sx][sc.sy] = 0;
  queue<pair<int, int> > q;
  q.push(make_pair(sc.sx, sc.sy));
  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = u.first + dr[i];
      int y = u.second + dc[i];
      if (x < 0 || y < 0 || x >= n || y >= m) continue;
      if (grid[x][y] == '#') continue;
      if (movingTime[sc.id][x][y] >
          movingTime[sc.id][u.first][u.second] + sc.tm) {
        movingTime[sc.id][x][y] = movingTime[sc.id][u.first][u.second] + sc.tm;
        q.push(make_pair(x, y));
      }
    }
  }
}
bool ok(long long tm) {
  for (int i = 0; i < 2000; i++) {
    edge[i].clear();
  }
  memset(cap, 0, sizeof cap);
  int src = 2000 - 2, snk = 2000 - 1;
  for (int i = 0; i < female.size(); i++) {
    addEdge(src, female[i].id, 1);
  }
  for (int i = 0; i < male.size(); i++) {
    addEdge(male[i].id, snk, 1);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      addEdge(cellid[i][j].first, cellid[i][j].second, 1);
    }
  }
  for (int i = 0; i < female.size(); i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < m; k++) {
        if (movingTime[female[i].id][j][k] <= tm) {
          addEdge(female[i].id, cellid[j][k].first, 1);
        }
      }
    }
  }
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < m; k++) {
      for (int l = 0; l < male.size(); l++) {
        if (movingTime[male[l].id][j][k] <= tm) {
          addEdge(cellid[j][k].second, male[l].id, 1);
        }
      }
    }
  }
  int flows = maxflow(src, snk);
  return flows == int(male.size());
}
long long solve(bool flag, Scayger& boss) {
  if (!flag) {
    male.push_back(boss);
  } else {
    female.push_back(boss);
  }
  long long l = 0, r = _INF;
  bool possible = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (ok(mid)) {
      possible = 1;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  if (!flag) {
    male.pop_back();
  } else {
    female.pop_back();
  }
  if (possible) return r + 1;
  return _INF;
}
int main() {
  cin >> n >> m >> males >> females;
  for (int i = 0; i < n; i++) scanf("%s", grid[i]);
  int bx, by;
  long long bt;
  cin >> bx >> by >> bt;
  bx--;
  by--;
  Scayger boss = Scayger(0, bx, by, bt);
  bfs(boss);
  int id = 1;
  for (int i = 0; i < males; i++) {
    int x, y;
    long long t;
    cin >> x >> y >> t;
    x--, y--;
    male.push_back(Scayger(id, x, y, t));
    id++;
    bfs(male[male.size() - 1]);
  }
  for (int i = 0; i < females; i++) {
    int x, y;
    long long t;
    cin >> x >> y >> t;
    x--, y--;
    female.push_back(Scayger(id, x, y, t));
    id++;
    bfs(female[female.size() - 1]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cellid[i][j].first = id++;
      cellid[i][j].second = id++;
    }
  }
  long long res = _INF;
  if ((males < females) && (males + 1 == females)) {
    res = solve(0, boss);
  } else if ((females < males) && (females + 1 == males)) {
    res = solve(1, boss);
  }
  if (res == _INF) {
    cout << "-1\n";
  } else {
    cout << res << "\n";
  }
  return 0;
}
