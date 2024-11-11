#include <bits/stdc++.h>
using namespace std;
long long int num[20][10][1 << 10], sum[20][10][1 << 10];
const long long int mod = 998244353;
long long int l, r;
int k;
int bit[10];
long long int pow(long long int x, long long int y, long long int z) {
  while (y--) {
    z = z * x;
  }
  return z % mod;
}
int f_n_bit(int x) {
  int n_bit = 0;
  for (int i = 0; i <= 9; i++)
    if (x >> i & 1) n_bit++;
  return n_bit;
}
int low[20], up[20];
long long int DP(int n) {
  long long int ans = 0;
  memset(num, 0, sizeof(num));
  memset(sum, 0, sizeof(sum));
  for (int i = 0; i <= up[1]; i++) num[0][i][1 << i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = low[i]; j <= up[i]; j++)
      for (int l = bit[1]; l < 1 << 10; l++) {
        int a = l | bit[j];
        if (f_n_bit(a) > i || f_n_bit(a) > k) continue;
        for (int t = 0; t < 10; t++)
          if ((l & bit[t]) == bit[t]) {
            num[i][j][a] = (num[i][j][a] + num[i - 1][t][l]) % mod;
            sum[i][j][a] = (pow(10, i - 1, j) * num[i - 1][t][l] % mod +
                            sum[i][j][a] + sum[i - 1][t][l]) %
                           mod;
          }
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= up[i]; j++)
      for (int l = bit[1]; l < 1 << 10; l++) ans = (ans + sum[i][j][l]) % mod;
  return ans;
}
long long int cal(long long int val) {
  long long int ans = 0;
  int n = 0, s[20];
  while (val > 0) {
    n++;
    s[n] = val % 10;
    val = val / 10;
  }
  for (int i = 1; i <= n; i++) {
    low[i] = 0;
    up[i] = 9;
  }
  s[n] == 1 ? up[n] = -1 : up[n] = s[n] - 1;
  ans = (ans + DP(n)) % mod;
  for (int i = n - 1; i >= 0; i--) {
    low[i + 1] = up[i + 1] = s[i + 1];
    up[i] = s[i] - 1;
    DP(n);
    for (int l = bit[1]; l < 1 << 10; l++) ans = (ans + sum[n][s[n]][l]) % mod;
  }
  return ans;
}
int main() {
  for (int i = 0; i < 10; i++) bit[i] = 1 << i;
  cin >> l >> r >> k;
  cout << (cal(r) - cal(l - 1) + mod) % mod << endl;
  return 0;
}
