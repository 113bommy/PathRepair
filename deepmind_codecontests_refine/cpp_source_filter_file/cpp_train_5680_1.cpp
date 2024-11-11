#include <bits/stdc++.h>
using namespace std;
const int N = 222;
const long long INF = 1e9 + 19;
struct Edge {
  int v, f, mf, c, pid;
};
int n, m;
int st, fn, all;
vector<Edge> e[N];
void addE(int v, int u, int f, int c) {
  int szV = e[v].size();
  int szU = e[u].size();
  e[v].push_back({u, 0, f, c, szU});
  e[u].push_back({v, 0, 0, -c, szV});
}
int dist[N];
bool inq[N];
int p[N];
int pid[N];
int answer = 0;
bool bfs() {
  memset(inq, 0, sizeof(inq));
  memset(dist, 63, sizeof(dist));
  queue<int> q;
  q.push(st);
  dist[st] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    inq[v] = 1;
    for (int i = 0; i < (int)e[v].size(); i++) {
      auto x = e[v][i];
      int u = x.v;
      if (dist[u] > dist[v] + x.c && x.f < x.mf) {
        dist[u] = dist[v] + x.c;
        p[u] = v;
        pid[u] = i;
        if (!inq[u]) {
          q.push(u);
          inq[u] = 1;
        }
      }
    }
  }
  if (dist[fn] < INF) {
    int flow = INF;
    int v = fn;
    for (; v != st; v = p[v])
      flow = min(flow, e[p[v]][pid[v]].mf - e[p[v]][pid[v]].f);
    v = fn;
    answer += flow * dist[fn];
    for (; v != st; v = p[v]) {
      int u = p[v];
      int id = pid[v];
      e[u][id].f += flow;
      e[v][e[u][id].pid].f -= flow;
    }
    return 1;
  }
  return 0;
}
void read() {
  scanf("%d%d", &n, &m);
  st = n;
  fn = n + 1;
  all = n + 2;
  addE(n - 1, 0, INF, 0);
  for (int i = 0; i < m; i++) {
    int v, u, c, f;
    scanf("%d%d%d%d", &v, &u, &c, &f);
    v--;
    u--;
    addE(st, u, f, 0);
    addE(v, fn, f, 0);
    if (f <= c) {
      addE(u, v, f, 1);
      addE(v, u, c - f, 1);
      addE(v, u, INF, 2);
    } else {
      answer += f - c;
      addE(u, v, f - c, 0);
      addE(u, v, c, 1);
      addE(v, u, INF, 2);
    }
  }
}
void solve() {
  while (bfs())
    ;
  cout << answer << endl;
}
void stress() {}
int main() {
  if (1) {
    int k = 1;
    for (int tt = 0; tt < k; tt++) {
      read();
      solve();
    }
  } else {
    stress();
  }
  return 0;
}
