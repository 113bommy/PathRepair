#include <bits/stdc++.h>
using namespace std;
inline void debugMode() {}
inline void optimizeIt() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
}
inline double ABS(const int &x) { return max(x, -x); }
inline bool isPrime(const int &x) {
  if (x == 1) return false;
  for (int d = 2; d * d <= x; d++) {
    if (x % d == 0) return false;
  }
  return true;
}
inline int GCD(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}
const int NMax = 1000 + 5;
const int LIM = 1e5;
const int MOD = 1e9 + 7;
long long int v[NMax][NMax];
long long int A[NMax][NMax];
long long int B[NMax][NMax];
long long int C[NMax][NMax];
long long int D[NMax][NMax];
int main() {
  debugMode();
  optimizeIt();
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      A[i][j] = max(A[i - 1][j], A[i][j - 1]) + v[i][j];
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = 1; j <= m; j++) {
      B[i][j] = max(B[i][j - 1], B[i + 1][j]) + v[i][j];
    }
  }
  for (int i = n; i > 0; i--) {
    for (int j = m; j > 0; j--) {
      C[i][j] = max(C[i + 1][j], C[i][j + 1]) + v[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = m; j > 0; j--) {
      D[i][j] = max(D[i - 1][j], D[i][j + 1]) + v[i][j];
    }
  }
  long long int ans = 0;
  for (int i = 2; i < n; i++) {
    for (int j = 2; j < m; j++) {
      long long int a = A[i - 1][j] + C[i + 1][j] + B[i][j - 1] + D[i][j + 1];
      long long int b = A[i][j - 1] + C[i][j + 1] + B[i + 1][j] + D[i - 1][j];
      ans = max(ans, max(a, b));
    }
  }
  cout << ans;
  return 0;
}
