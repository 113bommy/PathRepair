#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
int main() {
  vector<int> cc(30001);
  cc[0] = 1;
  cc[1] = 1;
  for (int i = 2; i <= 30000; i++) {
    cc[i] = i * (i - 1) / 2;
  }
  int n, m, t1, t2;
  cin >> n >> m;
  g = vector<vector<int> >(n);
  for (int i = 0; i < m; i++) {
    cin >> t1 >> t2;
    g[t1 - 1].push_back(t2 - 1);
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    queue<int> q;
    q.push(i);
    vector<bool> used(n);
    vector<int> d(n, 0);
    vector<int> lvl(n, 0);
    used[i] = true;
    lvl[i] = 0;
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int j = 0; j < g[v].size(); j++) {
        int to = g[v][j];
        if (!used[to]) {
          used[to] = true;
          q.push(to);
          lvl[to] = lvl[v] + 1;
        }
        if (lvl[v] == 1) d[to]++;
      }
    }
    for (int j = 0; j < n; j++) {
      if (j != i && d[j] > 1) {
        res += cc[d[j]];
      }
    }
  }
  cout << res;
  return 0;
}
