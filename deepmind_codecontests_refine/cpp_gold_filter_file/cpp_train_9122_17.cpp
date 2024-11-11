#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int dp[N][N][N][3];
vector<int> lista[N];
int conect[N][N];
int n, m;
int solve(int ai, int aj, int p, int flag) {
  int &ans = dp[ai][aj][p][flag];
  if (ans != -1) return ans;
  if (flag) {
    if (lista[ai].empty()) ans = !flag;
    for (int i = 0; i < lista[ai].size(); ++i) {
      int u = lista[ai][i];
      if (conect[u][ai] >= conect[aj][p]) {
        ans = ((ans == -1) ? (solve(u, aj, ai, !flag))
                           : max(ans, ((int)solve(u, aj, ai, !flag))));
      }
    }
    if (ans == -1) ans = !flag;
  } else {
    if (lista[aj].empty()) ans = !flag;
    for (int i = 0; i < lista[aj].size(); ++i) {
      int u = lista[aj][i];
      if (conect[u][aj] >= conect[ai][p]) {
        ans = ((ans == -1) ? (solve(ai, u, aj, !flag))
                           : min(ans, ((int)solve(ai, u, aj, !flag))));
      }
    }
    if (ans == -1) ans = !flag;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  int a, b;
  char c;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    conect[a][b] = (int)c;
    conect[b][a] = (int)c;
    lista[a].push_back(b);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (solve(i, j, 0, 1))
        cout << "A";
      else
        cout << "B";
    }
    cout << "\n";
  }
  return 0;
}
