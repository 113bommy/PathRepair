#include <bits/stdc++.h>
using namespace std;
long long psum[55][55];
long long psum2[55][55];
bool can(long long a, long long b, long long c, long long d) {
  if (psum[max(a, c)][b] - psum[min(a, c) - 1][b] ==
          max(a, c) - min(a, c) + 1 &&
      psum2[c][max(b, d)] - psum2[c][min(b, d) - 1] ==
          max(b, d) - min(b, d) + 1)
    return true;
  if (psum[max(a, c)][d] - psum[min(a, c) - 1][d] ==
          max(a, c) - min(a, c) + 1 &&
      psum2[a][max(b, d)] - psum2[a][min(b, d) - 1] ==
          max(b, d) - min(b, d) + 1)
    return true;
  return false;
}
void solve() {
  long long n, m;
  cin >> n >> m;
  string arr[n + 5];
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
    arr[i] = " " + arr[i];
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      if (arr[i][j] == 'B') {
        psum[i][j]++;
        psum2[i][j]++;
      }
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      psum[i][j] += psum[i - 1][j];
      psum2[i][j] += psum2[i][j - 1];
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      for (long long k = 1; k <= n; k++) {
        for (long long l = 1; l <= m; l++) {
          if (arr[i][j] == arr[k][l] && arr[i][j] == 'B') {
            if (!can(i, j, k, l)) {
              cout << "NO\n";
              return;
            }
          }
        }
      }
    }
  }
  cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  while (t--) solve();
  return 0;
}
