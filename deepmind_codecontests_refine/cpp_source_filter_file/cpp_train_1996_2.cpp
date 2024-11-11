#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const long long &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T, class U>
void _W(const pair<T, U> &x) {
  _W(x.first);
  putchar(' ');
  _W(x.second);
}
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
int MOD = 1e9 + 7;
void ADD(long long &x, long long v) {
  x = (x + v) % MOD;
  if (x < 0) x += MOD;
}
const int SIZE = 1e6 + 10;
long long fac[SIZE], inv[SIZE];
long long mypow(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y & 1) res = res * x % MOD;
    y >>= 1;
    x = x * x % MOD;
  }
  return res;
}
long long C(int x, int y) {
  if (y < 0 || y > x) return 0;
  return fac[x] * inv[y] % MOD * inv[x - y] % MOD;
}
void build() {
  assert(MOD >= SIZE);
  fac[0] = 1;
  for (int i = (1); i < (SIZE); ++i) fac[i] = fac[i - 1] * i % MOD;
  inv[SIZE - 1] = mypow(fac[SIZE - 1], MOD - 2);
  for (int i = SIZE - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}
int now_n, now_x;
long long now_v;
long long inv_2 = (MOD + 1) / 2;
long long calc(long long x, int n) {
  if (x >= n) return 1;
  if (now_n == -1) {
    now_n = n;
    now_x = x;
    for (int i = (0); i <= (x); ++i) ADD(now_v, C(n, i));
  } else {
    while (now_x > x) {
      ADD(now_v, C(now_n, now_x));
      now_x--;
    }
    while (now_n < n) {
      ADD(now_v, now_v);
      ADD(now_v, -C(now_n, now_v));
      now_n++;
    }
  }
  return now_v * mypow(inv_2, n) % MOD;
}
int main() {
  build();
  int n;
  long long T;
  R(n, T);
  long long now = 0;
  long long an = 0;
  now_n = -1;
  for (int i = (1); i <= (n); ++i) {
    int t;
    R(t);
    now += t;
    if (now > T) break;
    ADD(an, calc(T - now, i));
  }
  W(an);
  return 0;
}
