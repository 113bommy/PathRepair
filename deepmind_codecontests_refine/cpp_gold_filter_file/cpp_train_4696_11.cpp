#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long int lcm(long long int x, long long int y) {
  return ((x * y) / gcd(x, y));
}
bool prime(long long int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  long long int k = sqrt(n) + 1;
  for (int i = 2; i < k; i++)
    if (n % i == 0) return false;
  return true;
}
long long int modpow(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int power(long long int x, long long int n) {
  if (n == 0) return 1;
  if (n % 2 == 0)
    return power(x * x, n / 2);
  else
    return x * power(x, n - 1);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int a, b, x, y;
  cin >> a >> b >> x >> y;
  long long int c = 0;
  long long int k = gcd(x, y);
  x /= k;
  y /= k;
  c = min((a / x), (b / y));
  cout << c;
  return 0;
}
