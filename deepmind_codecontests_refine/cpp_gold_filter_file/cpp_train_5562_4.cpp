#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
int a[40], f[40][2][40];
void update(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int main() {
  int K, n = 0;
  cin >> K;
  for (int x = K; x; x >>= 1) a[n++] = x & 1;
  memset(f, 0, sizeof(f));
  for (int i = 0; i < n; i++) f[i][i < n - 1][1] = 1;
  for (int i = n - 1; i > 0; i--)
    for (int x = 0; x < 2; x++)
      for (int j = 1; j <= n; j++)
        if (f[i][x][j]) {
          if (x)
            update(f[i - 1][1][j], ((long long)f[i][x][j] << j) % MOD);
          else if (a[i - 1] == 1) {
            update(f[i - 1][0][j], ((long long)f[i][x][j] << (j - 1)) % MOD);
            update(f[i - 1][1][j], ((long long)f[i][x][j] << (j - 1)) % MOD);
          } else
            update(f[i - 1][0][j], ((long long)f[i][x][j] << (j - 1)) % MOD);
          if (x || a[i - 1] == 1) update(f[i - 1][x][j + 1], f[i][x][j]);
        }
  int res = 1;
  for (int x = 0; x < 2; x++)
    for (int i = 1; i <= n; i++) update(res, f[0][x][i]);
  cout << res << endl;
  return 0;
}
