#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
const long long INF = LLONG_MAX;
const long double pi = acos(-1);
const int S = 2e5 + 7;
const int MOD = 1e9 + 7;
short u[17][17][17];
int ans, k, n, m;
char a[17][17][17];
void dfs(int first, int second, int z) {
  if (!u[first - 1][second][z] && first > 0 && a[first - 1][second][z] == '.') {
    u[first - 1][second][z] = 1;
    dfs(first - 1, second, z);
  }
  if (!u[first + 1][second][z] && first < k - 1 &&
      a[first + 1][second][z] == '.') {
    u[first + 1][second][z] = 1;
    dfs(first + 1, second, z);
  }
  if (!u[first][second + 1][z] && second < n - 1 &&
      a[first][second + 1][z] == '.') {
    u[first][second + 1][z] = 1;
    dfs(first, second + 1, z);
  }
  if (!u[first][second - 1][z] && second > 0 &&
      a[first][second - 1][z] == '.') {
    u[first][second - 1][z] = 1;
    dfs(first, second - 1, z);
  }
  if (!u[first][second][z + 1] && z < m - 1 && a[first][second][z + 1] == '.') {
    u[first][second][z + 1] = 1;
    dfs(first, second, z + 1);
  }
  if (!u[first][second][z - 1] && z > 0 && a[first][second][z - 1] == '.') {
    u[first][second][z - 1] = 1;
    dfs(first, second, z - 1);
  }
}
void sol() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++)
      for (int q = 0; q < m; q++) cin >> a[i][j][q];
  }
  int first, second, ans = 0;
  cin >> first >> second;
  u[0][first - 1][second - 1] = 1;
  dfs(0, first - 1, second - 1);
  for (int i = 0; i < k; i++)
    for (int j = 0; j < n; j++)
      for (int q = 0; q < m; q++)
        if (a[i][j][q] == '.') ans += u[i][j][q];
  cout << ans;
}
int main() {
  if (getenv("USERNAME")[0] == 'D') freopen("input.txt", "r", stdin);
  cout << fixed << setprecision(9);
  ios::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int q = 1;
  while (q-- > 0) {
    sol();
  }
  return 0;
}
