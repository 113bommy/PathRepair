#include <bits/stdc++.h>
using namespace std;
long long n, m, a[22][22], b[22][22];
long long f(long long x) {
  for (long long i = 1; i <= m; i++) {
    if (b[x][i] != i) swap(b[x][i], b[x][b[x][i]]), i = m;
  }
  for (long long i = 1; i <= m; i++)
    if (b[x][i] != i) return 0;
  return 1;
}
int main() {
  cin >> n >> m;
  for (long long i = 1; i <= n; i++)
    for (long long j = 1; j <= m; j++) cin >> a[i][j];
  for (long long i = 1; i <= m; i++)
    for (long long j = i; j <= m; j++) {
      for (long long x = 1; x <= n; x++)
        for (long long y = 1; y <= m; y++) b[x][y] = a[x][y];
      for (long long x = 1; x <= n; x++) swap(b[x][i], b[x][j]);
      long long ch = 1;
      for (long long x = 1; x <= n; x++) ch &= f(x);
      if (ch) {
        cout << "YES";
        return 0;
      }
    }
  cout << "NO";
}
