#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
int dblcmp(double d) {
  if (fabs(d) < eps) return 0;
  return (d > 0) ? 1 : -1;
}
int n, m, T;
const int PRIMERANGE = 1000000;
int prime[PRIMERANGE + 1];
int getPrime() {
  memset(prime, 0, sizeof(int) * (PRIMERANGE + 1));
  for (int i = 2; i <= PRIMERANGE; i++) {
    if (!prime[i]) prime[++prime[0]] = i;
    for (int j = 1; j <= prime[0] && prime[j] <= PRIMERANGE / i; j++) {
      prime[prime[j] * i] = 1;
      if (i % prime[j] == 0) break;
    }
  }
  return prime[0];
}
long long count() {
  for (int i = 1; i <= prime[0] && prime[i] * prime[i] <= n; ++i)
    if (n % prime[i] == 0) return i;
  return -1;
}
int main() {
  cin >> n;
  getPrime();
  long long ans = n + 1;
  long long res;
  while (res = count(), res > 0) {
    ans += n / prime[res];
    n /= prime[res];
  }
  cout << ans << endl;
}
