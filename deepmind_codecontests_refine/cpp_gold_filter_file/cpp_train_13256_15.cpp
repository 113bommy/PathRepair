#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int NINF = 0xc0c0c0c0;
const int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 5;
const int N = 200 + 50;
int n, l, a[N], b[N];
long long f[3500][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i] >> b[i];
    f[a[i]][i]++;
    if (a[i] != b[i]) {
      a[i + n] = b[i];
      b[i + n] = a[i];
      f[a[i + n]][i + n]++;
    }
  }
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      if (!f[i][j]) continue;
      for (int k = 1; k <= 2 * n; k++) {
        if (j % n != k % n && a[k] == b[j])
          f[i + a[k]][k] = (f[i + a[k]][k] + f[i][j]) % mod;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= 2 * n; i++) ans = (ans + f[l][i]) % mod;
  cout << ans << '\n';
  return 0;
}
