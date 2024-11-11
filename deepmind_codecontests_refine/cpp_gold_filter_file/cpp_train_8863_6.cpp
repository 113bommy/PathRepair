#include <bits/stdc++.h>
using namespace std;
int n, k;
long long l;
long long mo = 998244353;
long long A[4005][4005][2];
long long B[4005];
long long a, b;
long long f(long long x, long long y) {
  long long mid = 1;
  while (y) {
    if (y & 1) {
      mid = mid * x % mo;
    }
    x = x * x % mo;
    y >>= 1;
  }
  return mid;
}
int main() {
  cin >> n >> k >> l;
  A[0][0][0] = 1;
  for (int i = 0; i <= 2 * n; i++) {
    for (int j = 0; j <= i; j++) {
      A[i + 1][j + 1][0] = (A[i + 1][j + 1][0] + A[i][j][0]) % mo;
      A[i + 1][j + 1][1] = (A[i + 1][j + 1][1] + A[i][j][1]) % mo;
      if (j) {
        A[i + 1][j - 1][0] = (A[i + 1][j - 1][0] + A[i][j][0] * j) % mo;
        A[i + 1][j - 1][1] = (A[i + 1][j - 1][1] + A[i][j][1] * j) % mo;
      }
      if (j >= k) {
        A[i + 1][j][1] = (A[i + 1][j][1] + A[i][j][0]) % mo;
      }
    }
  }
  B[0] = 1;
  for (int i = 1; i <= n * 2 + 1; i++) {
    B[i] = B[i - 1] * i % mo;
  }
  a = A[2 * n + 1][0][1] * B[n] % mo * f(2, n) % mo;
  b = f(B[2 * n + 1], mo - 2) * l % mo;
  cout << a * b % mo << endl;
}
