#include <bits/stdc++.h>
using namespace std;
const int MAXK = 1005;
const int MOD = 1e9 + 7;
int k, col[MAXK];
long long sum, res, f[MAXK], c[MAXK][MAXK];
long long nhan(long long a, long long b) {
  a = a % MOD;
  if (a <= 1 || b <= 1) return (a * b) % MOD;
  return (nhan(a * 2, b / 2) + a * (b % 2)) % MOD;
}
int main() {
  cin >> k;
  for (int i = 1; i <= k; i++) cin >> col[i];
  for (int i = 0; i <= 1001; i++) c[i][0] = 1;
  for (int i = 1; i <= 1001; i++)
    for (int j = 1; j <= 1001; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
  f[1] = 1;
  sum = col[1];
  for (int i = 2; i <= k; i++) {
    sum += col[i];
    f[i] = nhan(f[i - 1], c[sum - 1][col[i] - 1]);
  }
  cout << f[k];
}
