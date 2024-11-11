#include <bits/stdc++.h>
using namespace std;
inline int rdi() {
  int d;
  scanf("%d", &d);
  return d;
}
inline char rdc() {
  scanf(" ");
  return getchar();
}
inline string rds() {
  string s;
  cin >> s;
  return s;
}
inline double rddb() {
  double d;
  scanf("%lf", &d);
  return d;
}
template <class T>
inline bool setmin(T& a, T b) {
  return a > b ? a = b, true : false;
}
template <class T>
inline bool setmax(T& a, T b) {
  return a < b ? a = b, true : false;
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& x) {
    cerr << x << ",";
    return *this;
  }
} dbgr;
long long n, x, y, c, a[4], b[4];
long long sqr(long long t) { return t * t; }
long long f(long long t) { return 2 * (t + 1) * t + 1; }
long long g(long long t) { return t * (t + 1); }
long long calc(long long t) {
  long long s = f(t);
  for (int i = (0); i < (4); ++i)
    if (t > a[i]) s -= sqr(t - a[i]);
  for (int i = (0); i < (4); ++i)
    if (t > b[i]) s += g(t - b[i]);
  return s;
}
long long bisect(long long l, long long r) {
  while (l <= r) {
    long long m = l + r >> 1;
    if (calc(m) >= c)
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}
void init_ab() {
  a[0] = x - 1, a[1] = y - 1, a[2] = n - x, a[3] = n - y;
  for (int i = (0); i < (4); ++i) b[i] = a[i] + a[(i + 1) % 4] + 1;
}
int main() {
  cin >> n >> x >> y >> c;
  init_ab();
  cout << bisect(0, n + n) << endl;
  return 0;
}
