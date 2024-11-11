#include <bits/stdc++.h>
const long double eps = 1e-9;
const long double pi = acos(-1.0);
using namespace std;
const int N = 2e3 + 1;
int n;
int g[N][N], gr[N][N];
bool used[N];
int dfs(int v, int my_g[N][N]) {
  int cnt = 1;
  used[v] = true;
  for (int i = 1; i <= n; i++) {
    if (used[i] || g[i][v] == 0) continue;
    cnt = cnt + dfs(i, my_g);
  }
  return cnt;
}
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      g[i][j] = (x > 0);
      gr[i][j] = g[i][j];
    }
  int kol1 = dfs(1, g);
  memset(used, false, sizeof used);
  int kol2 = dfs(1, gr);
  if (kol1 != n || kol2 != n)
    cout << "NO";
  else
    cout << "YES";
}
int main() {
  ios::sync_with_stdio(NULL), cin.tie(0), cout.tie(0);
  cout.setf(ios::fixed), cout.precision(10);
  int step;
  step = 1;
  for (int i = 1; i <= step; i++) {
    solve();
  }
}
