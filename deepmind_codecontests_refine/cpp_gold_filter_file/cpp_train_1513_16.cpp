#include <bits/stdc++.h>
const double PI = acos(-1.0);
using namespace std;
const int Max = 10055;
int gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * (b / gcd(a, b))); }
bool com(string x, string y) { return x + y < y + x; }
int main() {
  long long n, t;
  cin >> n >> t;
  long double r = n * (powl(1.000000011, t));
  cout << r;
  return 0;
}
