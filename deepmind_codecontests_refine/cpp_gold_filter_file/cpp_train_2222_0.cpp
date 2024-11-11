#include <bits/stdc++.h>
using namespace std;
long long tests;
long long n, m, a, sum;
char c;
bool u[55][55], us[55][55];
void dfs(long long i, long long j) {
  sum++;
  us[i][j] = 1;
  if (u[i - 1][j] == 1 && us[i - 1][j] == 0) dfs(i - 1, j);
  if (u[i][j - 1] == 1 && us[i][j - 1] == 0) dfs(i, j - 1);
  if (u[i + 1][j] == 1 && us[i + 1][j] == 0) dfs(i + 1, j);
  if (u[i][j + 1] == 1 && us[i][j + 1] == 0) dfs(i, j + 1);
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c;
      u[i][j] = c == '#';
      a += u[i][j];
    }
  }
  if (a <= 2) {
    cout << -1;
    return;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (u[i][j] == 1) {
        for (int ii = 1; ii <= n; ii++)
          for (int ji = 1; ji <= m; ji++) us[ii][ji] = 0;
        us[i][j] = 1;
        sum = 1;
        if (u[i - 1][j] == 1)
          dfs(i - 1, j);
        else if (u[i][j - 1] == 1)
          dfs(i, j - 1);
        else if (u[i + 1][j] == 1)
          dfs(i + 1, j);
        else if (u[i][j + 1] == 1)
          dfs(i, j + 1);
        if (sum != a) {
          cout << 1;
          return;
        }
      }
    }
  cout << 2;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
}
