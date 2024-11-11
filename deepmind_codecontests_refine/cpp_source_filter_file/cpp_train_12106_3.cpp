#include <bits/stdc++.h>
using namespace std;
void solve();
int main() {
  srand(time(0));
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
const long long N = 1e5 + 10, maxE = 5200, maxK = 1e4 + 10, INF = 2e18 + 10,
                mod = 1073376287, base = 311, base2 = 217;
const double eps = 0.00000001;
long long t, n, m, ans[501][501], h[501][501], v[501][501], pos[501 * 501];
void solve() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> h[i][j];
      }
    }
    for (long long i = 0; i < n * m; i++) {
      pos[i] = -1;
    }
    for (long long j = 0; j < m; j++) {
      for (long long i = 0; i < n; i++) {
        cin >> v[i][j];
      }
    }
    for (long long i = 0; i < n; i++) {
      pos[v[i][0]] = i;
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        if (pos[h[i][j]] != -1) {
          for (long long e = 0; e < m; e++) {
            ans[pos[h[i][j]]][e] = h[i][e];
          }
          break;
        }
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
  }
}
