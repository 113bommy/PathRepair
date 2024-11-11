#include <bits/stdc++.h>
using namespace std;
int prime[500000];
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
int main() {
  long long n;
  cin >> n;
  long long x = n;
  for (long long i = 2; i * i <= n; i++)
    if (n % i == 0) {
      x = gcd(x, i);
      x = gcd(x, n / i);
    }
  cout << x << endl;
}
