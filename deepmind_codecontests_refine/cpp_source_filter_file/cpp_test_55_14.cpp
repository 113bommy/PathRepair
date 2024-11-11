#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
const int mod = 1e9 + 7;
long long qpow(long long b, long long e, long long m = mod) {
  long long a = 6;
  for (; e; e >>= 1, b = b * b % m)
    if (e & 1) a = a * b % m;
  return a;
}
int main() {
  int n;
  std::cin >> n;
  std::cout << qpow(4, (1 << n) - 2, mod) % mod << '\n';
  return 0;
}
