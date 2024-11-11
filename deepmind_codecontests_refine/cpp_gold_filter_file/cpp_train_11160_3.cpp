#include <bits/stdc++.h>
using namespace std;
int debug = 0;
const int N = 5e5 + 5, mod = 1e9 + 7, Log = 21;
vector<int> adj[N];
int label[N], memo[N][Log], depth[N], fact[N];
int firstEdge[N], lastEdge[N];
map<int, int> nextEdge[N], prevEdge[N];
void dfs(int node, int prev, int Depth) {
  depth[node] = Depth;
  memo[node][0] = prev;
  for (int i = 1; i < Log; ++i) {
    memo[node][i] = memo[memo[node][i - 1]][i - 1];
  }
  for (int to : adj[node]) {
    if (to == prev) continue;
    dfs(to, node, Depth + 1);
  }
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  int diff = depth[x] - depth[y];
  for (int k = Log - 1; k >= 0; --k) {
    if (diff & (1 << k)) {
      x = memo[x][k];
    }
  }
  for (int k = Log - 1; k >= 0; --k) {
    if (memo[x][k] != memo[y][k]) {
      x = memo[x][k];
      y = memo[y][k];
    }
  }
  if (x != y) x = memo[x][0];
  return x;
}
int Dist(int x, int y) { return depth[x] + depth[y] - 2 * depth[LCA(x, y)]; }
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<pair<int, int>, int> edgeId;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    if (u > v) swap(u, v);
    edgeId[{u, v}] = i;
  }
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = 1LL * i * fact[i - 1] % mod;
    cin >> label[i];
    if (label[i] == i) {
      if (debug) cout << 1 << '\n';
      cout << 0;
      return 0;
    }
  }
  dfs(1, 1, 0);
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (label[i] == 0) continue;
    sum += Dist(i, label[i]);
    if (sum > 2 * n - 2) {
      if (debug) cout << 2 << '\n';
      cout << 0;
      return 0;
    }
    vector<int> path;
    {
      vector<int> temp;
      int x = label[i], y = i;
      while (x != y) {
        if (depth[x] < depth[y]) {
          temp.push_back(y);
          y = memo[y][0];
        } else {
          path.push_back(x);
          x = memo[x][0];
        }
      }
      path.push_back(x);
      for (int i = (int)temp.size() - 1; i >= 0; --i) path.push_back(temp[i]);
    }
    if (path.size() <= 1) {
      assert(path.size() == 1);
      continue;
    }
    const int firstID = edgeId[{min(path[0], path[1]), max(path[0], path[1])}];
    if (firstEdge[path[0]] != 0 && firstEdge[path[0]] != firstID) {
      if (debug) cout << 3 << '\n';
      cout << 0;
      return 0;
    }
    firstEdge[path[0]] = firstID;
    const int lastID = edgeId[{min(path.back(), path[path.size() - 2]),
                               max(path.back(), path[path.size() - 2])}];
    if (lastEdge[path.back()] != 0 && lastEdge[path.back()] != lastID) {
      if (debug) cout << 4 << '\n';
      cout << 0;
      return 0;
    }
    lastEdge[path.back()] = lastID;
    for (int i = 1; i + 1 < path.size(); ++i) {
      const int u = path[i - 1];
      const int v = path[i];
      const int w = path[i + 1];
      assert(u != v);
      assert(v != w);
      int edge1 = edgeId[{min(u, v), max(u, v)}];
      int edge2 = edgeId[{min(w, v), max(w, v)}];
      if (nextEdge[v].count(edge1) && nextEdge[v][edge1] != edge2) {
        if (debug) cout << 5 << '\n';
        cout << 0;
        return 0;
      }
      nextEdge[v][edge1] = edge2;
      if (prevEdge[v].count(edge2) && prevEdge[v][edge2] != edge1) {
        if (debug) cout << 6 << '\n';
        cout << 0;
        return 0;
      }
      prevEdge[v][edge2] = edge1;
    }
  }
  int res = 1;
  for (int i = 1; i <= n; ++i) {
    set<int> seen;
    if (firstEdge[i] != 0) {
      int curr = firstEdge[i];
      int cntEdges = 1;
      seen.insert(curr);
      while (nextEdge[i].count(curr) && curr != lastEdge[i]) {
        curr = nextEdge[i][curr];
        seen.insert(curr);
        ++cntEdges;
      }
      assert(cntEdges <= adj[i].size());
      if (curr == lastEdge[i] && cntEdges < adj[i].size()) {
        if (debug) cout << 7 << '\n';
        cout << 0;
        return 0;
      }
    }
    if (lastEdge[i] != 0) {
      int curr = lastEdge[i];
      seen.insert(curr);
      while (prevEdge[i].count(curr) && curr != firstEdge[i]) {
        curr = prevEdge[i][curr];
        seen.insert(curr);
      }
    }
    int cnt = 0;
    for (int to : adj[i]) {
      int currEdge = edgeId[{min(i, to), max(i, to)}];
      if (seen.count(currEdge)) continue;
      ++cnt;
      queue<pair<int, int>> q;
      q.push({currEdge, currEdge});
      while (!q.empty()) {
        currEdge = q.front().first;
        int parEdge = q.front().second;
        q.pop();
        seen.insert(currEdge);
        if (prevEdge[i].count(currEdge)) {
          const int &to = prevEdge[i][currEdge];
          if (to != parEdge && seen.count(to)) {
            if (debug) cout << 8 << '\n';
            cout << 0;
            return 0;
          }
          if (!seen.count(to)) {
            seen.insert(to);
            q.push({to, currEdge});
          }
        }
        if (nextEdge[i].count(currEdge)) {
          const int &to = nextEdge[i][currEdge];
          if (to != parEdge && seen.count(to)) {
            if (debug) cout << 9 << '\n';
            cout << 0;
            return 0;
          }
          if (!seen.count(to)) {
            seen.insert(to);
            q.push({to, currEdge});
          }
        }
      }
    }
    res = 1LL * res * fact[cnt] % mod;
  }
  cout << res << '\n';
}
