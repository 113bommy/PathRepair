#include <bits/stdc++.h>
int getbit(long long x, int y) { return (x >> y) & 1; }
long long getoff(long long x, int y) { return x ^ ((1ll) << y); }
using namespace std;
int n, res, a[1010], b[1010][9], c[1010][9], f[1010][256];
void dp(int kc) {
  for (int i = 1; i <= n; ++i)
    for (int mask = 1; mask < 256; ++mask) f[i][mask] = -1e9;
  for (int i = 1; i <= n; ++i)
    for (int mask = 1; mask < (1 << 8); ++mask) {
      for (int j = 1; j <= 8; ++j)
        if (getbit(mask, j - 1) == 1) {
          int k;
          int ts = b[i][j];
          if (ts < kc) continue;
          k = c[ts - kc][j];
          f[i][mask] = max(f[i][mask], f[k][getoff(mask, j - 1)] + kc);
          if (ts < kc + 1) continue;
          k = c[ts - kc - 1][j];
          f[i][mask] = max(f[i][mask], f[k][getoff(mask, j - 1)] + kc + 1);
        }
      f[i][mask] = max(f[i][mask], f[i - 1][mask]);
    }
  res = max(res, f[n][255]);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 1; j <= 8; ++j) b[i][j] = b[i - 1][j];
    b[i][a[i]]++;
    for (int j = 1; j <= 8; ++j) c[b[i][j]][j] = i;
  }
  for (int kc = 0; kc <= n / 8; ++kc) dp(kc);
  cout << res;
  return 0;
}
