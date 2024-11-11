#include <bits/stdc++.h>
using namespace std;
string s1, s2;
int n, m;
int memo[2222][2222][2];
int cal(int i, int j, bool dx) {
  if (memo[i][j][dx] != -1) return memo[i][j][dx];
  if (j == m) return memo[i][j][dx] = 0;
  if (i == n) return memo[i][j][dx] = m - j;
  if (s1[i] != s2[j]) {
    if (dx) {
      return memo[i][j][dx] =
                 min(min(cal(i + 1, j, dx), cal(i + 1, j + 1, 0) + 1),
                     cal(i, j + 1, 0) + 1);
    } else {
      return memo[i][j][dx] = cal(i + 1, j + 1, 0) + 1;
    }
  } else {
    if (dx) {
      return memo[i][j][dx] = min(min(cal(i + 1, j, dx), cal(i + 1, j + 1, 0)),
                                  cal(i, j + 1, 0) + 1);
    } else {
      return memo[i][j][dx] = cal(i + 1, j + 1, 0);
    }
  }
}
int main() {
  cin >> s1 >> s2;
  n = s1.size();
  m = s2.size();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++)
      for (int k = 0; k <= 1; k++) memo[i][j][k] = -1;
  cout << cal(0, 0, 1);
}
