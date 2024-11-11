#include <bits/stdc++.h>
const long long oo = (long long)1e18 + 1;
using namespace std;
int n, k;
int h[2020];
int f[2020], inv[2020];
int G[2020][2020];
int pw(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = (long long)res * a % 998244353;
      b--;
    } else {
      a = (long long)a * a % 998244353;
      b /= 2;
    }
  }
  return res;
}
int C[2020][2020];
int comp(int n, int k) { return C[n][k]; }
int main() {
  ios::sync_with_stdio(false);
  for (int i = 0; i < 2020; i++) C[i][0] = 1;
  for (int i = 1; i < 2020; i++)
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 998244353;
  cin >> n >> k;
  int m = 0;
  int res = 1;
  for (int i = 1; i <= n; i++) cin >> h[i];
  for (int i = 1; i <= n; i++)
    if (h[i] != h[i % n + 1]) {
      m++;
    } else {
      res = (long long)res * k % 998244353;
    }
  if (m == 0) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (i + j <= m) {
        G[i][j] = (long long)comp(m, i) * comp(m - i, j) % 998244353;
      }
    }
  }
  int tot = 0;
  for (int i = 1; i <= m; i++) {
    int j = m - i;
    int sm = 0;
    for (int z = i / 2 + 1; z <= i; z++) {
      sm += G[z][i - z];
      sm %= 998244353;
    }
    tot += (long long)pw(k - 2, j) * sm % 998244353;
    tot %= 998244353;
  }
  res = (long long)res * tot % 998244353;
  cout << res;
  return 0;
}
