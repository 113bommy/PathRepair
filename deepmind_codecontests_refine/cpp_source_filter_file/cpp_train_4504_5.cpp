#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long> > a(n + 2, vector<long long>(m + 2, 0));
    long long f = 0;
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        if ((i == 0 && j == 0 || i == n - 1 && j == 0 || i == 0 && j == m - 1 ||
             i == n - 1 && j == m - 1) &&
            a[i][j] > 2) {
          f = 1;
        }
        if (((i == 0 || i == n - 1) && j > 0 && j < m - 1 ||
             (j == 0 || j == m - 1) && i > 1 && i < n - 1) &&
            a[i][j] > 3) {
          f = 1;
        }
        if (a[i][j] > 4) {
          f = 1;
        }
      }
    }
    if (f) {
      cout << "NO\n";
      continue;
    } else {
      cout << "YES\n";
    }
    cout << 2 << ' ';
    for (long long i = 1; i < m - 1; i++) {
      cout << 3 << ' ';
    }
    cout << 2 << '\n';
    for (long long i = 1; i < n - 1; i++) {
      cout << 3 << ' ';
      for (long long j = 1; j < m - 1; j++) {
        cout << 4 << ' ';
      }
      cout << 3 << '\n';
    }
    cout << 2 << ' ';
    for (long long i = 1; i < m - 1; i++) {
      cout << 3 << ' ';
    }
    cout << 2 << '\n';
  }
}
