#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
const int maxm = (1e4 + 10) * 2;
const int INF = 1e9;
struct Edge {
  int to, reverseIndex, cap, flow;
};
int n, m, s, t, maxFlow, dis[maxn], a[maxn];
vector<Edge> g[maxn];
vector<pair<int, int> > pari[2];
bool mark[maxm], mark1[maxn];
vector<vector<int> > ans;
vector<int> temp;
bool bfs() {
  for (int i = 0; i < maxn; i++) dis[i] = INF;
  queue<int> q;
  q.push(s);
  dis[s] = 0;
  while (q.size() > 0) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < g[v].size(); i++) {
      Edge x = g[v][i];
      int u = x.to;
      if (dis[u] == INF && x.flow < x.cap) {
        dis[u] = dis[v] + 1;
        q.push(u);
      }
    }
  }
  return (dis[t] != INF);
}
int dfs(int v, int f) {
  if (v == t) return f;
  for (int i = 0; i < g[v].size(); i++) {
    Edge &x = g[v][i];
    int u = x.to;
    if (x.cap <= x.flow) continue;
    if (dis[u] == dis[v] + 1) {
      int tmp = dfs(u, min(f, x.cap - x.flow));
      if (tmp > 0) {
        x.flow += tmp;
        g[u][x.reverseIndex].flow -= tmp;
        return tmp;
      }
    }
  }
  return 0;
}
void dinic() {
  while (bfs()) {
    while (int tmp = dfs(s, INF)) maxFlow += tmp;
  }
}
void dfs(int v) {
  mark1[v] = true;
  temp.push_back(v);
  for (int i = 0; i < g[v].size(); i++) {
    Edge e = g[v][i];
    if ((e.flow == 1 || e.flow == -1) && !mark1[e.to] && e.to != s &&
        e.to != t) {
      dfs(e.to);
      break;
    }
  }
}
int main() {
  mark[1] = 1;
  for (int i = 2; i < maxm; i++)
    if (!mark[i])
      for (int j = i * 2; j < maxm; j += i) mark[j] = 1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pari[a[i] % 2].push_back(make_pair(a[i], i));
  }
  if (pari[0].size() != pari[1].size()) {
    cout << "Impossible" << endl;
    return 0;
  }
  s = 0, t = n + 1;
  for (int i = 0; i < pari[0].size(); i++) {
    Edge e, e1;
    e.to = pari[0][i].second;
    e.reverseIndex = g[pari[0][i].second].size();
    e.cap = 2;
    e.flow = 0;
    e1.to = s;
    e1.reverseIndex = g[s].size();
    e1.cap = 0;
    e1.flow = 0;
    g[s].push_back(e);
    g[pari[0][i].second].push_back(e1);
    e.to = pari[1][i].second;
    e.reverseIndex = g[pari[1][i].second].size();
    e.cap = 0;
    e.flow = 0;
    e1.to = t;
    e1.reverseIndex = g[t].size();
    e1.cap = 2;
    e1.flow = 0;
    g[t].push_back(e);
    g[pari[1][i].second].push_back(e1);
  }
  for (int i = 0; i < pari[0].size(); i++) {
    for (int j = 0; j < pari[1].size(); j++) {
      if (!mark[pari[0][i].first + pari[1][j].first]) {
        Edge e, e1;
        e.to = pari[0][i].second;
        e.reverseIndex = g[pari[0][i].second].size();
        e.cap = 1;
        e.flow = 0;
        e1.to = pari[1][j].second;
        e1.reverseIndex = g[pari[1][j].second].size();
        e1.cap = 1;
        e1.flow = 0;
        g[pari[1][j].second].push_back(e);
        g[pari[0][i].second].push_back(e1);
      }
    }
  }
  dinic();
  if (maxFlow != n) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<vector<int> > ans;
  for (int i = 0; i < pari[0].size(); i++) {
    int v = pari[0][i].second;
    if (!mark1[v]) {
      temp.clear();
      mark1[v] = 1;
      temp.push_back(v);
      for (int j = 0; j < g[v].size(); j++) {
        Edge e = g[v][j];
        if (e.flow == 1 && !mark1[e.to] && e.to != s && e.to != t) {
          dfs(e.to);
          ans.push_back(temp);
          break;
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].size() << ' ';
    for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << ' ';
    cout << endl;
  }
}
