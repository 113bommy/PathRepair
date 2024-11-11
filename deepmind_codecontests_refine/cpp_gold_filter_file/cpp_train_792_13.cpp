#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string ans;
  long long n, m;
  cin >> n >> m;
  vector<string> v(n);
  for (auto &i : v) cin >> i;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      long long f = 0;
      for (long long k = 0; k < n; k++)
        if (k != i) {
          if (v[k][j] == v[i][j]) f = 1;
        }
      for (long long k = 0; k < m; k++)
        if (k != j) {
          if (v[i][k] == v[i][j]) f = 1;
        }
      if (!f) ans += v[i][j];
    }
  }
  cout << ans;
}
