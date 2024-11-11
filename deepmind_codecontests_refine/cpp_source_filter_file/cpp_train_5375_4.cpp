#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-11;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long n;
  n = (long long)a * (long long)b / gcd(a, b);
  return n;
}
int main() {
  long long a, b, mm, gg, num1 = 0, num2 = 0;
  long long t1, t2;
  cin >> a >> b;
  if (a >= b) {
    gg = gcd(a, b);
    mm = lcm(a, b);
  } else {
    gg = gcd(b, a);
    mm = lcm(b, a);
  }
  num1 = mm / a;
  num2 = mm / b;
  if (abs((long)(num1 - num2)) == 1) cout << "Equal";
  if (num1 < num2)
    cout << "Masha";
  else if (num1 > num2)
    cout << "Dasha";
  return 0;
}
