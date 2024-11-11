#include <bits/stdc++.h>
using namespace std;
const int inf = 2 * 1e9 + 1e8;
const int maxn = 102;
const double eps = 1e-10;
int n;
bool vis[maxn];
vector<pair<int, int> > gr[maxn];
void dfs(int v, double mom) {
  vis[v] = true;
  for (int i = 0; i < (int)gr[v].size(); ++i)
    if (!vis[gr[v][i].first]) {
      mom += 2.0 / (1.0 * gr[v].size());
      if (mom >= 2 - eps) mom -= 2;
      cout << 1 << " " << gr[v][i].second << " ";
      if (mom >= 1 - eps) {
        cout << gr[v][i].first << " " << v << " " << fixed << setprecision(10)
             << mom - 1 << endl;
        dfs(gr[v][i].first, mom - 1);
      } else {
        cout << v << " " << gr[v][i].first << " " << fixed << setprecision(10)
             << mom << endl;
        dfs(gr[v][i].first, 1 + mom);
      }
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    gr[a].push_back({b, i});
    gr[b].push_back({a, i});
  }
  cout << n - 1 << endl;
  dfs(1, 0);
  return 0;
}
