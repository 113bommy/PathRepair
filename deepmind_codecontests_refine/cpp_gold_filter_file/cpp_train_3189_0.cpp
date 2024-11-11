#include <bits/stdc++.h>
using namespace std;
void solve_min(int n, int m, vector<int> us, vector<int> vs, vector<int> ds,
               vector<vector<int>> g, int s) {
  queue<int> q;
  q.push(s);
  vector<bool> vis(n);
  vis[s] = true;
  int cnt = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    cnt++;
    for (int i : g[u])
      if (i % 2 == 0 && ds[i >> 1]) {
        int v = vs[i >> 1];
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
  }
  vector<int> ans(m);
  for (int i = 0; i < n; i++) {
    for (int ii : g[i])
      if (!ds[ii >> 1]) {
        int v = ii % 2 == 0 ? vs[ii >> 1] : us[ii >> 1];
        if (!vis[i] && vis[v]) {
          ans[ii >> 1] = ii % 2 == 1;
        }
      }
  }
  cout << cnt << endl;
  for (int i = 0; i < m; i++) {
    if (!ds[i]) {
      putchar(ans[i] ? '-' : '+');
    }
  }
  cout << endl;
}
void solve_max(int n, int m, vector<int> us, vector<int> vs, vector<int> ds,
               vector<vector<int>> g, int s) {
  priority_queue<pair<int, int>> q;
  q.emplace(1, s);
  q.emplace(0, s);
  vector<bool> vis(n);
  vis[s] = true;
  int cnt = 0;
  vector<int> ans(m);
  while (!q.empty()) {
    int d = q.top().first;
    int u = q.top().second;
    q.pop();
    cnt += d;
    if (d) {
      for (int i : g[u])
        if (ds[i >> 1]) {
          int v = vs[i >> 1];
          if (!vis[v]) {
            q.emplace(0, v);
            q.emplace(1, v);
            vis[v] = true;
          }
        }
    } else {
      for (int i : g[u])
        if (!ds[i >> 1]) {
          int v = i % 2 == 0 ? vs[i >> 1] : us[i >> 1];
          if (!vis[v]) {
            q.emplace(0, v);
            q.emplace(1, v);
            ans[i >> 1] = i % 2 == 1;
            vis[v] = true;
          }
        }
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < m; i++) {
    if (!ds[i]) {
      putchar(ans[i] ? '-' : '+');
    }
  }
  cout << endl;
}
int main() {
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  vector<int> us(m), vs(m), ds(m);
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &ds[i], &us[i], &vs[i]);
    ds[i] = ds[i] == 1;
    us[i]--;
    vs[i]--;
    if (ds[i]) {
      g[us[i]].push_back(i * 2);
    } else {
      g[us[i]].push_back(i * 2);
      g[vs[i]].push_back(i * 2 + 1);
    }
  }
  solve_max(n, m, us, vs, ds, g, s);
  solve_min(n, m, us, vs, ds, g, s);
}
