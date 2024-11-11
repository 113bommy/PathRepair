#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const long long mod = 1e8;
string str[55];
bool vis[53][53][53][53], co[53][53];
bool dfs(int m, int m1, int m2, int m3) {
  if (vis[m][m1][m2][m3]) return false;
  if (m == 3 && co[m1][m3] && co[m2][m3]) return true;
  if (co[m2][m3] && dfs(m - 1, m - 3, m1, m3)) return true;
  if (co[m3][m - 4] && dfs(m - 1, m3, m1, m2)) return true;
  vis[m][m1][m2][m3] = 1;
  return false;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> str[i];
  if (n == 1 || (n == 2 && (str[1][0] == str[2][0] || str[1][1] == str[2][1])))
    return puts("YES"), 0;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (str[i][0] == str[j][0] || str[i][1] == str[j][1]) {
        co[i][j] = 1;
        co[j][i] = 1;
      }
  if (dfs(n, n - 2, n - 1, n))
    cout << "YES";
  else
    cout << "NO";
}
