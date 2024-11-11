#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int fx[] = {+1, -1, +0, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, +0, +1, -1, +1, -1, +1, -1, +0};
template <typename T>
inline T GCD(T a, T b) {
  a = abs(a);
  b = abs(b);
  if (a < b) swap(a, b);
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <typename T>
inline T LCM(T x, T y) {
  T tp = GCD(x, y);
  if ((x / tp) * 1. * y > 9e18) return 9e18;
  return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M = MOD) {
  T ret = 1;
  while (B) {
    if (B & 1) ret = (ret * A) % M;
    A = (A * A) % M;
    B = B >> 1;
  }
  return ret;
}
template <typename T>
inline T InvMod(T A, T M = MOD) {
  return BigMod(A, M - 2, M);
}
template <typename T>
T scani(T &n) {
  n = 0;
  bool negative = false;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') negative = true;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    n = n * 10 + c - 48;
    c = getchar();
  }
  if (negative) n = ~(n - 1);
  return n;
}
template <typename T>
void write(T n, int type = true) {
  if (n < 0) {
    putchar('-');
    n = -n;
  }
  if (!n) {
    putchar('0');
    if (type == 32)
      putchar(' ');
    else if (type)
      putchar('\n');
    return;
  }
  char buff[22];
  int len = 0;
  while (n) buff[len++] = n % 10 + 48, n /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buff[i]);
  if (type == 32)
    putchar(' ');
  else if (type)
    putchar('\n');
}
int scans(char *a) {
  int i = 0;
  char c = 0;
  while (c < 33) c = getchar();
  while (c > 33) {
    a[i++] = c;
    c = getchar();
  }
  a[i] = 0;
  return i;
}
const int N = 100 + 10;
double dp[N][N][N][4];
bool vis[N][N][N][4];
double nC2(int n) { return n * (n - 1) / 2; }
double ans_me(int r, int s, int p, int now) {
  if (now == 0) {
    if (r == 0) return 0;
    if (s + p == 0) return 1;
  } else if (now == 1) {
    if (s == 0) return 0;
    if (r + p == 0) return 1;
  } else {
    if (p == 0) return 0;
    if (r + s == 0) return 1;
  }
  if (vis[r][s][p][now]) return dp[r][s][p][now];
  vis[r][s][p][now] = true;
  double &ret = dp[r][s][p][now];
  ret = 0;
  double two = nC2(r + s + p);
  double tp = (r - 1) * r * .5 + (s - 1) * s * .5 + (p - 1) * p * .5;
  tp /= two;
  tp = 1. - tp;
  if (r && p) ret += ans_me(r - 1, s, p, now) * (double)(r * p) / two;
  if (s && r) ret += ans_me(r, s - 1, p, now) * (double)(r * s) / two;
  if (p && s) ret += ans_me(r, s, p - 1, now) * (double)(s * p) / two;
  if (tp) ret /= tp;
  return ret;
}
int main() {
  int r, s, p;
  scani(r), scani(s), scani(p);
  double a, b, c;
  a = b = c = 0;
  a = ans_me(r, s, p, 0);
  b = ans_me(r, s, p, 1);
  c = ans_me(r, s, p, 2);
  printf("%.10f %.10.f %.10f\n", a, b, c);
  return 0;
}
