#include <bits/stdc++.h>
using namespace std;
const int N = 1000 + 5;
const int M = 2055;
int n;
pair<int, int> a[N];
int rg[N], dw[N];
int pmap[N][N], p1[N][N], p2[N][N];
vector<int> M1[N], M2[N];
bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
  return (y1 <= y3 and y3 <= y2) and (x3 <= x1 and x1 <= x4) and !pmap[x1][y3];
}
const int maxn = (int)1e6 + 11111;
struct edge {
  int v, u, f, c;
  edge() {}
  edge(int v, int u, int f, int c) : v(v), u(u), f(f), c(c) {}
};
edge mas[maxn];
int posit = 0;
vector<int> ed[M];
void add_edge(int v, int u) {
  mas[posit] = edge(v, u, 0, 1);
  ed[v].push_back(posit++);
  mas[posit] = edge(u, v, 0, 0);
  ed[u].push_back(posit++);
}
int d[M];
int iter[M];
int num = 2;
const int inf = (int)1e9;
bool bfs(int s, int t) {
  for (int i = 0; i < num; i++) {
    d[i] = inf;
    iter[i] = 0;
  }
  d[s] = 0;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < (int)ed[v].size(); i++) {
      int it = ed[v][i];
      int u = mas[it].u;
      if (mas[it].f != mas[it].c && d[u] == inf) {
        d[u] = d[v] + 1;
        q.push(u);
      }
    }
  }
  return d[t] != inf;
}
int dfs(int s, int t, int c) {
  if (s == t) {
    return c;
  }
  int w = 0;
  while (iter[s] != (int)ed[s].size()) {
    int it = ed[s][iter[s]];
    int u = mas[it].u;
    if (d[u] == d[s] + 1) {
      int cnt = dfs(u, t, min(c, mas[it].c - mas[it].f));
      mas[it].f += cnt;
      mas[it ^ 1].f -= cnt;
      w += cnt;
      c -= cnt;
      if (c == 0) {
        break;
      }
    }
    iter[s]++;
  }
  return w;
}
bool used[M];
void go(int v) {
  used[v] = true;
  for (int i = 0; i < (int)ed[v].size(); i++) {
    int it = ed[v][i];
    int u = mas[it].u;
    if (mas[it].c != mas[it].f && !used[u]) {
      go(u);
    }
  }
}
int main() {
  scanf("%d", &n);
  vector<int> vx, vy;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    vx.push_back(a[i].first);
    vy.push_back(a[i].second);
  }
  sort(vx.begin(), vx.end());
  vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
  sort(vy.begin(), vy.end());
  vy.resize(unique(vy.begin(), vy.end()) - vy.begin());
  for (int i = 1; i <= n; i++) {
    a[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin() + 1;
    a[i].second =
        lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin() + 1;
  }
  for (int i = 1; i <= n; i++) pmap[a[i].first][a[i].second] = i;
  for (int i = 1; i <= n; i++) {
    M1[a[i].first].push_back(a[i].second);
    M2[a[i].second].push_back(a[i].first);
  }
  for (int i = 1; i <= n; i++) {
    sort(M1[i].begin(), M1[i].end());
    sort(M2[i].begin(), M2[i].end());
  }
  for (int i = 1; i <= n; i++) {
    int id;
    int x, y;
    tie(x, y) = a[i];
    id = lower_bound(M1[x].begin(), M1[x].end(), y + 1) - M1[x].begin();
    rg[i] = (id == M1[x].size() ? -1 : M1[x][id]);
    id = lower_bound(M2[y].begin(), M2[y].end(), x + 1) - M2[y].begin();
    dw[i] = (id == M2[y].size() ? -1 : M2[y][id]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (rg[i] != -1 and dw[j] != -1 and
          intersect(a[i].first, a[i].second, a[i].first, rg[i], a[j].first,
                    a[j].second, dw[j], a[j].second)) {
        add_edge(i * 2 - 1, j * 2);
      }
      if (dw[i] != -1 and rg[j] != -1 and
          intersect(a[j].first, a[j].second, a[j].first, rg[j], a[i].first,
                    a[i].second, dw[i], a[i].second)) {
        add_edge(i * 2, j * 2 - 1);
      }
    }
  }
  int ss = M - 1;
  int tt = M - 2;
  num = M;
  for (int i = 1; i <= n; i++) {
    if (rg[i] != -1) add_edge(ss, i * 2 - 1);
    if (dw[i] != -1) add_edge(i * 2, tt);
  }
  while (bfs(ss, tt)) {
    dfs(ss, tt, inf);
  }
  go(ss);
  vector<int> ai, bi;
  for (int i = 1; i <= n; i++) {
    if (used[2 * i - 1] and rg[i] != -1) {
      ai.push_back(i);
    }
    if (!used[2 * i] and dw[i] != -1) {
      bi.push_back(i);
    }
  }
  for (auto x : ai) p1[a[x].first][a[x].second] = 1;
  for (auto x : bi) p2[a[x].first][a[x].second] = 1;
  vector<pair<pair<int, int>, pair<int, int>>> ans;
  for (int i = 1; i <= n; i++) {
    if (!M2[i].empty()) {
      for (int j = 0; j < M2[i].size(); j++) {
        int k = j;
        while (k < M2[i].size() and p2[M2[i][k]][i]) {
          k++;
        }
        ans.push_back({{M2[i][j], i}, {M2[i][k], i}});
        j = k;
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto l : ans)
    printf("%d %d %d %d\n", vx[l.first.first - 1], vy[l.first.second - 1],
           vx[l.second.first - 1], vy[l.second.second - 1]);
  ans.clear();
  for (int i = 1; i <= n; i++) {
    if (!M1[i].empty()) {
      for (int j = 0; j < M1[i].size(); j++) {
        int k = j;
        while (k < M1[i].size() and p1[i][M1[i][k]]) {
          k++;
        }
        ans.push_back({{i, M1[i][j]}, {i, M1[i][k]}});
        j = k;
      }
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto l : ans)
    printf("%d %d %d %d\n", vx[l.first.first - 1], vy[l.first.second - 1],
           vx[l.second.first - 1], vy[l.second.second - 1]);
  return 0;
}
