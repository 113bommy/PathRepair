#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
template <typename Tp>
inline void read(Tp &res) {
  static char c;
  res = 0;
  static bool f;
  f = false;
  while (c = getchar(), c != '-' && (c < '0' || c > '9'))
    ;
  if (c == '-') f = true, c = getchar();
  do res = (res * 10) + (c ^ 48);
  while (c = getchar(), c >= '0' && c <= '9');
  if (f) res = -res;
}
template <typename Tp>
inline void print(Tp first) {
  static char stk[30];
  static int top;
  top = 0;
  if (first == 0) {
    putchar('0');
    return;
  }
  if (first < 0) {
    first = -first;
    putchar('-');
  }
  while (first) stk[++top] = first % 10 ^ 48, first /= 10;
  while (top) putchar(stk[top--]);
}
namespace Program {
const int N = 2097152;
const double pi = acos(-1);
struct com {
  double first, second;
  com() {}
  com(const double _x, const double _y) : first(_x), second(_y) {}
  inline com operator+(const com t) {
    return com(first + t.first, second + t.second);
  }
  inline com operator-(const com t) {
    return com(first - t.first, second - t.second);
  }
  inline com operator*(const com t) {
    return com(first * t.first - second * t.second,
               first * t.second + second * t.first);
  }
} a[N + 5], b[N + 5];
int rev[N + 5];
int n, m, L;
void FFT(com *first, int type) {
  for (int i = 0, i_END_ = L; i < i_END_; ++i)
    if (i < rev[i]) swap(first[i], first[rev[i]]);
  for (int i = 2; i <= L; i <<= 1) {
    int mid = i >> 1;
    com wn(cos(pi * 2 / i), type * sin(pi * 2 / i));
    for (int j = 0; j < L; j += i) {
      com w(1, 0);
      for (int k = 0; k < mid; ++k, w = w * wn) {
        com a = first[k + j], b = w * first[k + j + mid];
        first[k + j] = a + b, first[k + j + mid] = a - b;
      }
    }
  }
}
const double eps = 1e-3;
int t[N + 5];
void Main() {
  read(n);
  read(m);
  for (L = 1; L <= m + m; L <<= 1)
    ;
  for (int i = 0, i_END_ = L; i < i_END_; ++i) a[i] = com(0, 0);
  int first;
  for (int i = 0, i_END_ = n; i < i_END_; ++i)
    read(first), t[first] = 1, a[first] = com(1, 0);
  rev[0] = 0;
  for (int i = 1, i_END_ = L; i < i_END_; ++i) {
    rev[i] = rev[i >> 1] >> 1;
    if (i & 1) rev[i] |= L >> 1;
  }
  FFT(a, 1);
  for (int i = 0, i_END_ = L; i < i_END_; ++i) a[i] = a[i] * a[i];
  FFT(a, -1);
  for (int i = 0, i_END_ = L; i < i_END_; ++i) a[i].first /= L;
  int cnt = 0;
  for (int i = 1, i_END_ = m + 1; i < i_END_; ++i) {
    if (t[i] == 1 && a[i].first < eps) ++cnt;
    if (t[i] == 0 && a[i].first > 1 - eps) {
      puts("NO");
      return;
    }
  }
  puts("YES");
  printf("%d\n", cnt);
  for (int i = 1, i_END_ = m + 1; i < i_END_; ++i)
    if (t[i] == 1 && a[i].first < eps) print(i), putchar(" \n"[--cnt == 0]);
}
}  // namespace Program
int main() {
  Program::Main();
  return 0;
}
