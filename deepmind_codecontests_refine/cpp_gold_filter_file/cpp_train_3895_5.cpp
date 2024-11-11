#include <bits/stdc++.h>
using namespace std;
const int inf = 0x20202020;
const int mod = 1000000007;
template <class T>
inline void read(T& first) {
  bool fu = 0;
  char c;
  for (c = getchar(); c <= 32; c = getchar())
    ;
  if (c == '-') fu = 1, c = getchar();
  for (first = 0; c > 32; c = getchar()) first = first * 10 + c - '0';
  if (fu) first = -first;
};
template <class T>
inline void read(T& first, T& second) {
  read(first);
  read(second);
}
template <class T>
inline void read(T& first, T& second, T& z) {
  read(first);
  read(second);
  read(z);
}
template <class T>
inline void read(T& first, T& second, T& z, T& q) {
  read(first);
  read(second);
  read(z);
  read(q);
}
const int DX[] = {1, 0, -1, 0}, DY[] = {0, 1, 0, -1};
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long powmod(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
const int N = 111111, M = 111111;
int l, m, n, t, C, a, p, h;
int calc(long long a, long long n, long long p) {
  long long t = a * n / p;
  if (t <= 0) return max(a, p - a * n);
  if (a * n % p < a * (p / a - 1)) t--;
  return calc(a - p % a, t, a);
}
int main() {
  scanf("%d", &C);
  for (int _ = (1); _ <= (C); ++_) {
    scanf("%d%d%d%d", &a, &n, &p, &h);
    a %= p;
    int ans = calc(a, n, p);
    if (1ll * a * n < p) ans = a;
    puts(ans > h ? "NO" : "YES");
  }
  return 0;
}
