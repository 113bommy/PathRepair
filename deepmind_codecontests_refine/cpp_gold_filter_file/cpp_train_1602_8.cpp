#include <bits/stdc++.h>
using namespace std;
int vis[100000 + 2];
vector<int> G[100000 + 2];
void dfs(int u, bool &e) {
  vis[u] = 1;
  for (int i = 0; i < (int)G[u].size(); i++) {
    int v = G[u][i];
    if (vis[v] == 0) {
      dfs(v, e);
    } else if (vis[v] == 1) {
      e = 1;
    }
  }
  vis[u] = 2;
}
void f(int u, vector<long long> &v) {
  v.push_back(u);
  for (int i = 0; i < (int)G[u].size(); i++) {
    int t = G[u][i];
    f(t, v);
  }
  return;
}
int degree[100000 + 2];
int main() {
  int n, q, x, y;
  long long t;
  cin >> n >> q >> t;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  for (int i = 0; i < q; i++) {
    cin >> x >> y;
    x--, y--;
    G[x].push_back(y);
    degree[y]++;
  }
  bool e = 0;
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0) {
      dfs(i, e);
    }
  }
  if (e == 1) {
    puts("0");
    return 0;
  }
  vector<long long> v;
  for (int i = 0; i < n; i++) {
    vector<long long> v2;
    if (degree[i] == 0) {
      f(i, v2);
      long long s = 0;
      for (int j = 0; j < (int)v2.size(); j++) {
        t -= s;
        s += A[v2[j]];
        v.push_back(s);
      }
    }
  }
  if (t < 0) {
    puts("0");
    return 0;
  }
  n = (int)v.size();
  vector<vector<long long> > DP(n + 1, vector<long long>(t + 1));
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j <= t; j++) {
      long long &dev = DP[i][j] = 0;
      if (i == n) {
        if (j == 0) dev = 1;
        continue;
      }
      if (j == 0) {
        dev = 1;
        continue;
      }
      dev = (dev + DP[i + 1][j]) % 1000000007;
      if (j - v[i] >= 0) dev = (dev + DP[i][j - v[i]]) % 1000000007;
    }
  }
  cout << DP[0][t] << '\n';
}
