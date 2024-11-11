#include <bits/stdc++.h>
using namespace std;
const int Maxn = 123;
const int Mod = 1e9 + 7;
long long C[Maxn][Maxn];
long long dp[Maxn][Maxn * Maxn];
long long T[Maxn][Maxn * Maxn][2];
long long TC[Maxn][Maxn * Maxn][2];
inline long long pw(long long a, long long b) {
  if (!b) return 1;
  return ((pw((a * a) % Mod, b / 2)) * ((b % 2) ? a : 1)) % Mod;
}
inline long long rec(int rn, int n, long long m, int t, long long cte) {
  if (dp[n][t] != -1) return dp[n][t];
  register long long ret = 0;
  long long mn = m % rn;
  if (n <= mn) {
    for (int i = 0; i <= min(rn, t); i++) {
      if (TC[rn][i][0] == -1) TC[rn][i][0] = pw(C[rn][i], cte + 1) % Mod;
      if (T[n - 1][t - i][0] == -1)
        T[n - 1][t - i][0] = pw(rec(rn, n - 1, m, t - i, cte), 1) % Mod;
      ret += (T[n - 1][t - i][0] * TC[rn][i][0]) % Mod;
    }
  } else {
    for (int i = 0; i <= min(rn, t); i++) {
      if (TC[rn][i][1] == -1) TC[rn][i][1] = pw(C[rn][i], cte) % Mod;
      if (T[n - 1][t - i][1] == -1)
        T[n - 1][t - i][1] = pw(rec(rn, n - 1, m, t - i, cte), 1) % Mod;
      ret += (T[n - 1][t - i][1] * TC[rn][i][1]) % Mod;
    }
  }
  return dp[n][t] = (ret % Mod);
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0 || i == j)
        C[i][j] = 1;
      else {
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        C[i][j] %= Mod;
      }
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      TC[i][j][1] = -1;
      TC[i][j][0] = -1;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      T[i][j][0] = -1;
      T[i][j][1] = -1;
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      if (j)
        dp[i][j] = -1;
      else
        dp[i][j] = 1;
      if (!i) dp[0][j] = 0;
    }
  }
  dp[0][0] = 1;
  cout << rec(n, n, m, k, m / n) % Mod << endl;
  return 0;
}
