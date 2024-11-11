#include <bits/stdc++.h>
using namespace std;
const int N = 800;
const long long md = 1e9 + 7;
long long gcd(long long a, long long b) { return (b ? gcd(b, a % b) : a); }
void ans(long long ch, long long zn) {
  long long g = gcd(ch, zn);
  cout << ch / g << "/" << zn / g;
  exit(0);
}
long long x, a, b;
int main() {
  cin >> x >> a >> b;
  long long g = gcd(a, b);
  if (a > b) swap(a, b);
  if (a / g > x / b) {
    ans(min(x, a - 1), x);
  }
  long long nok = a / g * b;
  long long n = (a - 1) + (x / nok - 1) * a + min(a, (x % nok) + 1);
  ans(n, x);
  return 0;
}
