#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  long long int n, a, b, p, q, c;
  cin >> n >> a >> b >> p >> q;
  if (a > b)
    c = gcd(a, b);
  else
    c = gcd(b, a);
  long long int lcm = (a * b) / c;
  long long int x = n / a;
  long long int y = n / b;
  long long int z = n / lcm;
  if (p > q)
    cout << x * p + (y - z) * q;
  else
    cout << (x - z) * p + (y)*q;
}
