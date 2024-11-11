#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int d;
vector<vector<long long>> multiply(vector<vector<long long>> A,
                                   vector<vector<long long>> B) {
  vector<vector<long long>> C(d, vector<long long>(d));
  for (int i = 0; i < d; i++)
    for (int j = 0; j < d; j++)
      for (int z = 0; z < d; z++)
        C[i][j] = (C[i][j] + (A[i][z] * B[z][j]) % MOD) % MOD;
  return C;
}
vector<vector<long long>> power(vector<vector<long long>> &A, long long p) {
  if (p == 1) return A;
  if (p & 1)
    return multiply(A, power(A, p - 1));
  else {
    vector<vector<long long>> X = power(A, p / 2);
    return multiply(X, X);
  }
}
int main() {
  ios::sync_with_stdio(0);
  long long i, j, n;
  long long k;
  cin >> n >> k;
  long long a[n];
  for (i = 0; i < n; ++i) cin >> a[i];
  d = n;
  vector<vector<long long>> b(n, vector<long long>(n)),
      c(n, vector<long long>(n));
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      b[i][j] = (__builtin_popcountll(a[i] ^ a[j]) % 3LL == 0);
    }
  }
  if (k == 1) {
    cout << n << "\n";
    return 0;
  }
  c = power(b, k - 1);
  long long ans = 0;
  for (i = 0; i < n; ++i)
    for (j = 0; j < n; ++j) ans = (ans + c[i][j]) % MOD;
  cout << ans << "\n";
  return 0;
}
