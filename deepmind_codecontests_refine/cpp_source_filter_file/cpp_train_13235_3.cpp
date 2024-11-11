#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long tces = 1;
  while (tces--) {
    long long n, m;
    cin >> n >> m;
    long long a[n][m], b[n][m];
    long long row[n], col[n];
    for (long long i = 0; i < (n); i++) {
      for (long long j = 0; j < (m); j++) {
        cin >> a[i][j];
        row[i] = 0;
        col[j] = 0;
      }
    }
    for (long long i = 0; i < (n); i++) {
      for (long long j = 0; j < (m); j++) {
        cin >> b[i][j];
      }
    }
    for (long long i = 0; i < (n); i++) {
      for (long long j = 0; j < (m); j++) {
        row[i] += a[i][j] + b[i][j];
      }
    }
    for (long long j = 0; j < (m); j++) {
      for (long long i = 0; i < (n); i++) {
        col[j] += a[i][j] + b[i][j];
      }
    }
    for (long long i = 0; i < (n); i++) {
      if (row[i] % 2) {
        cout << "NO";
        exit(0);
      }
    }
    for (long long i = 0; i < (m); i++) {
      if (col[i] % 2) {
        cout << "NO";
        exit(0);
      }
    }
    cout << "YES";
  }
  return 0;
}
