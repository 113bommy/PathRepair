#include <bits/stdc++.h>
using namespace std;
const long long N = 555;
long long n, res[N][N], c = 1;
void snake() {
  for (long long i = n - 1; i; i--) {
    if (i & 1) {
      for (long long j = n - 1; j >= 0; j--) res[i][j] = c++;
    } else {
      for (long long j = 0; j < n; ++j) res[i][j] = c++;
    }
    if (i == n - 2) c--;
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(40);
  cin >> n;
  if (n <= 2) {
    cout << -1;
    return 0;
  }
  if (n == 3) {
    cout << "6 8 1\n5 2 9\n7 3 4";
    return 0;
  }
  bool f = 0;
  if (n % 2) {
    for (long long i = 0; i < n; ++i) {
      cout << c << ' ';
      c++;
    }
    cout << '\n';
    c = 2 * n;
    f = 1;
    n--;
  }
  snake();
  for (long long i = 1; i < n; ++i) res[0][i] = c++;
  res[0][0] = c++;
  res[n - 2][n - 1] = c;
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < n; ++j) cout << res[i][j] << ' ';
    if (f) cout << (n + 1) + i + 1;
    cout << '\n';
  }
}
