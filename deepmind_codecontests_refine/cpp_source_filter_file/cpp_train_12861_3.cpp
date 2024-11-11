#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000;
const int MOD = 1000 * 1000 * 1000 + 7;
const long INF_L = 1000 * 1000 * 1000;
const long long INF_LL = 1LL * INF_L * INF_L;
const long long MOD_LL = 1000000000007LL;
long long pow(long long n, long long a, long long mod) {
  long long res = 1;
  int curPow = 1;
  while (a) {
    if (a & 1) res = (res * n) % mod;
    curPow <<= 1;
    n = (n * n) % mod;
    a >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
long long returnFirstLargerOrEq(long long maxNumber, long long boundingValue) {
  long long result = 0;
  for (long long i = 2; i <= 100000 && result <= boundingValue; ++i) {
    result += maxNumber / (i * i * i);
  }
  return result;
}
int main() {
  long long m;
  cin >> m;
  long long lo = 8, hi = m * 8;
  while (lo < hi - 1) {
    long long med = lo + (hi - lo) / 2;
    long long firstLargerOrEq = returnFirstLargerOrEq(med, m);
    if (firstLargerOrEq >= m) {
      hi = med;
    } else {
      lo = med;
    }
  }
  if (returnFirstLargerOrEq(lo, m) == m) {
    cout << lo << endl;
  } else if (returnFirstLargerOrEq(hi, m) == m) {
    cout << hi << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
