#include <bits/stdc++.h>
using namespace std;
long long delbit(long long a, long long k) { return a & (~(1 << k)); }
int delbit(int a, int k) { return a & (~(1 << k)); }
bool getbit(long long a, long long k) { return 1 & (a >> k); }
bool getbit(int a, int k) { return 1 & (a >> k); }
long long setbit(long long a, long long k) { return a |= (1 << k); }
int setbit(int a, int k) { return a |= (1 << k); }
inline long long mulmod(long long first, long long n, long long _mod) {
  long long res = 0;
  while (n) {
    if (n & 1) res = (res + first) % _mod;
    first = (first + first) % _mod;
    n >>= 1;
  }
  return res;
}
inline long long powmod(long long first, long long n, long long _mod) {
  long long res = 1;
  while (n) {
    if (n & 1) res = (res * first) % _mod;
    first = (first * first) % _mod;
    n >>= 1;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  long long t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline int gcd(int a, int b) {
  int t;
  while (b) {
    a = a % b;
    t = a;
    a = b;
    b = t;
  }
  return a;
}
inline long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
inline long long gcd(long long a, long long b, long long c) {
  return gcd(gcd(a, b), c);
}
inline int gcd(int a, int b, int c) { return gcd(gcd(a, b), c); }
template <typename T, typename T2>
void printarr(T a[], T2 sz, T2 beg = 0) {
  for (T2 i = beg; i < sz; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  if (n % 2 == 0)
    cout << n / 2 - 1 << endl;
  else
    cout << n / 2 + 1 << endl;
  return 0;
}
