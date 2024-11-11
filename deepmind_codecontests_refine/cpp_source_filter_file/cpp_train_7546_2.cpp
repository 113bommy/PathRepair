#include <bits/stdc++.h>
using namespace std;
long long ans = 1, n;
bool isprime(long long a) {
  if (a < 2) return false;
  if (a == 2) return true;
  if (a % 2 == 0) return false;
  for (int i = sqrt(a); i > 6; i--)
    if (a % i == 0) return false;
  return true;
}
long long c(long long n, long long k) {
  long long res = 0, p = k;
  while (p <= n) {
    res += n / p;
    p *= k;
  }
  return res;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long r = power(a, b / 2);
    return (r * r) % 1000000007;
  } else
    return (power(a, b - 1) * a) % 1000000007;
}
int main() {
  cin >> n;
  for (long long i = 2; i < 2 * n; i++) {
    if (isprime(i))
      ans = (ans * power(i, c(2 * n - 1, i) - c(n, i) - c(n - 1, i))) %
            1000000007;
  }
  cout << (2 * ans - n + 1000000007) % 1000000007 << endl;
  return 0;
}
