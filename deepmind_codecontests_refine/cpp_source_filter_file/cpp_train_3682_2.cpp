#include <bits/stdc++.h>
using namespace std;
vector<int> v[112345];
set<int> s[112345];
bool f[112345];
int c[112345];
bool k[112345];
void dfs(int x, int p) {
  f[x] = true;
  for (int i = 0; i < v[x].size(); i++) {
    int y = v[x][i];
    if (c[x] != c[y]) s[c[x]].insert(c[y]);
    if (f[y] == false) dfs(y, x);
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    k[c[i]] = true;
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (f[i] == false) {
      dfs(i, i);
    }
  }
  int mx = 0;
  for (int i = 1; i <= m; i++) mx = max(mx, (int)s[i].size());
  int ans = 1;
  while (s[ans].size() != mx || k[ans] == false) ans++;
  cout << ans << "\n";
  return 0;
}
