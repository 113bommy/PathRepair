#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626;
long long MOD = 1000000007;
const long double EPS = 1e-9;
const int N = 3e5 + 7;
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline unsigned int setBits(unsigned int v) {
  unsigned int c;
  for (c = 0; v; ++c) v &= (v - 1);
  return c;
}
inline bool isPowerOfTwo(unsigned int v) { return (v && !(v & (v - 1))); }
long long power(long long base, unsigned long long exp, long long mod = MOD) {
  long long res = 1;
  base %= mod;
  while (exp) {
    if (exp & 1) res = (res * base) % mod;
    exp >>= 1;
    base = (base * base) % mod;
  }
  return res;
}
long long modInv(long long a, long long mod = MOD) {
  if (mod == 1) return 0;
  long long x = 1, y = 0, m = mod;
  while (a > 1) {
    long long q = a / m, t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += mod;
  return x;
}
inline unsigned int iabs(int x) {
  unsigned int y = x;
  return (y > 0) ? y : -y;
}
inline long long add(long long a, long long b, long long mod = MOD) {
  long long res = (a % mod + b % mod) % mod;
  return res;
}
inline long long sub(long long a, long long b, long long mod = MOD) {
  long long res = (a % mod - b % mod + mod) % mod;
  return res;
}
inline long long mult(long long a, long long b, long long mod = MOD) {
  long long res = (a % mod * b % mod) % mod;
  return res;
}
inline long long div(long long a, long long b, long long mod = MOD) {
  long long res = (a % mod * modInv(b, mod)) % mod;
  return res;
}
void openf() {}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  openf();
  int n, lind, mind = -1, clind;
  string res = "YES";
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  lind = 0;
  for (int i = 1; i < n; ++i) {
    if (arr[lind] > arr[i]) {
      if (mind == -1 || arr[mind] > arr[i]) {
        clind = lind;
        mind = i;
      }
    }
    if (arr[i] > arr[lind]) {
      lind = i;
    }
  }
  if (mind != -1) {
    swap(arr[mind], arr[clind]);
  }
  for (int i = 1; i < n; ++i) {
    if (arr[i] < arr[i - 1]) {
      res = "NO";
      break;
    }
  }
  cout << res << endl;
  return 0;
}
