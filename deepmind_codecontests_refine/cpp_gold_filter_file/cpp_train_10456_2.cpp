#include <bits/stdc++.h>
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
int a[108][108];
int main() {
  int n, m;
  read(n);
  read(m);
  for (int i = (1); i <= (n); ++i) read(a[i] + 1, m);
  while (n % 2 == 0) {
    int hh = n / 2;
    for (int i = (1); i <= (hh); ++i)
      for (int j = (1); j <= (m); ++j)
        if (a[n + 1 - i][j] != a[i][j]) goto fail;
    n = hh;
  }
fail:;
  writeln(n);
  return 0;
}
