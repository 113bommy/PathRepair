#include <bits/stdc++.h>
using namespace std;
const int NMAX = 1000 + 1;
int n, m;
int v[NMAX][NMAX];
long long dp1[NMAX][NMAX], dp2[NMAX][NMAX], dp3[NMAX][NMAX], dp4[NMAX][NMAX];
void citeste() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> v[i][j];
}
void rezolva() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      dp1[i][j] = v[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
  for (int j = m; j >= 1; j--)
    for (int i = 1; i <= n; i++)
      dp2[i][j] = v[i][j] + max(dp2[i - 1][j], dp2[i][j + 1]);
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      dp3[i][j] = v[i][j] + max(dp3[i + 1][j], dp3[i][j - 1]);
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      dp4[i][j] = v[i][j] + max(dp4[i][j + 1], dp4[i + 1][j]);
  long long sol = -1;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      sol = max(sol,
                dp1[i][j - 1] + dp4[i][j + 1] + dp2[i - 1][j] + dp3[i + 1][j]);
      sol = max(sol,
                dp1[i - 1][j] + dp4[i + 1][j] + dp2[i][j + 1] + dp3[i][j - 1]);
    }
  }
  cout << sol << '\n';
}
int main() {
  citeste();
  rezolva();
  return 0;
}
