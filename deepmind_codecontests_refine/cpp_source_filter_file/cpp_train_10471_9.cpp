#include <bits/stdc++.h>
using namespace std;
struct twosat {
  static const long long maxval = 2e5 + 5;
  long long n, ct;
  vector<long long> v[maxval], rv[maxval];
  bool visited[maxval];
  long long comp[maxval];
  long long order[maxval];
  void init(long long curn) {
    n = curn;
    for (long long i = 0; i < n; i++) {
      v[i].clear();
      rv[i].clear();
    }
  }
  void addEdge(long long x, long long y) {
    v[x].push_back(y);
    rv[y].push_back(x);
  }
  void dfs1(long long s) {
    visited[s] = true;
    for (long long i = 0; i < v[s].size(); i++) {
      if (!visited[v[s][i]]) {
        dfs1(v[s][i]);
      }
    }
    order[ct] = s;
    ct++;
  }
  void dfs2(long long s, long long color) {
    comp[s] = color;
    for (long long i = 0; i < rv[s].size(); i++) {
      if (comp[rv[s][i]] == -1) {
        dfs2(rv[s][i], color);
      }
    }
  }
  long long solve(vector<long long> &ans) {
    memset(visited, false, sizeof(visited));
    memset(comp, -1, sizeof(comp));
    ct = 0;
    for (long long i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs1(i);
      }
    }
    long long color = 0;
    for (long long i = n - 1; i >= 0; i--) {
      long long x = order[i];
      if (comp[x] == -1) {
        dfs2(x, color);
        color++;
      }
    }
    for (long long i = 0; i < n; i += 2) {
      if (comp[i] == comp[i ^ 1]) {
        return 0;
      }
    }
    ans.clear();
    for (long long i = 0; i < n; i += 2) {
      if (comp[i] > comp[i ^ 1]) {
        ans.push_back(i);
      } else {
        ans.push_back(i ^ 1);
      }
    }
    return 1;
  }
};
twosat ts;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  ts.init(2 * n);
  long long r[n];
  for (long long i = 0; i < n; i++) {
    cin >> r[i];
  }
  vector<long long> v[n];
  for (long long i = 0; i < m; i++) {
    long long x;
    cin >> x;
    for (long long j = 0; j < x; j++) {
      long long y;
      cin >> y;
      y--;
      v[y].push_back(i);
    }
  }
  for (long long i = 0; i < n; i++) {
    long long x0 = v[i][0] * 2, x1 = v[i][0] * 2 + 1, y0 = v[i][1] * 2,
              y1 = v[i][1] * 2 + 1;
    if (r[i] == 0) {
      ts.addEdge(x0, y1);
      ts.addEdge(x1, y0);
      ts.addEdge(y0, x1);
      ts.addEdge(y1, x0);
    } else {
      ts.addEdge(x0, y0);
      ts.addEdge(x1, y1);
      ts.addEdge(y0, x0);
      ts.addEdge(y1, x1);
    }
  }
  vector<long long> ans;
  long long z = ts.solve(ans);
  if (z == 0) {
    cout << "NO";
  } else {
    cout << "YES";
  }
  return 0;
}
