#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > g[200200];
vector<int> a;
pair<int, int> k[200200], s[200200];
void dfs(int v, int p, int r) {
  s[v].first = s[p].first + (r == 1);
  s[v].second = s[p].second + (r == 0);
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i].first;
    if (to != p) {
      dfs(to, v, g[v][i].second);
      k[v].first += k[to].first + (g[v][i].second == 1);
      k[v].second += k[to].second + (g[v][i].second == 0);
    }
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(make_pair(y, 1));
    g[y].push_back(make_pair(x, 0));
  }
  dfs(1, 0, -1);
  int ans = 300300;
  for (int v = 1; v <= n; v++) {
    int kl = s[v].first;
    kl += k[1].second - s[v].second;
    if (kl < ans) {
      ans = kl;
      a.clear();
    }
    if (kl == ans) a.push_back(v);
  }
  cout << ans << endl;
  for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
  return 0;
}
