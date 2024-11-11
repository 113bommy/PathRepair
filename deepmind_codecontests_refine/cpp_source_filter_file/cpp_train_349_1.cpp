#include <bits/stdc++.h>
using namespace std;
int n, m, p[510][510][2];
vector<int> vr[510], ans, ans2;
queue<pair<pair<int, int>, bool> > qe;
bool bfs() {
  qe.push(make_pair(make_pair(1, n), true));
  p[1][n][true] = -1;
  while (qe.size()) {
    int v = qe.front().first.first, u = qe.front().first.second;
    bool f = qe.front().second;
    qe.pop();
    if (f == true) {
      for (int i = 0; i < vr[v].size(); i++) {
        int v2 = vr[v][i];
        if (p[v2][u][!f] == 0) {
          p[v2][u][!f] = v;
          qe.push(make_pair(make_pair(v2, u), !f));
        }
      }
    } else
      for (int i = 0; i < vr[u].size(); i++) {
        int u2 = vr[u][i];
        if (u2 != v && p[v][u2][!f] == 0) {
          p[v][u2][!f] = u;
          if (v == n && u2 == 1) return true;
          qe.push(make_pair(make_pair(v, u2), !f));
        }
      }
  }
  return false;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    vr[v].push_back(u);
    vr[u].push_back(v);
  }
  if (bfs() == false)
    cout << "-1\n";
  else {
    int v = n, u = 1;
    bool f = true;
    ans.push_back(v);
    ans2.push_back(u);
    while (v != 1 || u != n || f != true) {
      if (f == true) {
        u = p[v][u][f];
        ans2.push_back(u);
      } else {
        v = p[v][u][f];
        ans.push_back(v);
      }
      f = !f;
    }
    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i > -1; i--) cout << ans[i] << ' ';
    cout << '\n';
    for (int i = ans2.size() - 1; i > -1; i--) cout << ans2[i] << ' ';
    cout << '\n';
  }
  return 0;
}
