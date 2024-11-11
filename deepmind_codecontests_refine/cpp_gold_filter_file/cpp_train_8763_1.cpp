#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200010];
vector<int> tmp[200010];
int dep[200010];
int deps[200010];
int sz[200010];
int dfs(int u, int fa = 0) {
  for (auto v : adj[u])
    if (v != fa) {
      dfs(v, u);
      deps[u] = max(deps[u], deps[v] + 1);
    }
}
int rdfs(int u, int fa = 0) {
  for (auto v : adj[u])
    if (v != fa) {
      dep[v] = dep[u] + 1;
      for (auto first : adj[u])
        if (first != fa and first != v) {
          dep[v] = max(dep[v], deps[first] + 2);
        }
    }
  for (auto v : adj[u])
    if (v != fa) rdfs(v, u);
}
int gt(int u, int fa = 0) {
  sz[u] = 1;
  for (auto v : adj[u])
    if (v != fa) {
      gt(v, u);
      sz[u] += sz[v];
    }
  return 0;
}
int erase(int u, int v) {
  vector<int> res;
  for (auto first : adj[u])
    if (first != v) res.push_back(first);
  sort(res.begin(), res.end());
  sort(adj[u].begin(), adj[u].end());
  if (adj[u] == res) {
    assert(0);
    return 0;
  }
  adj[u] = res;
  return 1;
}
int ok(int root, int fa = 0) {
  if (adj[root].size() == 1) return 1;
  int tot = 1, cnt = 0;
  vector<int> res;
  for (auto v : adj[root])
    if (v != fa) {
      int first = ok(v, root);
      if (first == -1) return -1;
      cnt++;
      res.push_back(first);
      tot += first;
    }
  if (cnt != 2) return -1;
  if (res[0] != res[1]) return -1;
  return tot;
}
vector<int> ans;
int Solve(int root, int N) {
  for (int i = 1; i <= N; i++) adj[i] = tmp[i];
  adj[N + 1].clear();
  memset(dep, 0, sizeof dep);
  memset(deps, 0, sizeof deps);
  memset(sz, 0, sizeof sz);
  gt(root);
  int bad = 0;
  if (adj[root].size() == 1 || adj[root].size() == 4) {
    return 0;
  }
  if (adj[root].size() == 3) {
    bad = root;
  } else {
    int cnt = 0;
    for (int i = 1; i <= N; i++)
      if (i != root)
        if (adj[i].size() == 2) {
          cnt++;
          bad = i;
        }
    for (int i = 1; i <= N; i++)
      if (adj[i].size() == 4) {
        cnt++;
        bad = i;
      }
    if (cnt != 1) return 0;
  }
  if (bad != root and adj[bad].size() == 2) {
    adj[bad].push_back(N + 1);
    adj[N + 1].push_back(bad);
    if (ok(root)) {
      ans.push_back(bad);
      return 0;
    }
    return 0;
  }
  sort(adj[bad].begin(), adj[bad].end(),
       [&](int u, int v) { return sz[u] < sz[v]; });
  int u = adj[bad][0], v = adj[bad][1];
  erase(bad, u);
  erase(u, bad);
  erase(bad, v);
  erase(v, bad);
  adj[u].push_back(N + 1);
  adj[v].push_back(N + 1);
  adj[bad].push_back(N + 1);
  adj[N + 1].push_back(u);
  adj[N + 1].push_back(v);
  adj[N + 1].push_back(bad);
  if (ok(root) != -1) ans.push_back(bad);
  return 0;
}
int main() {
  int n;
  cin >> n;
  int N = (1 << n) - 2;
  for (int i = 1; i < N; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (n == 2) {
    cout << 2 << endl;
    cout << 1 << ' ' << 2 << endl;
    return 0;
  }
  for (int i = 1; i <= N; i++)
    if (adj[i].size() >= 5) {
      cout << 0 << endl;
      return 0;
    }
  int root = 2;
  dfs(1);
  rdfs(1);
  for (int i = 1; i <= N; i++) dep[i] = max(dep[i], deps[i]);
  vector<int> pp;
  for (int i = 1; i <= N; i++)
    if (dep[i] <= n - 1) {
      pp.push_back(i);
    }
  for (int i = 1; i <= N; i++) tmp[i] = adj[i];
  for (auto first : pp) {
    Solve(first, N);
  }
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  cout << ans.size() << endl;
  for (auto first : ans) {
    cout << first << endl;
  }
}
