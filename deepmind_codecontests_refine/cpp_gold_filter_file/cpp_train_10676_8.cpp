#include <bits/stdc++.h>
using namespace std;
inline unsigned long long gcd(long long a, long long b) {
  return b ? gcd(b, a % b) : abs(a);
}
inline unsigned long long lcm(long long a, long long b) {
  if (a && b) return abs(a) / gcd(a, b) * (long long)abs(b);
  return (long long)abs(a | b);
}
int main() {
  int n;
  cin >> n;
  unsigned long long k = 1, t = n + 1, m = 2;
  while (k != t) {
    unsigned long long x = lcm(k, k + 1);
    unsigned long long q = x / k * x - m / k;
    cout << q << endl;
    k++;
    m = x;
  }
  return 0;
}
