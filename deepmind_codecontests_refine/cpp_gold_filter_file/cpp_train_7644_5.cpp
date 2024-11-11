#include <bits/stdc++.h>
using namespace std;
const int SIZE = 1234;
long long dp1[SIZE][SIZE];
long long dp2[SIZE][SIZE];
long long dp3[SIZE][SIZE];
long long dp4[SIZE][SIZE];
long long maze[SIZE][SIZE];
int n, m;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%lld", &maze[i][j]);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      long long a = dp1[i - 1][j];
      long long b = dp1[i][j - 1];
      dp1[i][j] = maze[i][j] + max(a, b);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = m; j >= 1; j--) {
      long long a = dp2[i + 1][j];
      long long b = dp2[i][j + 1];
      dp2[i][j] = maze[i][j] + max(a, b);
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = 1; j <= m; j++) {
      long long a = dp3[i + 1][j];
      long long b = dp3[i][j - 1];
      dp3[i][j] = maze[i][j] + max(a, b);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j >= 1; j--) {
      long long a = dp4[i - 1][j];
      long long b = dp4[i][j + 1];
      dp4[i][j] = maze[i][j] + max(a, b);
    }
  }
  long long res = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      long long a = dp1[i - 1][j] + dp2[i + 1][j];
      long long b = dp3[i][j - 1] + dp4[i][j + 1];
      res = max(res, a + b);
      long long c = dp1[i][j - 1] + dp2[i][j + 1];
      long long d = dp3[i + 1][j] + dp4[i - 1][j];
      res = max(res, c + d);
    }
  }
  cout << res << endl;
  return 0;
}
