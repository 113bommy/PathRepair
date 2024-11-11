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
int l, m, n, t, C;
int main() {
  scanf("%d", &n);
  if (n <= 4) {
    puts("No solution");
    return 0;
  }
  double l = 233, ang = 0, tmp = 2 * 3.1415926535897 / n, first = 0, second = 0;
  puts("0 0");
  for (int i = (3); i <= (n); ++i) {
    ang += tmp;
    first += l * cos(ang);
    second += l * sin(ang);
    l += 0.002;
    printf("%.9lf %.9lf\n", first, second);
  }
  printf("%.9lf 0\n", first + second / tan(tmp));
  return 0;
}
