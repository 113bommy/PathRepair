#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1, i, j, k;
  cin >> t;
  for (long long ii = 1; ii <= t; ii++) {
    long long n, m;
    cin >> n >> m;
    vector<vector<long long> > a(n, vector<long long>(m));
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) cin >> a[i][j];
    }
    long long nr = 0, nc = 0;
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) {
        if (a[i][j] == 1) break;
      }
      if (j < m) nr++;
    }
    for (j = 0; j < m; j++) {
      for (i = 0; i < n; i++) {
        if (a[i][j] == 1) break;
      }
      if (i < n) nc++;
    }
    k = min(nr, nc);
    if (k % 2)
      cout << "Ashish" << '\n';
    else
      cout << "Vivek" << '\n';
  }
  return 0;
}
