#include <bits/stdc++.h>
using namespace std;
int MOD;
const int N = 2;
struct matrix {
  long long ar[N][N];
};
matrix operator*(matrix a, matrix b) {
  matrix ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans.ar[i][j] = 0;
      for (int k = 0; k < N; k++) {
        ans.ar[i][j] += (a.ar[i][k] * b.ar[k][j]) % MOD;
      }
      ans.ar[i][j] %= MOD;
    }
  }
  return ans;
}
matrix _pow(matrix m, long long n) {
  if (n == 1) return m;
  if (n & 1) return (m * _pow(m, n - 1));
  m = _pow(m, n >> 1);
  m = m * m;
  return m;
}
matrix get_pow(long long k) {
  matrix ans;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans.ar[i][j] = 1;
    }
  }
  ans.ar[1][1] = 0;
  ans = _pow(ans, k);
  return ans;
}
int main() {
  long long l, r, k, g = 0, ans = -1, t;
  cin >> MOD >> l >> r >> k;
  for (t = 1; t <= 1000000; t++) {
    if ((l + t - 1) / t <= r / (t + k - 1) && ans == -1) {
      ans = t;
    }
    if ((r / t) - ((l + t - 1) / t) + 1 >= k) g = t;
  }
  if (ans != -1) g = max(g, r / (ans + k - 1));
  cout << get_pow(g).ar[1][0] % MOD;
}
