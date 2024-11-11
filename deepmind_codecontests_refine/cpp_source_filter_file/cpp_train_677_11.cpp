#include <bits/stdc++.h>
using namespace std;
int n, m;
int d[3010][3010];
int f[3010][3], g[3010][3];
int c[3010];
vector<int> a[3010];
vector<pair<int, int> > st;
void bfs(int x) {
  memset(c, 0, sizeof(c));
  queue<pair<int, int> > q;
  q.push(pair<int, int>(0, x));
  for (int i = 1; i <= n; i++) d[x][i] = 1e9 + 1;
  while (!q.empty()) {
    int mv = q.front().first;
    int u = q.front().second;
    q.pop();
    if (c[u] == 1) continue;
    c[u] = 1;
    d[x][u] = mv;
    for (int i = 0; i < a[u].size(); i++)
      q.push(pair<int, int>(mv + 1, a[u][i]));
  }
}
bool cmp(pair<int, int> i, pair<int, int> j) { return i > j; }
bool check(int a, int b, int c, int d) {
  if (a == 0 || b == 0 || c == 0 || d == 0) return false;
  if (a == b || a == c || a == d) return false;
  if (b == c || b == d) return false;
  if (c == d) return false;
  return true;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) bfs(i);
  for (int i = 1; i <= n; i++) {
    st.clear();
    for (int j = 1; j <= n; j++) {
      if (i != j && d[j][i] != 1e9 + 1)
        st.push_back(pair<int, int>(d[j][i], j));
    }
    sort(st.begin(), st.end());
    for (int j = 0; j < min(3, (int)st.size()); j++) f[i][j] = st[j].second;
    st.clear();
    for (int j = 1; j <= n; j++) {
      if (i != j && d[i][j] != 1e9 + 1)
        st.push_back(pair<int, int>(d[i][j], j));
    }
    sort(st.begin(), st.end(), cmp);
    for (int j = 0; j < min(3, (int)st.size()); j++) g[i][j] = st[j].second;
  }
  int ans = 0, prt[4];
  for (int bb = 1; bb <= n; bb++) {
    for (int cc = 1; cc <= n; cc++) {
      if (d[bb][cc] == 1e9 + 1) continue;
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          int aa = f[bb][i];
          int dd = g[cc][j];
          if (check(aa, bb, cc, dd)) {
            if (d[aa][bb] + d[bb][cc] + d[cc][dd] > ans) {
              ans = d[aa][bb] + d[bb][cc] + d[cc][dd];
              prt[0] = aa;
              prt[1] = bb;
              prt[2] = cc;
              prt[3] = dd;
            }
          }
        }
      }
    }
  }
  for (int i = 0; i < 4; i++) cout << prt[i] << " ";
}
