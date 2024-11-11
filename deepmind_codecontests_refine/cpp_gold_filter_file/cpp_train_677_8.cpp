#include <bits/stdc++.h>
using namespace std;
using namespace std;
const int N = 3030;
const int INF = (int)2e9;
int n, m;
int len[N];
int f[N][N];
vector<int> g[N];
vector<int> gr[N];
vector<pair<int, int> > have[N];
vector<pair<int, int> > gave[N];
queue<int> q;
void bfs(int v) {
  for (int i = 1; i <= n; i++) len[i] = INF;
  len[v] = 0;
  q.push(v);
  while (!q.empty()) {
    int ver = q.front();
    q.pop();
    for (int i = 0; i < (int)g[ver].size(); i++) {
      int to = g[ver][i];
      if (len[to] > len[ver] + 1) {
        len[to] = len[ver] + 1;
        q.push(to);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    f[v][i] = len[i];
    if (len[i] != INF && i != v) {
      gave[i].push_back(make_pair(len[i], v));
    }
  }
  for (int i = 1; i <= n; i++) len[i] = INF;
  len[v] = 0;
  q.push(v);
  while (!q.empty()) {
    int ver = q.front();
    q.pop();
    for (int i = 0; i < (int)gr[ver].size(); i++) {
      int to = gr[ver][i];
      if (len[to] > len[ver] + 1) {
        len[to] = len[ver] + 1;
        q.push(to);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (len[i] != INF && i != v) {
      have[i].push_back(make_pair(len[i], v));
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    gr[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    bfs(i);
  }
  for (int i = 1; i <= n; i++) {
    sort(have[i].begin(), have[i].end());
    reverse(have[i].begin(), have[i].end());
    sort(gave[i].begin(), gave[i].end());
    reverse(gave[i].begin(), gave[i].end());
  }
  int res = 0;
  int a, b, c, d, sz, ptr, cost;
  for (int i = 1; i <= n; i++) {
    sz = min(4, (int)gave[i].size());
    for (int idx = 0; idx < sz; idx++) {
      for (int j = 1; j <= n; j++) {
        if (j == i) continue;
        if (f[i][j] == INF) continue;
        ptr = 0;
        while (true) {
          if (ptr >= (int)have[j].size()) break;
          if (have[j][ptr].second == i ||
              have[j][ptr].second == gave[i][idx].second ||
              j == gave[i][idx].second) {
            ++ptr;
            continue;
          } else {
            cost = gave[i][idx].first + f[i][j] + have[j][ptr].first;
            if (cost > res) {
              res = cost;
              a = gave[i][idx].second;
              b = i;
              c = j;
              d = have[j][ptr].second;
            }
            break;
          }
        }
      }
    }
  }
  printf("%d %d %d %d\n", a, b, c, d);
  return 0;
}
