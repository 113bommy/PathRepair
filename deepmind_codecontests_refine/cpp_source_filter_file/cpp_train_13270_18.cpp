#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T abs(T a) {
  return ((a < 0) ? -a : a);
}
template <typename T>
inline T sqr(T a) {
  return a * a;
}
bool solve(int);
int main() {
  int test = 0;
  while (solve(test)) {
    ++test;
  }
  return 0;
}
const int N = 24;
struct guy {
  int first, second, speed;
};
guy readGuy() {
  guy res;
  assert(scanf("%d%d%d", &res.first, &res.second, &res.speed) == 3);
  --res.first;
  --res.second;
  return res;
}
int n, m, mal, fem;
guy mals[N * N], fems[N * N];
bool f[N][N];
int dst[N][N][N][N];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
void bfs(int dst[N][N], int i, int j) {
  queue<pair<int, int> > q;
  for (int first = int(0); first < int(n); ++first)
    for (int second = int(0); second < int(m); ++second)
      dst[first][second] = -1;
  dst[i][j] = 0;
  q.push(pair<int, int>(i, j));
  while (!q.empty()) {
    i = q.front().first, j = q.front().second;
    q.pop();
    for (int d = int(0); d < int(4); ++d) {
      int first = i + dx[d], second = j + dy[d];
      if (first < 0 || first >= n || second < 0 || second >= m ||
          f[first][second])
        continue;
      if (dst[first][second] == -1) {
        dst[first][second] = dst[i][j] + 1;
        q.push(pair<int, int>(first, second));
      }
    }
  }
}
const int V = 1000500;
struct edge {
  int to, f, c, rev;
};
vector<edge> g[V];
int s, t;
int szVs = 0;
int newVertex() {
  g[szVs].clear();
  return szVs++;
}
void addEdge(int a, int b) {
  edge e1 = {b, 0, 1, int((g[b]).size())};
  edge e2 = {a, 0, 0, int((g[a]).size())};
  g[a].push_back(e1);
  g[b].push_back(e2);
}
int p[V];
int pe[V];
bool enlarge() {
  for (int i = int(0); i < int(szVs); ++i) p[i] = -1;
  queue<int> q;
  p[s] = s;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = int(0); i < int(int((g[v]).size())); ++i) {
      if (g[v][i].f == g[v][i].c) continue;
      int to = g[v][i].to;
      if (p[to] == -1) {
        p[to] = v;
        pe[to] = i;
        q.push(to);
      }
    }
  }
  if (p[t] == -1) return false;
  int v = t;
  while (v != s) {
    int pv = p[v];
    --g[v][g[pv][pe[v]].rev].f;
    ++g[pv][pe[v]].f;
    v = pv;
  }
  return true;
}
int vs1[N * N], vs2[N * N];
bool can(long long tm) {
  szVs = 0;
  s = newVertex();
  t = newVertex();
  int pars = max(mal, fem);
  for (int i = int(0); i < int(pars); ++i) {
    vs1[i] = newVertex();
    vs2[i] = newVertex();
    addEdge(s, vs1[i]);
    addEdge(vs2[i], t);
  }
  for (int first = int(0); first < int(n); ++first)
    for (int second = int(0); second < int(m); ++second) {
      int v1 = newVertex();
      int v2 = newVertex();
      addEdge(v1, v2);
      for (int i = int(0); i < int(pars); ++i) {
        long long d = dst[mals[i].first][mals[i].second][first][second];
        if (d == -1 || d * mals[i].speed > tm) continue;
        addEdge(vs1[i], v1);
      }
      for (int i = int(0); i < int(pars); ++i) {
        long long d = dst[fems[i].first][fems[i].second][first][second];
        if (d == -1 || d * fems[i].speed > tm) continue;
        addEdge(v2, vs2[i]);
      }
    }
  int flow = 0;
  while (enlarge()) ++flow;
  return flow == pars;
}
bool solve(int) {
  if (scanf("%d%d%d%d", &n, &m, &mal, &fem) != 4) return false;
  for (int i = int(0); i < int(n); ++i)
    for (int j = int(0); j < int(m); ++j) {
      char c;
      assert(scanf(" %c", &c) == 1);
      f[i][j] = c != '.';
    }
  for (int i = int(0); i < int(n); ++i) {
    for (int j = int(0); j < int(m); ++j) {
      bfs(dst[i][j], i, j);
    }
  }
  bool bad = false;
  if (mal + 1 == fem)
    mals[mal] = readGuy();
  else if (fem + 1 == mal)
    fems[fem] = readGuy();
  else {
    readGuy();
    bad = true;
  }
  for (int i = int(0); i < int(mal); ++i) mals[i] = readGuy();
  for (int i = int(0); i < int(fem); ++i) fems[i] = readGuy();
  if (bad) {
    puts("-1");
    return true;
  }
  const long long INF = 1e18 + 300;
  int pars = max(mal, fem);
  vector<long long> poss;
  for (int t = int(0); t < int(pars); ++t) {
    int i = mals[t].first, j = mals[t].second;
    for (int first = int(0); first < int(n); ++first)
      for (int second = int(0); second < int(n); ++second) {
        if (dst[i][j][first][second] == -1) continue;
        poss.push_back(dst[i][j][first][second] * 1LL * mals[t].speed);
      }
  }
  for (int t = int(0); t < int(pars); ++t) {
    int i = fems[t].first, j = fems[t].second;
    for (int first = int(0); first < int(n); ++first)
      for (int second = int(0); second < int(n); ++second) {
        if (dst[i][j][first][second] == -1) continue;
        poss.push_back(dst[i][j][first][second] * 1LL * fems[t].speed);
      }
  }
  poss.push_back(0);
  poss.push_back(INF);
  sort((poss).begin(), (poss).end());
  poss.erase(unique((poss).begin(), (poss).end()), poss.end());
  int lf = -1, rg = int((poss).size()) - 1;
  while (rg - lf > 1) {
    int mid = (lf + rg) / 2;
    if (can(poss[mid]))
      rg = mid;
    else
      lf = mid;
  }
  poss.back() = -1;
  cout << poss[rg] << endl;
  return true;
}
