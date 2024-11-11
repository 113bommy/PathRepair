#include <bits/stdc++.h>
using namespace std;
const long long N = 3e2 + 1;
const long long MOD = 1e9 + 7;
long long m, n, a[N][N];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  for (long long r = 1; r <= n; r++) {
    long long b[n + 1][m + 1];
    for (long long i = 1; i <= n; i++)
      for (long long j = 1; j <= m; j++)
        if (a[r][j])
          b[i][j] = a[i][j] ^ 1;
        else
          b[i][j] = a[i][j];
    bool solution = true;
    long long spec = 0;
    for (long long i = 1; i <= n; i++) {
      long long diff = 0;
      for (long long j = 1; j < m; j++)
        if (b[i][j] != b[i][j + 1]) diff++;
      if (diff > 2) solution = false;
      if (diff == 1) {
        if (spec) solution = false;
        spec = i;
      }
    }
    if (solution) {
      cout << "YES\n";
      for (long long i = 1; i <= spec; i++)
        if (b[i][1])
          cout << 1;
        else
          cout << 0;
      for (long long i = spec + 1; i <= n; i++)
        if (b[i][1])
          cout << 0;
        else
          cout << 1;
      cout << "\n";
      for (long long i = 1; i <= m; i++) cout << a[r][i];
      return 0;
    }
  }
  cout << "NO";
}
