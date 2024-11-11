#include <bits/stdc++.h>
using namespace std;
long long int n, m;
inline bool isValid(long long int x, long long int y) {
  if (x > n or x <= 0 or y > m or y <= 0) {
    return false;
  }
  return true;
}
long long int dp1[1010][1010], dp2[1010][1010], dp3[1010][1010],
    dp4[1010][1010], a[1010][1010];
int main() {
  long long int i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (i = 0; i <= n + 2; i++) {
    for (j = 0; j <= m + 2; j++) {
      dp1[i][j] = dp2[i][j] = dp3[i][j] = dp4[i][j] = 0;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      dp1[i][j] = max(dp1[i][j - 1], dp1[i - 1][j]) + a[i][j];
    }
  }
  for (i = n; i >= 1; i--) {
    for (j = m; j >= 1; j--) {
      dp2[i][j] = max(dp2[i][j + 1], dp2[i + 1][j]) + a[i][j];
    }
  }
  for (i = n; i >= 1; i--) {
    for (j = 1; j <= m; j++) {
      dp3[i][j] = max(dp3[i][j - 1], dp3[i + 1][j]) + a[i][j];
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = m; j >= 1; j--) {
      dp4[i][j] = max(dp4[i][j + 1], dp4[i - 1][j]) + a[i][j];
    }
  }
  long long int sum = 0;
  sum = 0;
  for (i = 2; i < n; i++) {
    for (j = 2; j < m; j++) {
      sum = max(sum,
                dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
      sum = max(sum,
                dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
    }
  }
  cout << sum << endl;
  return 0;
}
