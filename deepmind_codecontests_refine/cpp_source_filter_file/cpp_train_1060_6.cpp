#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int deg[N];
int cntDeg[N];
int deg2[N];
int dist[N];
vector<int> g[N], t[N];
bool used[N];
int par[N];
bool dfsCycle(int v, int& start, int& finish) {
  used[v] = true;
  for (int u : t[v]) {
    if (u == par[v]) continue;
    if (used[u]) {
      start = u;
      finish = v;
      return true;
    } else {
      dist[u] = dist[v] + 1;
      par[u] = v;
      if (dfsCycle(u, start, finish)) return true;
    }
  }
  return false;
}
int dfsPath(int v, int start) {
  used[v] = true;
  if (deg[v] % 3 == 1 && v != start) return v;
  for (int u : g[v]) {
    if (!used[v]) {
      par[u] = v;
      int x = dfsPath(u, start);
      if (x != -1) return x;
    }
  }
  return -1;
}
bool dp[N];
void dfsDp(int v, int p) {
  dp[v] = deg2[v] >= 4;
  for (int u : t[v]) {
    if (u == p) continue;
    dfsDp(u, v);
    dp[v] |= dp[u];
  }
}
void dfsKill(int v, int p, vector<bool>& kill) {
  kill[v] = true;
  for (int u : t[v]) {
    if (u != p) dfsKill(u, v, kill);
  }
}
void dfsFind(int v, int p, vector<bool>& kill) {
  for (int u : t[v]) {
    if (u == p || !dp[u]) continue;
    dfsFind(u, v, kill);
    return;
  }
  int cntKill = 3;
  for (int u : t[v]) {
    if (!cntKill) break;
    dfsKill(u, v, kill);
    --cntKill;
  }
}
void getPath(int start, int finish, vector<int>& out) {
  for (int v = finish; v != start; v = par[v]) out.push_back(v);
  out.push_back(start);
  reverse(out.begin(), out.end());
}
bool debug = false;
bool solve(vector<bool>& kill) {
  int n, m;
  scanf("%d %d", &n, &m);
  kill.assign(n, true);
  for (int v = 0; v < n; ++v) {
    g[v].clear();
    t[v].clear();
    deg[v] = 0;
    dp[v] = false;
    used[v] = false;
    par[v] = -1;
  }
  for (int x = 0; x < n; ++x) cntDeg[x] = 0;
  while (m--) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++deg[u];
    ++deg[v];
  }
  if (n <= 3) return false;
  for (int v = 0; v < n; ++v) ++cntDeg[deg[v]];
  if (cntDeg[1] == 2 && cntDeg[2] == n - 2) return false;
  if (cntDeg[2] == n) return false;
  if (cntDeg[4] == 1 && cntDeg[2] == n - 1) return false;
  for (int v = 0; v < n; ++v) {
    if (deg[v] % 3 == 2) {
      for (int u : g[v])
        if (deg[u] % 3 == 2) t[v].push_back(u);
    }
  }
  for (int v = 0; v < n; ++v) {
    if (deg[v] % 3 == 0) {
      kill[v] = false;
      return true;
    }
    vector<int> one;
    for (int u : g[v])
      if (deg[u] % 3 == 1) one.push_back(u);
    if (deg[v] % 3 == 1) {
      if (!one.empty()) {
        kill[v] = false;
        kill[one[0]] = false;
        return true;
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    if (deg[v] % 3 == 0 || deg[v] % 3 == 1) continue;
    vector<int> one;
    for (int u : g[v])
      if (deg[u] % 3 == 1) one.push_back(u);
    if ((int)one.size() >= 2) {
      kill[v] = false;
      kill[one[0]] = false;
      kill[one[1]] = false;
      return true;
    }
  }
  for (int v = 0; v < n; ++v) {
    if (!used[v] && deg[v] % 3 == 2) {
      int start, finish;
      par[v] = -1;
      dist[v] = 0;
      if (dfsCycle(v, start, finish)) {
        vector<int> cycle;
        getPath(start, finish, cycle);
        memset(used, false, sizeof(bool) * n);
        for (int v : cycle) {
          used[v] = true;
          int minDist = N + 5, v_minDist = -1;
          for (int u : g[v]) {
            if (!used[u] || par[v] == u) continue;
            if (dist[v] - dist[u] < minDist) {
              minDist = dist[v] - dist[u];
              v_minDist = u;
            }
          }
          if (minDist != N + 5) {
            start = v_minDist, finish = v;
            break;
          }
        }
        cycle.clear();
        getPath(start, finish, cycle);
        for (int x : cycle) kill[x] = false;
        return true;
      }
    }
  }
  memset(used, false, sizeof(bool) * n);
  int start = -1;
  for (int v = 0; v < n; ++v)
    if (deg[v] % 3 == 1) start = v;
  int finish = dfsPath(start, start);
  if (finish != -1) {
    vector<int> path;
    getPath(start, finish, path);
    memset(dist, -1, sizeof(int) * n);
    for (int i = 0; i < (int)path.size(); ++i) dist[path[i]] = i;
    int start_next = path[1];
    for (int x : g[start]) {
      if (dist[x] > dist[start_next]) start_next = x;
    }
    path.clear();
    getPath(start_next, finish, path);
    memset(dist, N + 5, sizeof(int) * n);
    for (int i = 0; i < (int)path.size(); ++i) dist[path[i]] = i;
    int finish_prev = path[(int)path.size() - 2];
    for (int x : g[finish]) {
      if (dist[x] < dist[finish_prev]) x = finish_prev;
    }
    path.clear();
    getPath(start_next, finish_prev, path);
    path.push_back(finish);
    reverse(path.begin(), path.end());
    path.push_back(start);
    reverse(path.begin(), path.end());
    for (int x : path) kill[x] = false;
    return true;
  }
  int root = -1;
  for (int v = 0; v < n; ++v) {
    deg2[v] = 0;
    for (int u : g[v]) deg2[v] += (deg[u] % 3 == 2);
    if (deg[v] % 3 == 2 && deg2[v] >= 4) root = v;
  }
  memset(used, false, sizeof(bool) * n);
  for (int v = 0; v < n; ++v) kill[v] = false;
  if (root == -1) {
    int cntKill = 3;
    for (int v = 0; v < n && cntKill > 0; ++v) {
      if (deg[v] % 3 == 2 && !kill[v]) {
        dfsKill(v, -1, kill);
        --cntKill;
      }
    }
  } else {
    dfsDp(root, -1);
    dfsFind(root, -1, kill);
  }
  return true;
}
int main() {
  int test;
  scanf("%d", &test);
  while (test--) {
    vector<bool> kill;
    if (solve(kill)) {
      int n = (int)kill.size();
      for (int v = 0; v < n; ++v) {
        if (kill[v]) continue;
        int cntKill = 0;
        for (int u : g[v]) cntKill += kill[u];
        if (cntKill % 3 != 0) {
          for (int v = 0; v < n; ++v) {
            for (int u : g[v]) printf("%d", u + 1);
            printf("|");
          }
          break;
        }
      }
      int cnt = 0;
      for (bool f : kill) cnt += (int)f;
      printf("Yes\n");
      printf("%d\n", cnt);
      for (int i = 0; i < (int)kill.size(); ++i)
        if (kill[i]) printf("%d ", i + 1);
      printf("\n");
    } else {
      printf("No\n");
    }
  }
}
