#include <bits/stdc++.h>
using namespace std;
vector<int> tr[300001], a[300001];
long long ans[300001] = {}, cur = 0, z[300001] = {};
stack<int> q, s;
int n, m, t[300001][3] = {}, f[300001] = {}, d[300001] = {};
void solve() {
  int i, x;
  q.push(1);
  s.push(0);
  s.push(1);
  while (!q.empty()) {
    x = q.top();
    q.pop();
    for (i = 0; i < tr[x].size(); i++) {
      cur += t[tr[x][i]][2];
      z[min(d[x] + t[tr[x][i]][1] + 1, 300000)] -= t[tr[x][i]][2];
    }
    cur += z[d[x]];
    ans[x] = cur;
    for (i = 0; i < a[x].size(); i++)
      if (a[x][i] != f[x]) {
        q.push(a[x][i]);
        s.push(a[x][i]);
        f[a[x][i]] = x;
        d[a[x][i]] = d[x] + 1;
      }
    if (a[x].size() == 1 && x != 1) {
      s.pop();
      cur -= z[d[x]];
      for (i = 0; i < tr[x].size(); i++) {
        cur -= t[tr[x][i]][2];
        z[min(d[x] + t[tr[x][i]][1] + 1, 300000)] += t[tr[x][i]][2];
      }
      while (d[s.top()] == d[x] - 1) {
        x = f[x];
        cur -= z[d[x]];
        s.pop();
        for (i = 0; i < tr[x].size(); i++) {
          cur -= t[tr[x][i]][2];
          z[min(d[x] + t[tr[x][i]][1] + 1, 300000)] += t[tr[x][i]][2];
        }
      }
    }
  }
}
int main() {
  cin >> n;
  int i, j;
  for (i = 1; i < n; i++) {
    scanf("%d%d", &m, &j);
    a[m].push_back(j);
    a[j].push_back(m);
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    for (j = 0; j < 3; j++) scanf("%d", &t[i][j]);
    tr[t[i][0]].push_back(i);
  }
  solve();
  for (i = 1; i <= n; i++) printf("%d ", ans[i]);
  cout << endl;
  return 0;
}
