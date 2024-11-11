#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  long double p[N + 5][N + 5];
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) cin >> p[i][j];
  vector<vector<long double> > DP((1 << N), vector<long double>(N + 1, 0));
  DP[(1 << N) - 1][1] = 1;
  for (int mask = (1 << N) - 2; mask >= 0; mask--) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (!(mask & (1 << (j - 1)))) {
          long double aux = p[i][j] * DP[mask | (1 << (j - 1))][i] +
                            p[j][i] * DP[mask | (1 << (j - 1))][j];
          DP[mask][i] = max(DP[mask][i], aux);
        }
      }
    }
  }
  long double ans = 0;
  for (int i = 2; i <= N; i++) ans = max(ans, DP[(1 << (i - 1))][i]);
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << ans << "\n";
  return 0;
}
