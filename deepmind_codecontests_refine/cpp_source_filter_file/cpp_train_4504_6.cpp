#include <bits/stdc++.h>
using namespace std;
long long findbits(long long n) {
  int i;
  for (i = 0;; i++) {
    if (pow(2, i) > n) return i - 1;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bool c = true;
    set<int> s1, s2;
    long long a[n][m], b[n][m];
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < m; j++) {
        cin >> a[i][j];
        if (i > 0 && i < n - 1 && j > 0 && j < m - 1)
          b[i][j] = 4;
        else if ((i == 0 || i == n - 1) && (j == 0 || j == m - 1))
          b[i][j] = 2;
        else
          b[i][j] = 3;
      }
    }
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (a[i][j] > b[i][j]) {
          c = false;
          break;
        }
      }
      if (!c) break;
    }
    if (!c)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) cout << b[i][j] << " ";
        cout << endl;
      }
    }
  }
  return 0;
}
