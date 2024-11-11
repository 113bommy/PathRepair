#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int n, m, ans;
bool ok = true;
vector<int> adj[MAXN], S[MAXN];
int lrg[MAXN];
void dfs(int u) {
  if (!ok) return;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (lrg[v] && lrg[v] != lrg[u])
      ok = false;
    else if (!lrg[v])
      lrg[v] = lrg[u], dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      int x;
      cin >> x;
      S[i].push_back(x);
    }
  }
  for (int i = 1; i < n; i++) {
    int id = 0;
    while (id < min(S[i].size(), S[i - 1].size()) && S[i][id] == S[i - 1][id])
      id++;
    if (id == min(S[i].size(), S[i - 1].size()) &&
        S[i].size() < S[i - 1].size()) {
      return cout << "No" << endl, 0;
    } else if (id != min(S[i].size(), S[i - 1].size())) {
      int x = S[i][id], y = S[i - 1][id];
      if (y > x) {
        if (lrg[y] == 1 || lrg[x] == 2) return cout << "No" << endl, 0;
        lrg[y] = 2, lrg[x] = 1;
      } else {
        adj[x].push_back(y);
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (lrg[i] == 2) dfs(i);
    if (!ok) return cout << "No" << endl, 0;
  }
  for (int i = 1; i <= m; i++)
    if (lrg[i] == 2) ans++;
  cout << "Yes" << endl;
  cout << ans << endl;
  for (int i = 1; i <= m; i++)
    if (lrg[i] == 2) cout << i << " ";
  return 0;
}
