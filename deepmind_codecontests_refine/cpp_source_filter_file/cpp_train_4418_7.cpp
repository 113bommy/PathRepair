#include <bits/stdc++.h>
using namespace std;
bool sortinrevp(const pair<long long, long long> &a,
                const pair<long long, long long> &b) {
  return (a.first > b.first);
}
bool sortinrev(const long long &a, const long long &b) { return (a > b); }
void solve() {
  long long n;
  cin >> n;
  long long c[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cin >> c[i][j];
  }
  float a[n][n], b[n][n];
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (i == j) {
        a[i][j] = c[i][j];
        b[i][j] = 0;
      } else if (c[i][j] > c[j][i]) {
        float d = ((c[i][j] - c[j][i]) * 1.0) / 2;
        a[i][j] = (float)c[i][j] - d;
        b[i][j] = d;
      } else if (c[i][j] < c[j][i]) {
        float d = ((c[j][i] - c[i][j]) * 1.0) / 2;
        a[i][j] = (float)c[i][j] + d;
        b[i][j] = (-1) * d;
      } else {
        a[i][j] = 0;
        b[i][j] = 0;
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << setprecision(8) << a[i][j] << " ";
    cout << "\n";
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) cout << setprecision(8) << b[i][j] << " ";
    cout << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) solve();
  return 0;
}
