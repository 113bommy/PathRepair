#include <bits/stdc++.h>
using namespace std;
const int N = 1e3, M = 3e4, INF = 1e9;
int n, m, s, t, stemp, invalid;
int eu[M + 1];
int ev[M + 1];
int ew[M + 1];
vector<int> e[N + 1];
int ans, e1, e2;
int l[N + 1];
int r[N + 1];
int lowest[N + 1];
int par[N + 1];
void update_ans(int local_ans, int local_e1, int local_e2) {
  if (ans > local_ans) {
    ans = local_ans;
    e1 = local_e1;
    e2 = local_e2;
  }
}
void init() {
  for (int i = 0, _stop = N; i <= _stop; i++) {
    e[i].clear();
    l[i] = r[i] = lowest[i] = par[i] = 0;
  }
  ans = INF;
  e1 = -1;
  e2 = -1;
  stemp = 1;
  invalid = -1;
}
void dfs(int u, int p) {
  par[u] = p;
  lowest[u] = stemp;
  ;
  l[u] = stemp++;
  for (int i = 0, _stop = e[u].size() - 1; i <= _stop; i++) {
    int other = eu[e[u][i]] ^ ev[e[u][i]] ^ u;
    if (e[u][i] == invalid || e[u][i] == p) {
      continue;
    }
    if (l[other] == 0) {
      dfs(other, e[u][i]);
      ;
      lowest[u] = min(lowest[u], lowest[other]);
    } else {
      ;
      lowest[u] = min(lowest[u], l[other]);
    }
  };
}
void solve() {
  dfs(s, 0);
  if (l[t] == 0) {
    update_ans(0, -1, -1);
    return;
  };
  int node = t;
  vector<int> be;
  ;
  while (node != s) {
    ;
    int p = ev[par[node]] ^ eu[par[node]] ^ node;
    ;
    if (lowest[node] > l[p]) {
      ;
      update_ans(ew[par[node]], par[node], -1);
    } else {
      ;
      be.push_back(par[node]);
    }
    node = p;
  };
  for (int i = 0, _stop = be.size() - 1; i <= _stop; i++) {
    int edge = be[i];
    fill_n(l, N + 1, 0);
    invalid = edge;
    dfs(s, 0);
    int node = t;
    while (node != s) {
      int p = ev[par[node]] ^ eu[par[node]] ^ node;
      if (lowest[node] > l[p]) {
        update_ans(ew[par[node]] + ew[invalid], par[node], invalid);
      }
      node = p;
    }
  }
}
int main() {
  ;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  {
    init();
    cin >> n >> m >> s >> t;
    for (int i = 1, _stop = m; i <= _stop; i++) {
      cin >> eu[i] >> ev[i] >> ew[i];
      e[eu[i]].push_back(i);
      e[ev[i]].push_back(i);
    };
    solve();
    if (ans == INF) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
      cout << (e1 != -1) + (e2 != -1) << '\n';
      if (e1 != -1) {
        cout << e1 << " ";
      }
      if (e2 != -1) {
        cout << e2 << " ";
      }
      cout << '\n';
    }
  };
  return 0;
}
