#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
int n, m;
int l[maxn];
vector<int> a[maxn], g[maxn], ans;
bool mark[maxn];
bool vis[maxn];
void bad(string def = "") {
  cout << def + "No" << endl;
  exit(0);
}
void dfs(int v) {
  vis[v] = true;
  for (int u : g[v]) {
    if (!vis[u]) dfs(u);
    mark[v] |= mark[u];
  }
  if (mark[v]) ans.push_back(v);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    a[i].resize(l[i]);
    for (int j = 0; j < l[i]; j++) cin >> a[i][j];
  }
  for (int i = 1; i < n; i++) {
    int dif = -1;
    for (int j = 0; j < l[i - 1] and j < l[i]; j++)
      if (a[i - 1][j] != a[i][j]) {
        dif = j;
        break;
      }
    if (dif == -1 and l[i - 1] > l[i]) bad();
    int j = dif;
    if (~dif)
      if (a[i - 1][j] > a[i][j]) {
        mark[a[i - 1][j]] = true;
      } else {
        g[a[i - 1][j]].push_back(a[i][j]);
      }
  }
  for (int i = 0; i <= m; i++)
    if (!vis[i]) dfs(i);
  for (int i = 1; i < n; i++) {
    int dif = -1;
    for (int j = 0; j < l[i - 1] and j < l[i]; j++)
      if (a[i - 1][j] != a[i][j] or mark[a[i - 1][j]] != mark[a[i][j]]) {
        dif = j;
        break;
      }
    int j = dif;
    if (~j) {
      if (!mark[a[i - 1][j]] and mark[a[i][j]]) bad();
      if (a[i - 1][j] > a[i][j] and mark[a[i][j]]) bad();
    }
  }
  cout << "Yes" << endl;
  cout << ans.size() << endl;
  for (int x : ans) cout << x << " ";
  cout << endl;
  return 0;
}
