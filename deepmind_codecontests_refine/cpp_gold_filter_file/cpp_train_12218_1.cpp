#include <bits/stdc++.h>
using namespace std;
const int inf = (int)(1e9);
long long n, m, i, ans, j, tc;
int main() {
  cin >> n >> m;
  ans = 0;
  vector<string> s(n);
  for (i = 0; i < n; i++) cin >> s[i];
  vector<vector<long long> > a(n, vector<long long>(m));
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (s[i][j] == '0')
        a[i][j] = 1;
      else
        a[i][j] = 0;
    }
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      if (a[i][j] && j - 1 >= 0) a[i][j] += a[i][j - 1];
      long long w = a[i][j];
      for (long long k = i; k >= 0 && a[k][j]; k--) {
        w = min(w, a[k][j]);
        ans = max(ans, 2 * (w + (i - k + 1)));
      }
    }
  }
  cout << ans << endl;
}
