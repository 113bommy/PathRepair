#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
const int MOD = 1e9 + 7;
const int MAX = 1e5 + 10;
const long long LNF = 2e18;
int n, k, A[110], st, C[2];
class matrix {
 public:
  int X[101][101] = {};
  matrix operator*(matrix &P) {
    matrix R;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
          R.X[i][k] = (R.X[i][k] + 1LL * X[i][j] * P.X[j][k]) % MOD;
    return R;
  }
  matrix operator^(int e) {
    if (e == 1) return *this;
    matrix T = *this ^ e / 2;
    T = T * T;
    return (e % 2 ? T * *this : T);
  }
} T;
long long pw(long long a, int e) {
  if (e == 0) return 1;
  long long t = pw(a, e / 2);
  t = t * t % MOD;
  return (e % 2 ? t * a % MOD : t);
}
long long inv(long long x) { return pw(x % MOD, MOD - 2); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> A[i], C[A[i]]++;
  for (int i = 1; i <= C[0]; i++) st += A[i] == 0;
  long long s = n * (n - 1) / 2, u = inv(s);
  for (int i = 0; i <= C[0]; i++) {
    long long p = i * (C[1] - (C[0] - i)), r = (C[0] - i) * (C[0] - i),
              q = s - p - r;
    if (i > 0) T.X[i - 1][i] = p * u % MOD;
    if (i < C[0]) T.X[i + 1][i] = r * u % MOD;
    T.X[i][i] = q * u % MOD;
  }
  matrix R = T ^ k;
  cout << R.X[C[0]][st] << '\n';
  return 0;
}
