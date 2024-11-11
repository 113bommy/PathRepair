#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
vector<int> dg[N];
vector<pair<int, int> > ug[N];
pair<int, int> edges[N];
bool u[N];
void dfs(int s) {
  u[s] = true;
  for (int to : dg[s]) {
    if (u[to]) continue;
    dfs(to);
  }
}
void dfs2(int s, vector<bool> &q) {
  u[s] = true;
  for (int to : dg[s]) {
    if (u[to]) continue;
    dfs2(to, q);
  }
  for (pair<int, int> t : ug[s]) {
    if (u[t.first]) continue;
    if (t.second >= 0) q[t.second] = true;
    dfs2(t.first, q);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int n, m, s;
  cin >> n >> m >> s;
  s--;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    a--;
    b--;
    if (t == 1)
      dg[a].push_back(b);
    else {
      ug[a].push_back({b, cur});
      ug[b].push_back({a, -1});
      edges[cur] = {a, b};
      cur++;
    }
  }
  dfs(s);
  int ans1 = 0;
  for (int i = 0; i < n; i++) {
    if (u[i]) ans1++;
  }
  string anss;
  for (int i = 0; i < cur; i++) {
    if ((u[edges[i].first] && u[edges[i].second]) ||
        (!u[edges[i].first] && !u[edges[i].second]) ||
        (!u[edges[i].first] && u[edges[i].second])) {
      anss.push_back('+');
    } else
      anss.push_back('-');
  }
  vector<bool> q(cur);
  for (int i = 0; i < n; i++) {
    if (u[i]) dfs2(i, q);
  }
  int ans2 = 0;
  for (int i = 0; i < n; i++) {
    if (u[i]) ans2++;
  }
  cout << ans2 << endl;
  for (int i = 0; i < cur; i++) {
    if (q[i])
      cout << "+";
    else
      cout << "-";
  }
  cout << endl << ans1 << endl << anss;
}
