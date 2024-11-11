#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  int n, m;
  long long ans = 0;
  cin >> n >> m;
  int p[n][m];
  int sumx[n][m];
  int sumy[m][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      sumx[i][j] = 0;
      sumy[j][i] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> p[i][j];
      if (j) {
        sumx[i][j] = sumx[i][j - 1];
      }
      if (i) {
        sumy[j][i] = sumy[j][i - 1];
      }
      if (p[i][j]) {
        sumx[i][j]++;
        sumy[j][i]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (p[i][j] == 0) {
        ans += (sumx[i][j] > 0);
        ans += ((sumx[i][m - 1] - sumx[i][j]) > 0);
        ans += (sumy[j][i] > 0);
        ans += ((sumy[j][n - 1] - sumy[j][i]) > 0);
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
