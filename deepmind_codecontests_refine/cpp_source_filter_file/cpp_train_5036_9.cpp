#include <bits/stdc++.h>
const int MAXN = 1000005;
using namespace std;
struct edge {
  int to, cap, dir, ind;
};
vector<edge> G[MAXN];
int flow[MAXN], d[MAXN];
void mainp() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    edge temp;
    temp.to = v;
    temp.cap = c;
    temp.dir = 0;
    temp.ind = i;
    flow[v] += c;
    flow[u] += c;
    G[u].push_back(temp);
    temp.to = u;
    temp.cap = c;
    temp.dir = 1;
    temp.ind = i;
    G[v].push_back(temp);
  }
  for (int i = 0; i <= n; i++) flow[i] /= 2;
  for (int i = 0; i <= n; i++) d[i] = -1;
  queue<int> C;
  C.push(1);
  while (C.size()) {
    int u = C.front();
    C.pop();
    for (int i = 0; i < G[u].size(); i++) {
      int v = G[u][i].to;
      int in = G[u][i].ind;
      int ca = G[u][i].cap;
      int di = G[u][i].dir;
      if (d[in] == -1) {
        flow[v] -= ca;
        d[in] = di;
        if (flow[v] == 0 && v != n) C.push(v);
      }
    }
  }
  for (int i = 0; i < m; i++) cout << d[i] << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  mainp();
  return 0;
}
