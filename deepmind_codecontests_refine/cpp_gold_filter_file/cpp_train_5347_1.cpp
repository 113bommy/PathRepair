#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long d[100][10001];
long long fact[101];
long long C[2][101];
long long power(long long a, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) (res *= a) %= MOD;
    (a *= a) %= MOD;
    n >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  long long m;
  cin >> n >> m >> k;
  long long onest = (m + n - 1) / n;
  long long twost = m / n;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) fact[i] = (fact[i - 1] * i) % MOD;
  for (int i = 0; i <= n; i++) {
    long long now =
        (fact[n] * power((fact[i] * fact[n - i]) % MOD, MOD - 2)) % MOD;
    C[0][i] = power(now, onest);
    C[1][i] = power(now, twost);
  }
  for (int j = 0; j <= n; j++) d[0][j] = C[0][j];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      int border = min(n, j);
      int now = (m - i + n - 1) / n == twost;
      for (int x = 0; x <= border; x++)
        (d[i][j] += d[i - 1][j - x] * C[now][x]) %= MOD;
    }
  }
  cout << d[n - 1][k] << '\n';
  return 0;
}
