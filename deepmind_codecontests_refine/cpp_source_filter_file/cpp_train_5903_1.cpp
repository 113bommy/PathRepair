#include <bits/stdc++.h>
using namespace std;
int n, m, k, s;
vector<long long> a;
vector<bool> used;
vector<vector<long long> > gr, res;
int main() {
  cin >> n >> m >> k >> s;
  a.resize(n);
  gr.resize(n);
  used.resize(n, false);
  res.resize(n, vector<long long>(k, 1e8));
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  int u, v;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    u--;
    v--;
    gr[u].push_back(v);
    gr[v].push_back(u);
  }
  queue<int> q;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      used[i] = false;
      if (a[j] == i) {
        res[j][i] = 0;
        used[j] = true;
        q.push(j);
      }
    }
    while (!q.empty()) {
      u = q.front();
      q.pop();
      for (int j = 0; j < gr[u].size(); j++) {
        if (!used[gr[u][j]]) {
          res[gr[u][j]][i] = res[u][i] + 1;
          used[gr[u][j]] = true;
          q.push(gr[u][j]);
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    sort(res[i].begin(), res[i].end());
    ans = 0;
    for (int j = 0; j < s; j++) {
      ans += res[i][j];
    }
    cout << ans << ' ';
  }
  return 0;
}
