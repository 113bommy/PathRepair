#include <bits/stdc++.h>
using namespace std;
double doINF = 1.0 / 0.0;
ostream_iterator<int> outp(cout, " ");
inline long long modadd(long long n, long long m, long long mod) {
  long long sum = ((n + m) % mod + mod) % mod;
  return sum;
}
inline long long modsub(long long n, long long m, long long mod) {
  long long diff = ((n - m + mod) % mod + mod) % mod;
  return diff;
}
inline long long modpro(long long n, long long m, long long mod) {
  long long pro = ((n * m) % mod + mod) % mod;
  return pro;
}
inline long long pow(int x, int y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
inline long long powmod(long long x, long long y, long long mod) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = modpro(res, x, mod);
    y = y >> 1;
    x = modpro(x, x, mod);
  }
  return res;
}
bool pairdec(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first)
    return (a.first > b.first);
  else
    return a.second > b.second;
}
long long power(long long x, long long y, long long mod) {
  long long res = 1;
  x = x % mod;
  while (y > 0) {
    if (y & 1) res = (res * x) % mod;
    y = y >> 1;
    x = (x * x) % mod;
  }
  return res;
}
long long modInverse(long long a, long long mod) {
  return powmod(a, mod - 2, mod);
}
long long modFact(long long n, long long mod) {
  if (n >= mod) return 0;
  long long result = 1;
  for (long long i = 1; i <= n; i++) result = (result * i) % mod;
  return result;
}
const int N = 1e5;
int main() {
  int t;
  cin >> t;
  set<long long> s;
  for (int i = 1; i < 7; i++) s.insert(i);
  while (t--) {
    long long num;
    cin >> num;
    if (s.find(num % 14) != s.end() && num > 14)
      cout << "YES"
           << "\n";
    else
      cout << "NO"
           << "\n";
  }
}
