#include <bits/stdc++.h>
using namespace std;
int i, j, maxi, mini = 1000000000, a, b, c, d, n, m, f[1050000], total,
                dp[3051][3051], ok[1050000];
char v[1050][1050];
string s, t;
void go(int first, int second) {
  if (first == n || first == -1 || second == m || second == -1 ||
      v[first][second] == '*' || dp[first][second])
    return;
  dp[first][second] = a;
  f[a]++;
  go(first + 1, second);
  go(first - 1, second);
  go(first, second + 1);
  go(first, second - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (dp[i][j] == 0 && v[i][j] == '.') {
        a++;
        go(i, j);
      }
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        a++;
        b = 0;
        if (i + 1 < n && ok[dp[i + 1][j]] != a)
          b += f[dp[i + 1][j]], ok[dp[i + 1][j]] = a;
        if (i - 1 >= 0 && ok[dp[i - 1][j]] != a)
          b += f[dp[i - 1][j]], ok[dp[i - 1][j]] = a;
        if (j + 1 < m && ok[dp[i][j + 1]] != a)
          b += f[dp[i][j + 1]], ok[dp[i][j + 1]] = a;
        if (j - 1 >= 0 && ok[dp[i][j - 1]] != a)
          b += f[dp[i][j - 1]], ok[dp[i][j - 1]] = a;
        cout << b + 1;
      } else
        cout << '.';
    }
    cout << '\n';
  }
  return 0;
}
