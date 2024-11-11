#include <bits/stdc++.h>
using namespace std;
const int MaxN = (int)300 + 7;
const int MaxLen = 300 + 7;
bitset<MaxLen> b, x;
bitset<MaxLen> getLine(int r, int l) {
  return (~(bitset<MaxLen>(0)) >> (MaxLen - (l - r))) << r;
}
int n, m, k;
long long l, r, c;
long long f[MaxLen][MaxLen];
long long cost[MaxLen][MaxLen];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(f, 0x7f, sizeof(f));
  memset(cost, 0x7f, sizeof(cost));
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> l >> r >> c;
    for (int j = l; j <= r; j++) cost[l][j] = min(cost[l][j], c);
  }
  f[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      f[i][j] = f[i - 1][j];
      for (int k = 1; k <= j; k++) {
        if (f[i][j] > f[i - k][j - k] + cost[i - k + 1][i])
          f[i][j] = f[i - k][j - k] + cost[i - k + 1][i];
      }
    }
  }
  long long ans = f[n][k];
  if (ans >= 0x3f3f3f3f3f3f) ans = -1;
  cout << ans;
  return 0;
}
