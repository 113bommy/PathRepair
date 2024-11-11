#include <bits/stdc++.h>
using namespace std;
const long long int K = 1e9 + 7;
long long int inv[1005];
long long int mu(long long int a, long long int n) {
  if (n == 0) return 1;
  long long int q = mu(a, n / 2);
  if (n % 2 == 0) return q * q % K;
  return q * q % K * a % K;
}
long long int S1(long long int n) {
  n %= K;
  return n * (n + 1) % K * inv[2] % K;
}
long long int S2(long long int n) {
  n %= K;
  return n * (n + 1) % K * (2 * n + 1) % K * inv[6] % K;
}
long long int S4(long long int n) {
  n %= K;
  long long int m[6];
  m[0] = 1;
  for (long long int i = 1; i <= 5; i++) m[i] = n * m[i - 1] % K;
  return ((m[5] * inv[5] % K + m[4] * inv[2] % K + m[3] * inv[3] % K -
           m[1] * inv[30] % K) %
              K +
          K) %
         K;
}
long long int S6(long long int n) {
  n %= K;
  long long int m[8];
  m[0] = 1;
  for (long long int i = 1; i <= 7; i++) m[i] = n * m[i - 1] % K;
  long long int res =
      (m[7] * inv[7] % K + m[6] * inv[2] % K + m[5] * inv[2] % K -
       m[3] * inv[6] % K + m[1] * inv[42] % K) %
      K;
  return (res + K) % K;
}
long long int A(long long int n) {
  n %= K;
  return (S1(n) + S2(n)) % K * inv[2] % K;
}
long long int sqr(long long int n) {
  if (n == 0) return 0;
  long long int m = sqrt(n);
  if ((m) * (m) <= n && ((m + 1) * (m + 1)) > n) return m;
  if ((m - 1) * (m - 1) <= n && ((m) * (m)) > n) return m - 1;
  if ((m) * (m) <= n && ((m + 1) * (m + 1)) > n) return m - 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  for (long long int i = 1; i <= 1000; i++) {
    inv[i] = mu(i, K - 2);
  }
  long long int m;
  cin >> m;
  long long int sm = sqr(m);
  long long int res = 0, sum, d;
  for (long long int x = -sm; x <= sm; x++) {
    sum = 0;
    d = sqr(m - x * x);
    sum = (2 * d + 1) * A(m) % K;
    long long int B =
        S4(d) % K + (2 * x * x % K - 1) % K * S2(d) % K +
        (2 * d + 1) % K * x % K * x % K * (x * x % K - 1) % K * inv[2] % K;
    B %= K;
    long long int C = S6(d) % K + (2 * x * x % K - 1) % K * S4(d) % K +
                      S2(d) % K * x % K * x % K * (x * x % K - 1) % K;
    C %= K;
    long long int D = B * inv[2] % K;
    long long int E = 2 * S6(d) * inv[3] % K + (2 * x * x % K - 1) * S4(d) % K +
                      (6 * x * x % K * x % K * x % K - 6 * x * x % K + 1) *
                          S2(d) % K * inv[3] % K +
                      (x * x % K) * (x * x % K - 1) % K * (2 * x * x % K - 1) %
                          K * (2 * d + 1) % K * inv[6] % K;
    E %= K;
    D = (D + E * inv[2] % K) % K;
    sum = (sum - (m % K + 1 - x * x % K) * B % K + C - D) % K;
    res = (res + sum) % K;
  }
  cout << (res + K) % K << endl;
  return 0;
}
