#include <bits/stdc++.h>
using namespace std;
struct Edge {
  int u, v;
  Edge() {}
  Edge(int U, int V) : u(U), v(V) {}
};
pair<int, int> &operator+=(pair<int, int> &r, const pair<int, int> &s) {
  r.first += s.first;
  r.second += s.second;
  return r;
}
pair<int, int> &operator-=(pair<int, int> &r, const pair<int, int> &s) {
  r.first -= s.first;
  r.second -= s.second;
  return r;
}
pair<int, int> operator+(const pair<int, int> &r, const pair<int, int> &s) {
  pair<int, int> t = r;
  return t += s;
}
pair<int, int> operator-(const pair<int, int> &r, const pair<int, int> &s) {
  pair<int, int> t = r;
  return t -= s;
}
vector<vector<int> > adj;
int n, sex[100000];
pair<vector<vector<int> >, vector<Edge> > decompose() {
  static bool visited[100000];
  fill(visited, visited + n, false);
  vector<vector<int> > comps;
  vector<Edge> edges;
  for (int i = 0; i < (n); i++)
    if (!visited[i]) {
      vector<int> comp;
      Edge e;
      queue<pair<int, int> > qu;
      qu.push(make_pair(i, -1));
      visited[i] = true;
      while (!qu.empty()) {
        pair<int, int> a = qu.front();
        qu.pop();
        int u = a.first, prev = a.second;
        comp.push_back(u);
        for (int j = 0; j < (adj[u].size()); j++) {
          int v = adj[u][j];
          if (v != prev) {
            if (!visited[v]) {
              qu.push(make_pair(v, u));
              visited[v] = true;
            } else
              e = Edge(u, v);
          }
        }
      }
      comps.push_back(comp);
      edges.push_back(e);
    }
  return make_pair(comps, edges);
}
pair<int, int> dp[2][100000];
int match[100000];
short path[2][100000];
pair<int, int> go0(int u, int parent);
pair<int, int> go1(int u, int parent);
pair<int, int> go0(int u, int parent) {
  if (~dp[0][u].first) return dp[0][u];
  if (adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == parent)) {
    return dp[0][u] = pair<int, int>(0, 0);
  }
  pair<int, int> ans, ans2;
  int x = -1;
  for (int i = 0; i < (adj[u].size()); i++) {
    int v = adj[u][i];
    if (v != parent) {
      pair<int, int> tmp0 = go0(v, u), tmp1 = go1(v, u);
      ans += max(tmp0, tmp1);
      if (tmp1 < tmp0)
        path[0][v] = 0;
      else
        path[0][v] = 1;
      pair<int, int> dif = pair<int, int>(1, sex[u] == sex[v] ? 0 : 1) +
                           min(tmp1 - tmp0, pair<int, int>(0, 0));
      if (x == -1 || ans2 < dif) {
        ans2 = dif;
        x = v;
      }
    }
  }
  path[0][x] = 1;
  match[u] = x;
  return dp[0][u] = ans + ans2;
}
pair<int, int> go1(int u, int parent) {
  if (~dp[1][u].first) return dp[1][u];
  if (adj[u].size() == 0 || (adj[u].size() == 1 && adj[u][0] == parent)) {
    return dp[1][u] = pair<int, int>(0, 0);
  }
  pair<int, int> ans;
  for (int i = 0; i < (adj[u].size()); i++) {
    int v = adj[u][i];
    if (v != parent) {
      pair<int, int> tmp0 = go0(v, u), tmp1 = go1(v, u);
      ans += max(tmp0, tmp1);
      if (tmp1 < tmp0)
        path[1][v] = 0;
      else
        path[1][v] = 1;
    }
  }
  return dp[1][u] = ans;
}
void constructMatchings(int u, int parent, int type, vector<Edge> &matches) {
  if (type == 0) matches.push_back(Edge(u, match[u]));
  for (int i = 0; i < (adj[u].size()); i++) {
    int v = adj[u][i];
    if (v != parent) {
      if (path[type][v] == 0)
        constructMatchings(v, u, 0, matches);
      else
        constructMatchings(v, u, 1, matches);
    }
  }
}
void deleteNode(int u) {
  for (int i = 0; i < (adj[u].size()); i++) {
    int v = adj[u][i];
    adj[v].erase(find((adj[v]).begin(), (adj[v]).end(), u));
  }
  adj[u].clear();
}
void deleteEdge(const Edge &e) {
  int u = e.u, v = e.v;
  adj[u].erase(find((adj[u]).begin(), (adj[u]).end(), v));
  adj[v].erase(find((adj[v]).begin(), (adj[v]).end(), u));
}
pair<pair<int, int>, vector<Edge> > solve(const vector<int> &V, const Edge &e) {
  int u = e.u, v = e.v;
  deleteEdge(e);
  pair<int, int> tmp0 = go0(u, -1);
  for (int k = 0; k < (2); k++)
    for (int i = 0; i < (V.size()); i++) dp[k][V[i]] = pair<int, int>(-1, 0);
  pair<int, int> tmp1 = go1(u, -1);
  pair<int, int> r1 = max(tmp0, tmp1);
  vector<Edge> matches;
  if (tmp0 < tmp1)
    constructMatchings(u, -1, 1, matches);
  else
    constructMatchings(u, -1, 0, matches);
  vector<int> cand = adj[v];
  vector<pair<int, int> > res;
  deleteNode(v);
  for (int k = 0; k < (2); k++)
    for (int i = 0; i < (V.size()); i++) dp[k][V[i]] = pair<int, int>(-1, 0);
  pair<int, int> r2 = go1(u, -1) + pair<int, int>(1, sex[u] == sex[v] ? 0 : 1);
  for (int i = 0; i < (cand.size()); i++) {
    int x = cand[i];
    if (dp[1][x].first == -1) {
      pair<int, int> t0 = go0(x, -1), t1 = go1(x, -1);
      r2 += max(t0, t1);
      if (t0 < t1)
        res.push_back(make_pair(x, 1));
      else
        res.push_back(make_pair(x, 0));
    }
  }
  if (r1 < r2) {
    matches.clear();
    constructMatchings(u, -1, 1, matches);
    for (int i = 0; i < (res.size()); i++) {
      constructMatchings(res[i].first, -1, res[i].second, matches);
    }
    matches.push_back(Edge(u, v));
    r1 = r2;
  }
  return make_pair(r1, matches);
}
int main() {
  scanf("%d", &n);
  adj.resize(n);
  for (int u = 0; u < (n); u++) {
    int v;
    scanf("%d%d", &v, sex + u);
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  pair<vector<vector<int> >, vector<Edge> > res = decompose();
  vector<vector<int> > &comps = res.first;
  vector<Edge> &edges = res.second;
  for (int k = 0; k < (2); k++)
    for (int u = 0; u < (n); u++) dp[k][u] = pair<int, int>(-1, 0);
  memset(match, -1, sizeof match);
  memset(path, -1, sizeof path);
  pair<int, int> ans;
  vector<Edge> matches;
  for (int i = 0; i < (comps.size()); i++) {
    pair<pair<int, int>, vector<Edge> > tmp = solve(comps[i], edges[i]);
    ans += tmp.first;
    matches.insert(matches.end(), (tmp.second).begin(), (tmp.second).end());
  }
  printf("%d %d\n", ans.first, ans.second);
  for (int i = 0; i < (matches.size()); i++)
    printf("%d %d\n", matches[i].u + 1, matches[i].v + 1);
  return 0;
}
