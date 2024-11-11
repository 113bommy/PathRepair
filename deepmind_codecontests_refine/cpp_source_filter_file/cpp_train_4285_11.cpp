#include <bits/stdc++.h>
using namespace std;
int NN;
struct mat {
  long long a[105][105];
  mat() { memset(a, 0, sizeof(a)); }
  mat operator*(const mat& m1) const {
    mat ret;
    for (int i = 0; i <= NN; i++) {
      for (int j = 0; j <= NN; j++) {
        for (int k = 0; k <= NN; k++) {
          ret.a[i][j] = (ret.a[i][j] + a[i][k] * m1.a[k][j] % int(1e9 + 7)) %
                        int(1e9 + 7);
        }
      }
    }
    return ret;
  }
  void print() {
    cout << "======== print" << endl;
    for (int i = 0; i <= NN; i++) {
      for (int j = 0; j <= NN; j++) cout << a[i][j] << " ";
      cout << endl;
    }
  }
};
mat pow(mat x, long long n) {
  mat ret;
  for (int i = 0; i <= NN; i++) {
    ret.a[i][i] = 1;
  }
  while (n) {
    if (n & 1) ret = ret * x;
    x = x * x;
    n /= 2;
  }
  return ret;
}
long long qpow(long long x, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * x % int(1e9 + 7);
    x = x * x % int(1e9 + 7);
    n /= 2;
  }
  return ans;
}
int N, M, K;
int a[105];
long long fac[105], ifac[105], iN2;
long long comb(long long n, long long k) {
  if (n < k) return 0;
  return fac[n] * ifac[n - k] % int(1e9 + 7) * ifac[k] % int(1e9 + 7);
}
void init() {
  fac[1] = ifac[1] = 1;
  for (int i = 2; i <= N; i++) {
    fac[i] = fac[i - 1] * i % int(1e9 + 7);
    ifac[i] = qpow(fac[i], int(1e9 + 7) - 2);
  }
  iN2 = qpow(comb(N, 2), int(1e9 + 7) - 2);
}
int main() {
  ios::sync_with_stdio(0);
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    if (a[i]) ++K;
  }
  int k = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i] && i >= N - K + 1) ++k;
  }
  NN = K;
  init();
  mat A, res;
  for (int i = 0; i <= NN; i++) {
    if (i < K)
      A.a[i][i + 1] = (K - i) * (K - i) % int(1e9 + 7) * iN2 % int(1e9 + 7);
    if (i > 0)
      A.a[i][i - 1] =
          i * max(0, N - 2 * K + i) % int(1e9 + 7) * iN2 % int(1e9 + 7);
    A.a[i][i] =
        (1 - A.a[i][i + 1] - (i > 0 ? A.a[i][i - 1] : 0) + 2 * int(1e9 + 7)) %
        int(1e9 + 7);
  }
  res = pow(A, M);
  long long ans = res.a[k][K];
  cout << ans << endl;
  return 0;
}
