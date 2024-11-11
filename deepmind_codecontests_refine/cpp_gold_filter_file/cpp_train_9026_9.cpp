#include <bits/stdc++.h>
using namespace std;
const int iinf = 1e9 + 10;
const long long inf = 1ll << 60;
const long long mod = 998244353;
void GG() {
  cout << "0\n";
  exit(0);
}
long long mpow(long long a, long long n, long long mo = mod) {
  long long re = 1;
  while (n > 0) {
    if (n & 1) re = re * a % mo;
    a = a * a % mo;
    n >>= 1;
  }
  return re;
}
long long inv(long long b, long long mo = mod) {
  if (b == 1) return b;
  return (mo - mo / b) * inv(mo % b) % mo;
}
const int maxn = 4002;
int n, m, k;
long long dp[76][maxn];
int ways[2][76];
int at = 0;
long long C[80][80];
inline void first(int &x) {
  if (x >= mod) x -= mod;
}
void build() {
  C[0][0] = 1;
  for (int i = 0; i < 80; ++i)
    for (int j = 0; j <= i; ++j) {
      if (!i || !j) {
        C[i][j] = 1;
      } else {
        C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
      }
    }
}
int X[2][4005], Y[2][4005];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  build();
  ;
  cin >> n >> m >> k;
  array<vector<pair<int, int> >, 2> E;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    X[0][i] = a;
    Y[0][i] = b;
  }
  for (int i = 0; i < m - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    X[1][i] = a;
    Y[1][i] = b;
  };
  clock_t t = clock();
  for (int B = 0; B < 2; ++B) {
    int N = B == 0 ? n : m;
    for (int i = 0; i < N; ++i) {
      memset(dp[0], 0, sizeof dp[0]);
      dp[0][i] = 1;
      ways[B][0] += 1;
      for (int L = 1; L <= k; ++L) {
        memset(dp[L], 0, sizeof dp[L]);
        for (int it = 0; it < N - 1; ++it) {
          dp[L][Y[B][it]] += dp[L - 1][X[B][it]];
          dp[L][X[B][it]] += dp[L - 1][Y[B][it]];
        }
        if (!(L & 0b11))
          for (int i = 0; i < N; ++i) dp[L][i] %= mod;
        ways[B][L] += dp[L][i] % mod;
        first(ways[B][L]);
      }
    }
  };
  t = clock();
  ;
  int re = 0;
  for (int tk = 0; tk <= k; ++tk) {
    re += ways[0][tk] * (long long)ways[1][k - tk] % mod * (long long)C[k][tk] %
          mod;
    first(re);
  };
  cout << re << '\n';
}
