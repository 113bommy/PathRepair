#include <bits/stdc++.h>
using namespace std;
void desperate_optimization(int precision) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(precision);
}
const long long MOD = 1e9 + 7;
const int N = 1e5;
const int K = 100;
long long pending[K + 5][N + 5];
long long arr[N + 5];
long long fct[N + 5], inv[N + 5];
long long fast(long long A, long long B) {
  long long ans = 1;
  while (B) {
    if (B & 1) ans = ans * A % MOD;
    A = A * A % MOD;
    B /= 2;
  }
  return ans;
}
long long combin(int n, int r) {
  return fct[n] * inv[r] % MOD * inv[n - r] % MOD;
}
void hora(int tc) {
  fct[0] = 1;
  for (int i = 1; i <= N; i++) fct[i] = fct[i - 1] * i % MOD;
  inv[N] = fast(fct[N], MOD - 2);
  for (int i = N - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    long long x;
    cin >> x;
    arr[i] = x;
  }
  for (int i = 1; i <= m; i++) {
    int l, r, x;
    cin >> l >> r >> x;
    pending[x][l] = (pending[x + 1][l] + 1) % MOD;
    for (int j = x; j >= 0; j--) {
      pending[j][r + 1] =
          (pending[j][r + 1] + MOD - combin(r - l + (x - j), x - j)) % MOD;
    }
  }
  for (int i = 100; i >= 0; i--) {
    for (int j = 1; j <= n; j++) {
      pending[i][j] =
          (pending[i][j - 1] + pending[i][j] + pending[i + 1][j]) % MOD;
    }
  }
  for (int i = 1; i <= n; i++) cout << (arr[i] + pending[0][i]) % MOD << " ";
  cout << '\n';
}
int main() {
  desperate_optimization(10);
  int ntc = 1;
  for (int tc = 1; tc <= ntc; tc++) hora(tc);
  return 0;
}
