#include <bits/stdc++.h>
using namespace std;
struct abc {
  long long int val, up;
};
bool compare(abc x1, abc x2) { return (x1.up > x2.up); }
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
long long int min(long long int a, long long int b) {
  if (a < b) return a;
  return b;
}
bool isprime(long long int n) {
  if (n == 1) return false;
  for (long long int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
const long long int N = 2e5 + 3, A = 1e6 + 3;
int32_t main() {
  long long int n;
  cin >> n;
  for (long long int i = n + 1; i; i++) {
    long long int a[10] = {0}, j = i;
    while (j != 0) {
      long long int p = j % 10;
      if (a[p] == 0) {
        a[p] = 1;
        j /= 10;
      } else
        break;
    }
    if (j == 0) {
      cout << i;
      return 0;
    }
  }
}
