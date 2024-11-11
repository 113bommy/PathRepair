#include <bits/stdc++.h>
using namespace std;
mt19937 rnd;
const long long mod = 1e9 + 7;
const long long N = 2000, M = N * N;
long long C[N][N];
long long q[M], p[M];
long long f[N][N];
long long add(long long x, long long y) {
  return ((x % mod) + (y % mod)) % mod;
}
long long sub(long long x, long long y) {
  return ((x % mod) - (y % mod)) % mod;
}
long long mult(long long x, long long y) {
  long long ans = ((x % mod) * (y % mod)) % mod;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  long long k;
  cin >> n >> k;
  if (n == 1 || k == 1) {
    cout << 1;
    return 0;
  }
  C[0][0] = 1;
  for (long long i = 1; i <= n; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (long long j = 1; j <= i - 1; j++) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }
  }
  q[0] = 1ll;
  p[0] = 1ll;
  for (long long i = 1; i < M; i++) {
    p[i] = mult(p[i - 1], k);
    q[i] = mult(q[i - 1], k - 1);
  }
  long long ans = p[n * n] % mod;
  for (long long r = 0; r <= n; r++) {
    for (long long c = 0; c <= n; c++) {
      long long x = mult(C[n][r], C[n][c]);
      long long kek = n * (r + c) - r * c;
      long long y = mult(q[kek], p[n * n - kek]);
      f[r][c] = mult(x, y);
    }
  }
  for (long long i = 1; i <= 2 * n; i++) {
    for (long long r = 0; r <= min(n, i); r++) {
      long long c = i - r;
      if (i % 2 == 1) {
        ans = sub(ans, f[r][c]);
      } else {
        ans = add(ans, f[r][c]);
      }
    }
  }
  ans += mod;
  ans %= mod;
  cout << ans << '\n';
  return 0;
}
