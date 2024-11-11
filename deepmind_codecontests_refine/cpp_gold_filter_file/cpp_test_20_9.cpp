#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(51);
const long long INF = 1e18;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m)),
        pr(n, vector<long long>(m));
    vector<vector<long long>> mn(m, vector<long long>(m, INF));
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        char c;
        cin >> c;
        a[i][j] = c - '0';
        pr[i][j] = a[i][j] + (j > 0 ? pr[i][j - 1] : 0);
      }
    }
    long long anss = 1e18;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        for (long long jj = j; jj < m; jj++) {
          if (jj - j + 1 >= 4) {
            if (i > 0)
              mn[j][jj] += (a[i - 1][j] ^ 1) + (a[i - 1][jj] ^ 1) +
                           (pr[i - 1][jj - 1] - pr[i - 1][j]);
            if (i - 4 >= 0) {
              long long add = 0;
              for (long long f = i - 3; f < i; f++) {
                add +=
                    (a[f][j] ^ 1) + (a[f][jj] ^ 1) + (pr[f][jj - 1] - pr[f][j]);
              }
              mn[j][jj] =
                  min(mn[j][jj],
                      (jj - j - 1) - (pr[i - 4][jj - 1] - pr[i - 4][j]) + add);
            }
            anss = min(anss,
                       mn[j][jj] + (jj - j - 1) - (pr[i][jj - 1] - pr[i][j]));
          }
        }
      }
    }
    cout << anss << endl;
  }
  return 0;
}
