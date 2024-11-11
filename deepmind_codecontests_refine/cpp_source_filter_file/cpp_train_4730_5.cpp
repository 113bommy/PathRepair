#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 100;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
int d[50][N][N], tp[N][N];
long long f[50];
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  for (int i = int(0); i <= int(N - 1); ++i) {
    if (i < 50) f[i] = (i == 0 ? 1 : f[i - 1] * i % B);
    tp[i][0] = 1;
    for (int j = int(1); j <= int(i); ++j)
      tp[i][j] = (tp[i - 1][j - 1] + tp[i - 1][j]) % B;
  }
  for (int k = int(1); k <= int(45); ++k) {
    for (int n = int(1); n <= int(1e3); ++n) {
      for (int mn = int(1); mn <= int(n); ++mn) {
        if (k == 1) {
          d[k][n][mn] = (n == mn);
          continue;
        }
        d[k][n][mn] = d[k - 1][n - mn][mn + 1];
      }
      for (int mn = int(n); mn >= int(1); --mn)
        d[k][n][mn] = d[k][n][mn] + d[k][n][mn + 1];
    }
  }
  int tests;
  cin >> tests;
  for (int test = int(1); test <= int(tests); ++test) {
    int n, k;
    cin >> n >> k;
    if (k >= 45) {
      cout << "0\n";
      continue;
    }
    long long ans = 0;
    for (int s = int(1); s <= int(n); ++s)
      ans = (ans + 1ll * d[k][s][1] * tp[n - s + k][k]) % B;
    ans = ans * f[k] % B;
    cout << ans << "\n";
  }
  return 0;
}
