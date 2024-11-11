#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
const long long mod = 1e9 + 7;
const int MAXN = 1010;
long long dn[MAXN][MAXN][2][2];
long long dp[MAXN];
long long F[MAXN];
long long C[MAXN][MAXN];
inline void add(long long &a, long long b) {
  a = (a + b) % mod;
  if (a < 0) a += mod;
}
int main() {
  int N, K;
  cin >> N >> K;
  for (int(i) = (0); (i) <= (N); (i)++) {
    F[i] = i ? F[i - 1] * i % mod : 1;
    for (int(j) = (0); (j) <= (i); (j)++)
      C[i][j] = j ? C[i - 1][j] + C[i - 1][j - 1] : 1;
  }
  dn[0][0][0][0] = 1LL;
  for (int(i) = (0); (i) <= (N); (i)++)
    for (int(j) = (0); (j) <= (N); (j)++)
      for (int(m1) = (0); (m1) < (2); (m1)++)
        for (int(m2) = (0); (m2) < (2); (m2)++) {
          if (!m1 && i > 0) add(dn[i + 1][j + 1][m2][0], dn[i][j][m1][m2]);
          if (i + 2 <= N) add(dn[i + 1][j + 1][m2][1], dn[i][j][m1][m2]);
          add(dn[i + 1][j][m2][0], dn[i][j][m1][m2]);
        }
  for (int(i) = (0); (i) <= (N); (i)++) {
    for (int(m1) = (0); (m1) < (2); (m1)++)
      for (int(m2) = (0); (m2) < (2); (m2)++) add(dp[i], dn[N][i][m1][m2]);
    dp[i] = (dp[i] * F[N - i]) % mod;
  }
  for (int i = N; i >= 0; i--)
    for (int(j) = (i + 1); (j) <= (N); (j)++) add(dp[i], -dp[j] * C[j][i]);
  cout << dp[K] << endl;
  return 0;
}
