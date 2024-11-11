#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 7;
const int maxn = 1010;
long long w[maxn];
int vis[maxn];
vector<int> g[maxn];
long long res = 0;
void down(int x, int f, long long W) {
  res += w[x] * W % inf;
  for (int i = 0; i < g[x].size(); ++i) {
    int y = g[x][i];
    if (y == f) {
      continue;
    }
    if (vis[y]) {
      continue;
    }
    down(y, x, W);
  }
}
int fa[maxn], dep[maxn];
bool check(int u, int v) {
  while (u != v) {
    if (dep[u] > dep[v]) {
      if (vis[u]) {
        return false;
      }
      u = fa[u];
    } else if (dep[v] > dep[u]) {
      if (vis[v]) {
        return false;
      }
      v = fa[v];
    } else {
      if (vis[u] || vis[v]) {
        return false;
      }
      u = fa[u];
      v = fa[v];
    }
  }
  return (vis[u] == 0);
}
void paint(int u, int v, int c) {
  while (u != v) {
    if (dep[u] > dep[v]) {
      vis[u] = c;
      u = fa[u];
    } else if (dep[v] > dep[u]) {
      vis[v] = c;
      v = fa[v];
    } else {
      vis[u] = vis[v] = c;
      u = fa[u];
      v = fa[v];
    }
  }
  vis[u] = c;
}
int N, K, U[maxn], V[maxn];
void dfs(int x, int msk, long long W) {
  down(x, x, W);
  for (int i = 0; i < K; ++i) {
    if ((msk >> i) & 1) {
      if (!vis[V[i]] && check(x, U[i])) {
        paint(x, U[i], 1);
        if (!vis[V[i]]) {
          dfs(V[i], msk ^ (1 << i), W);
        }
        paint(x, U[i], 0);
      }
      if (!vis[U[i]] && check(x, V[i])) {
        paint(x, V[i], 1);
        if (!vis[U[i]]) {
          dfs(U[i], msk ^ (1 << i), W);
        }
        paint(x, V[i], 0);
      }
    }
  }
}
long long subtree(int u) {
  long long cnt = 0, nn = N;
  for (long long lef = u, rig = u; lef <= N; lef = lef * 2, rig = rig * 2 + 1) {
    cnt += min(rig, nn) - lef + 1;
  }
  return cnt;
}
int main() {
  cin >> N >> K;
  int uu[4], vv[4];
  vector<int> R;
  R.push_back(1);
  for (int i = 0; i < K; ++i) {
    cin >> uu[i] >> vv[i];
    for (int k = uu[i]; k > 0; k /= 2) {
      R.push_back(k);
    }
    for (int k = vv[i]; k > 0; k /= 2) {
      R.push_back(k);
    }
  }
  sort(R.begin(), R.end());
  int M = unique(R.begin(), R.end()) - R.begin();
  for (int i = 0; i < K; ++i) {
    U[i] = lower_bound(R.begin(), R.begin() + M, uu[i]) - R.begin() + 1;
    V[i] = lower_bound(R.begin(), R.begin() + M, vv[i]) - R.begin() + 1;
  }
  for (int i = 0; i < M; ++i) {
    int u = i + 1;
    dep[u] = dep[fa[u]] + 1;
    w[u] = 1;
    for (int j = 0; j < 2; ++j) {
      int v =
          lower_bound(R.begin(), R.begin() + M, R[i] * 2 + j) - R.begin() + 1;
      if (v <= M && R[v - 1] == R[i] * 2 + j) {
        fa[v] = u;
        g[u].push_back(v);
        g[v].push_back(u);
      } else {
        w[u] += subtree(R[i] * 2 + j);
      }
    }
  }
  for (int i = 1; i <= M; ++i) {
    dfs(i, (1 << K) - 1, w[i]);
  }
  cout << res << endl;
  return 0;
}
