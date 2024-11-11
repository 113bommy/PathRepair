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
  for (long long i = (0); i < (n); ++i) read(a[i]);
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
  for (long long i = (0); i < (n); ++i) write(a[i]);
  putchar('\n');
}
template <class T>
inline void writelnln(T *a, int n) {
  for (long long i = (0); i < (n); ++i) writeln(a[i]);
}
int n;
struct inv {
  int l, r, id;
};
inline bool operator<(const inv &x, const inv &y) {
  return x.l < y.l || (x.l == y.l && x.r > y.r);
}
inv a[200086];
bool hav[200086];
int main() {
  memset(hav, 0, sizeof(hav));
  read(n);
  read(n);
  for (long long i = (1); i <= (n); ++i) {
    read(a[i].l);
    read(a[i].r);
    a[i].r += a[i].l - 1;
    a[i].id = i;
  }
  std::sort(a + 1, a + n + 1);
  int cn = 0, mr = 0;
  for (long long i = (1); i <= (n); ++i)
    if (a[i].r > mr) {
      a[++cn] = a[i];
      mr = a[i].r;
    }
  mr = 0;
  int ans = n;
  a[cn + 1].l = 1000086;
  for (long long i = (1); i <= (cn); ++i)
    if (a[i + 1].l > mr + 1) {
      hav[a[i].id] = 1;
      mr = a[i].r;
      --ans;
    }
  writeln(ans);
  for (long long i = (1); i <= (n); ++i)
    if (!hav[i]) printf("%d ", i);
  return 0;
}
