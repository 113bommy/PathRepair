#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const double EPS = 1e-10;
inline double SQR(double x) { return x * x; }
inline long long SQR(long long x) { return x * x; }
inline int SQR(int x) { return x * x; }
inline double SQR3(double x) { return x * x * x; }
inline void DEBUG() { puts("jackie"); }
inline int inInt() {
  int x = 0, c;
  while ((unsigned int)((c = getchar()) - '0') >= 10) {
    if ('-' == c) return -inInt();
  }
  do {
    x = (x << 3) + (x << 1) + (c - '0');
  } while ((unsigned int)((c = getchar()) - '0') < 10);
  return x;
}
inline void outInt(int x) {
  if (x >= 10) outInt(x / 10);
  putchar((x % 10) + '0');
}
int main() {
  long long N, M;
  scanf(
      "%I64d"
      "%I64d",
      &N, &M);
  long long s, f, t;
  while (N--) {
    scanf(
        "%I64d"
        "%I64d"
        "%I64d",
        &s, &f, &t);
    if (s == f) {
      printf(
          "%I64d"
          "\n",
          t);
      continue;
    }
    if (s < f) {
      long long ans = t / (2 * (M - 1)) * 2 * (M - 1);
      if (t - ans <= s - 1) {
        ans = ans + f - 1;
      } else {
        ans = ans + f - 1 + 2 * (M - 1);
      }
      printf(
          "%I64d"
          "\n",
          ans);
    } else {
      if (t < M - 1) t = M - 1;
      long long ans = (t - (M - 1)) / (2 * (M - 1)) * 2 * (M - 1) + M - 1;
      if (t - ans <= M - s) {
        ans = ans + M - f;
      } else {
        ans = ans + 2 * (M - 1) + (M - f);
      }
      printf(
          "%I64d"
          "\n",
          ans);
    }
  }
  return 0;
}
