#include <bits/stdc++.h>
using namespace std;
long long const INF = 1e9;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    long long mat[n][m];
    long long sum = 0, qn = 0, take = INF, num = -1;
    bool has = false;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> mat[i][j];
        sum += abs(mat[i][j]);
        if (abs(mat[i][j]) < take) {
          take = abs(mat[i][j]);
        }
        if (mat[i][j] < 0) {
          qn++;
        }
        if (mat[i][j] == 0) has = true;
      }
    }
    if (has || qn % 2 == 0) {
      cout << sum << '\n';
      continue;
    }
    if (take != INF) {
      sum -= 2 * take;
    }
    cout << sum << '\n';
  }
  return 0;
}
