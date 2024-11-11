#include <bits/stdc++.h>
using namespace std;
const int NICO = 10000 + 10;
int T, n;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
bool isprime(int x) {
  if (x == 2) return 1;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 0;
  }
  return 1;
}
int main() {
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    int tmp = n;
    while (!isprime(tmp)) {
      tmp--;
    }
    long long x = tmp;
    tmp = n + 1;
    while (!isprime(tmp)) {
      tmp++;
    }
    long long y = tmp;
    long long p = x * y - 2 * y - 2 * (n - x - 1);
    long long q = 2 * x * y;
    long long t = gcd(p, q);
    p /= t, q /= t;
    printf("%lld/%lld\n", p, q);
  }
}
