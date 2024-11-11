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
const unsigned long long inf = 1LL << 60;
const int N = 16384;
unsigned long long n, c, a[N], b[N];
unsigned long long days(unsigned long long x) {
  unsigned long long sum = n;
  for (int i = (1); i <= (n); ++i)
    if ((sum += (a[i] * x) / b[i]) > c) break;
  return sum;
}
unsigned long long lbound(unsigned long long l, unsigned long long r) {
  while (l <= r) {
    unsigned long long m = l + r >> 1;
    if (days(m) < c)
      l = m + 1;
    else
      r = m - 1;
  }
  return l;
}
unsigned long long rbound(unsigned long long l, unsigned long long r) {
  while (l <= r) {
    unsigned long long m = (l + r) / 2;
    if (days(m) > c)
      r = m - 1;
    else
      l = m + 1;
  }
  return l;
}
int main() {
  n = rdi(), c = rdi();
  for (int i = (1); i <= (n); ++i) a[i] = rdi(), b[i] = rdi();
  if (!accumulate(a + 1, a + 1 + n, 0ULL)) {
    puts(n == c ? "-1" : "0");
    return 0;
  }
  unsigned long long mn = lbound(1, inf);
  unsigned long long mx = rbound(1, inf);
  cout << mx - mn << endl;
  return 0;
}
