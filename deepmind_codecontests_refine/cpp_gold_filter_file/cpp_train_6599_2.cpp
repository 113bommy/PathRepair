#include <bits/stdc++.h>
#pragma GCC optimize(3)
inline void read(int &x) { scanf("%d", &x); }
inline void read(long long &x) { scanf("%I64d", &x); }
inline void read(double &x) { scanf("%lf", &x); }
inline void read(long double &x) {
  double tmp;
  read(tmp);
  x = tmp;
}
template <class T>
inline void read(T *a, int n) {
  for (int i = (0); i < (n); ++i) read(a[i]);
}
inline void write(int x) { printf("%d", x); }
inline void write(long long x) { printf("%I64d", x); }
inline void write(double x) { printf("%.10lf", x); }
inline void write(long double x) { printf("%.10lf", (double)x); }
template <class T>
inline void writeln(T x) {
  write(x);
  putchar('\n');
}
template <class T>
inline void writeln(T *a, int n) {
  for (int i = (0); i < (n); ++i) write(a[i]);
  putchar('\n');
}
template <class T>
inline void writelnln(T *a, int n) {
  for (int i = (0); i < (n); ++i) writeln(a[i]);
}
char a[100086];
int n;
unsigned int _dp[250086], _ldp[250086], *dp = _dp + 100008,
                                        *ldp = _ldp + 100008;
int main() {
  read(n);
  scanf("%s", a + 1);
  memset(_ldp, 0, sizeof(_ldp));
  ldp[0] = 1;
  memset(_dp, 0, sizeof(_dp));
  for (int i = (1); i <= (n); ++i) {
    if (a[i] == '?') {
      register int til = std::min(i, n - i);
      register unsigned int *p1 = ldp + til + 1;
      while (til--) *(p1--) += *(p1 - 2) * 25u;
      ++ldp;
    } else {
      *(--ldp) = 0;
    }
  }
  printf("%u\n", ldp[0]);
  return 0;
}
