#include <bits/stdc++.h>
const double EPS = 1e-9;
const int MOD = 1000000007;
const int INF = 2000 * 1000 * 1000;
const int MAX = 1005;
using namespace std;
int popcount(int n) {
  bitset<32> b(n);
  return b.count();
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) {
  long long temp = gcd(a, b);
  return temp ? (a / temp * b) : 0;
}
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
inline bool isInteger(const std::string& s) {
  if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
    return false;
  char* p;
  strtol(s.c_str(), &p, 10);
  return (*p == 0);
}
int main() {
  int k, b, n, t, x = 0;
  cin >> k >> b >> n >> t;
  long long val = 1;
  for (; val < t; x++) val = val * k + b;
  x -= (val != k);
  cout << (x <= n ? n - x : 0) << endl;
  return 0;
}
