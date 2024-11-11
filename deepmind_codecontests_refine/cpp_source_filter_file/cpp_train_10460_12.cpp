#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, d[N], up[N][19], tin[N], tout[N], timer, sz[N], parent[N];
vector<int> adj[N], qu[N], qu2[N], eh[N];
void dfs(int v, int pr = 0) {
  tin[v] = ++timer;
  parent[v] = pr;
  sz[v] = 1;
  d[v] = d[pr] + 1;
  up[v][0] = pr;
  for (int i = 1; i < 19; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (auto to : adj[v]) {
    if (to != pr) dfs(to, v), sz[v] += sz[to];
  }
  tout[v] = timer;
}
bool predok(int a, int b) { return tin[a] <= tin[b] && tout[a] >= tout[b]; }
int lca(int a, int b) {
  if (d[a] > d[b]) swap(a, b);
  for (int i = 18; i >= 0; i--) {
    if (d[up[b][i]] >= d[a]) b = up[b][i];
  }
  if (a == b) return a;
  for (int i = 18; i >= 0; i--) {
    if (up[a][i] != up[b][i]) {
      a = up[a][i];
      b = up[b][i];
    }
  }
  return up[a][0];
}
int get(int a, int b) {
  int pr = a;
  for (int i = 18; i >= 0; i--) {
    if (!up[a][i]) continue;
    int dist = d[pr] - d[up[a][i]];
    int dist2;
    if (d[b] <= d[up[a][i]])
      dist2 = d[up[a][i]] - d[b];
    else
      dist2 = d[b] - d[up[a][i]];
    if (dist <= dist2) a = up[a][i];
  }
  return a;
}
int Get(int a, int b) {
  int pr = a;
  for (int i = 18; i >= 0; i--) {
    if (!up[a][i]) continue;
    int dist = d[pr] - d[up[a][i]];
    int dist2;
    if (d[b] <= d[up[a][i]])
      dist2 = d[up[a][i]] - d[b];
    else
      dist2 = d[b] - d[up[a][i]];
    if (dist < dist2) a = up[a][i];
  }
  return a;
}
int main() {
  ios ::sync_with_stdio(0), cin.tie(0);
  int m;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    eh[a].push_back(i);
    adj[a].push_back(b);
    adj[b].push_back(a);
    eh[b].push_back(i);
  }
  dfs(1);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << n << '\n';
      continue;
    }
    if (d[a] < d[b]) swap(a, b);
    int l = lca(a, b);
    int dist = d[a] + d[b] - 2 * d[l];
    if (dist & 1) {
      cout << 0 << '\n';
      continue;
    }
    dist /= 2;
    int v;
    {
      int A = a;
      for (int i = 18; i >= 0; i--) {
        if (d[a] - d[up[A][i]] <= dist) A = up[A][i];
      }
      v = A;
    }
    int dela;
    {
      int A = a;
      for (int i = 18; i >= 0; i--) {
        if (d[up[A][i]] > d[v]) A = up[A][i];
      }
      dela = A;
    }
    int ans;
    if (!predok(v, b)) {
      ans = sz[v] - sz[dela];
      assert(ans != 81274);
    } else {
      int delb;
      {
        int B = b;
        for (int i = 18; i >= 0; i--) {
          if (d[B] - d[up[B][i]] < dist) B = up[B][i];
        }
        delb = B;
      }
      ans = n - sz[dela] - sz[delb];
    }
    cout << ans << '\n';
  }
  return 0;
}
