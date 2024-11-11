#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const int M = 300;
int S, T, n, m, p;
int gr[M][M];
bool vis[M];
int parent[M];
int cap[M][M];
int beg[M][M];
bool crivao[100000];
void build_crivo() {
  for (int i = 2; i < 100000; i++) {
    if (!crivao[i]) {
      for (int j = i + i; j < 500; j += i) {
        crivao[j] = true;
      }
    }
  }
}
void insertEdge(int u, int v, int capacidade) {
  gr[u][v] = 1;
  cap[u][v] = capacidade;
  beg[u][v] = capacidade;
  gr[v][u] = 1;
  cap[v][u] = 0;
}
int bfs() {
  memset(vis, false, sizeof vis);
  memset(parent, -1, sizeof parent);
  vis[S] = true;
  queue<pair<int, int> > q;
  q.push(make_pair(S, INT_MAX));
  while (!q.empty()) {
    int u = q.front().first;
    int flow = q.front().second;
    q.pop();
    if (u == T) {
      for (int v = T; v != S; v = parent[v]) {
        cap[parent[v]][v] -= flow;
        cap[v][parent[v]] += flow;
      }
      return flow;
    }
    for (int v = 0; v < M; v++) {
      if (!gr[u][v]) continue;
      if (!vis[v] and cap[u][v] > 0) {
        q.push(make_pair(v, min(flow, cap[u][v])));
        vis[v] = true;
        parent[v] = u;
      }
    }
  }
  return 0;
}
int main(void) {
  build_crivo();
  S = 250;
  T = 251;
  scanf("%d", &n);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
    if (x % 2) {
      insertEdge(i, T, 2);
    } else {
      insertEdge(S, i, 2);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!crivao[v[i] + v[j]]) {
        if (v[i] % 2) {
          insertEdge(j, i, 1);
        } else {
          insertEdge(i, j, 1);
        }
      }
    }
  }
  int ans = 0, flow;
  while (flow = bfs()) {
    ans += flow;
  }
  if (ans == n) {
    vector<vector<int> > resp;
    set<int> s;
    for (int i = 0; i < n; i++) {
      s.insert(i);
    }
    while (!s.empty()) {
      int k = *(s.begin());
      vector<int> x;
      while (s.count(k)) {
        x.push_back(k);
        s.erase(k);
        if (v[k] % 2) {
          for (int i = 0; i < n; i++) {
            if (beg[i][k] and !cap[i][k] and s.count(i)) {
              k = i;
              break;
            }
          }
        } else {
          for (int i = 0; i < n; i++) {
            if (beg[k][i] and !cap[k][i] and s.count(i)) {
              k = i;
              break;
            }
          }
        }
      }
      resp.push_back(x);
    }
    cout << resp.size() << endl;
    for (int i = 0; i < resp.size(); i++) {
      cout << resp[i].size() << " ";
      for (int j = 0; j < resp[i].size(); j++) {
        printf("%d ", resp[i][j] + 1);
      }
      cout << endl;
    }
  } else
    printf("Impossible\n");
  return 0;
}
