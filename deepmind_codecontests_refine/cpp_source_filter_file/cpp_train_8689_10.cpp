#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000;
const int INF = 1e9;
const int N = 25;
const long long BIGINF = 1e8;
struct Person {
  int gender, x, y, t;
  Person(){};
  Person(int gender, int x, int y, int t) : gender(gender), x(x), y(y), t(t){};
};
struct edge {
  int to, cap, flow;
  edge(){};
  edge(int to, int cap, int flow) : to(to), cap(cap), flow(flow){};
};
bool place[N][N];
vector<Person> pers;
int dist[N][N][N][N];
pair<int, int> q[N * N];
struct Flow {
  int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
  vector<int> g[MAXN];
  vector<edge> e;
  Flow(){};
  Flow(int n, int s, int t) : n(n), s(s), t(t){};
  void init(int n1, int s1, int t1) {
    n = n1;
    s = s1;
    t = t1;
  }
  void add_edge(int a, int b, int cap) {
    edge e1 = edge(b, cap, 0);
    edge e2 = edge(a, 0, 0);
    g[a].push_back(e.size());
    e.push_back(e1);
    g[b].push_back(e.size());
    e.push_back(e2);
  }
  bool bfs(int min_cap) {
    int qh = 0, qt = 0;
    q[qt++] = s;
    memset(d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt) {
      int v = q[qh++];
      for (int id : g[v]) {
        int to = e[id].to;
        if (d[to] == -1 && e[id].cap - e[id].flow >= min_cap) {
          d[to] = d[v] + 1;
          q[qt++] = to;
        }
      }
    }
    return d[t] != -1;
  }
  int dfs(int v, int flow, int min_cap) {
    if (!flow) return 0;
    if (v == t) return flow;
    for (; ptr[v] < g[v].size(); ptr[v]++) {
      int id = g[v][ptr[v]];
      int to = e[id].to;
      if (d[to] != d[v] + 1) continue;
      if (e[id].cap - e[id].flow < min_cap) continue;
      int pushed = dfs(to, min(flow, e[id].cap - e[id].flow), min_cap);
      if (pushed) {
        e[id].flow += pushed;
        e[id ^ 1].flow -= pushed;
        return pushed;
      }
    }
    return 0;
  }
  int dinic() {
    int flow = 0;
    for (int min_cap = (1 << 30); min_cap > 0; min_cap >>= 1) {
      while (bfs(min_cap)) {
        memset(ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs(s, INF, min_cap)) {
          flow += pushed;
        }
      }
    }
    return flow;
  }
};
bool valid(int x, int y) { return min(x, y) >= 0 && max(x, y) < N; }
void great_bfs(int x, int y) {
  int qh = 0, qt = 0;
  q[qt++] = make_pair(x, y);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dist[x][y][i][j] = INF;
  dist[x][y][x][y] = 0;
  while (qh < qt) {
    pair<int, int> p = q[qh++];
    for (int i = -1; i < 2; i++)
      for (int j = -1; j < 2; j++)
        if (abs(i) + abs(j) == 1) {
          int x1 = p.first + i, y1 = p.second + j;
          if (!valid(x1, y1)) continue;
          if (dist[x][y][x1][y1] == INF && place[x1][y1]) {
            dist[x][y][x1][y1] = dist[x][y][p.first][p.second] + 1;
            q[qt++] = make_pair(x1, y1);
          }
        }
  }
}
bool check_ans(long long ans, int h, int w) {
  int n = MAXN - 100;
  int s = n - 2, t = n - 1;
  Flow flow(n, s, t);
  int k = pers.size();
  for (int i = 0; i < k; i++) {
    if (pers[i].gender) {
      flow.add_edge(i, t, 1);
    } else {
      flow.add_edge(s, i, 1);
    }
    for (int x = 0; x < h; x++)
      for (int y = 0; y < w; y++)
        if (place[x][y]) {
          if (dist[x][y][pers[i].x][pers[i].y] == INF) continue;
          if ((long long)dist[x][y][pers[i].x][pers[i].y] * pers[i].t <= ans) {
            if (pers[i].gender) {
              flow.add_edge(2 * (x * N + y) + k + 1, i, 1);
            } else {
              flow.add_edge(i, 2 * (x * N + y) + k, 1);
            }
          }
        }
  }
  for (int x = 0; x < h; x++)
    for (int y = 0; y < w; y++)
      if (place[x][y]) {
        flow.add_edge(2 * (x * N + y) + k, 2 * (x * N + y) + k + 1, 1);
      }
  return flow.dinic() * 2 == k;
}
long long bs(int h, int w) {
  long long l = -1, r = INF;
  while (r - l > 1) {
    long long m = (l + r) / 2;
    if (check_ans(m, h, w)) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}
void pre_build(int h, int w) {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++) dist[i][j][x][y] = INF;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (place[i][j]) {
        great_bfs(i, j);
      }
}
int main() {
  ios_base::sync_with_stdio(0);
  int h, w, m, f;
  cin >> h >> w >> m >> f;
  if (abs(m - f) != 1) {
    cout << -1;
    return 0;
  }
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) place[i][j] = 0;
  for (int i = 0; i < h; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < w; j++) {
      place[i][j] = (s[j] == '.');
    }
  }
  pre_build(h, w);
  Person p;
  cin >> p.x >> p.y >> p.t;
  --p.x;
  --p.y;
  p.gender = (int)(m < f);
  pers.push_back(p);
  for (int i = 0; i < m; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    pers.push_back(Person(1, x - 1, y - 1, t));
  }
  for (int i = 0; i < f; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    pers.push_back(Person(0, x - 1, y - 1, t));
  }
  long long ans = bs(h, w);
  cout << (ans != INF ? ans : -1);
}
