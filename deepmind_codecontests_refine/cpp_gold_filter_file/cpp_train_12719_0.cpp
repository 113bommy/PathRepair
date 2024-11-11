#include <bits/stdc++.h>
using namespace std;
int n;
long long a[400400];
set<int> st;
vector<int> q;
vector<int> L[70];
vector<int> g[400400];
int done = 0;
int ncycle = 0;
int color[400400], p[400400];
vector<int> cycle[400400];
int add_cycle(int cycle_end, int cycle_st) {
  cycle[ncycle].clear();
  cycle[ncycle].push_back(cycle_st);
  for (int v = cycle_end; v != cycle_st; v = p[v]) cycle[ncycle].push_back(v);
  cycle[ncycle].push_back(cycle_st);
  reverse(cycle[ncycle].begin(), cycle[ncycle].end());
  if ((int)cycle[ncycle].size() == 5) {
    cout << 4 << "\n";
    exit(0);
  }
  return (int)cycle[ncycle].size();
}
void dfs(int v) {
  if (done == 1) return;
  color[v] = 1;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (color[to] == 0) {
      p[to] = v;
      dfs(to);
    } else if (color[to] == 1) {
      if (add_cycle(v, to) > 3) ncycle++;
      if (ncycle > 200000) {
        done = 1;
      }
    }
  }
  color[v] = 0;
}
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 0; j <= 60; ++j) {
      long long x = (1ll << j);
      if (a[i] & x) L[j].push_back(i);
    }
  }
  for (int i = 0; i <= 60; ++i) {
    if (L[i].size() >= 3) {
      cout << 3 << "\n";
      return 0;
    }
    for (int id : L[i]) {
      if (!st.count(id)) {
        st.insert(id);
        q.push_back(id);
      }
    }
  }
  for (int i = 0; i < q.size(); ++i) {
    for (int j = i + 1; j < q.size(); ++j) {
      long long v1 = a[q[i]];
      long long v2 = a[q[j]];
      if ((v1 & v2) > 0) {
        g[i].push_back(j);
        g[j].push_back(i);
      }
    }
  }
  for (int i = 0; i < q.size(); ++i)
    for (int j = i + 1; j < q.size(); ++j)
      for (int k = j + 1; k < q.size(); ++k) {
        long long v1 = a[q[i]], v2 = a[q[j]], v3 = a[q[k]];
        if ((v1 & v2) > 0) {
          if ((v1 & v3) > 0) {
            if ((v2 & v3) > 0) {
              cout << 3 << "\n";
              return 0;
            }
          }
        }
      }
  for (int i = 0; i < q.size(); i++)
    if (color[i] == 0) dfs(i);
  int mn = (int)1e9, id = -1;
  for (int i = 0; i < ncycle; ++i) {
    mn = min(mn, (int)cycle[i].size());
  }
  if (mn != (int)1e9)
    cout << mn - 1 << "\n";
  else
    cout << -1 << "\n";
  return 0;
}
