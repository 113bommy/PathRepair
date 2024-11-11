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
const int inf = 1000000000;
const int MOD = 1000000007;
unsigned long long a[10005], b[10007];
unsigned long long n, c;
unsigned long long ok(unsigned long long x) {
  unsigned long long cnt = n;
  for (int i = (1); i <= (n); ++i) {
    if (x * a[i] / b[i] + cnt > c) return c + 1;
    unsigned long long cur = (a[i] * x) / b[i];
    cnt += cur;
    if (cnt > c) break;
  }
  return cnt;
}
unsigned long long lbound(unsigned long long l, unsigned long long r) {
  while (l < r) {
    unsigned long long mid = (l + r) / 2;
    if (ok(mid) < c)
      l = mid + 1;
    else
      r = mid;
  }
  return r;
}
unsigned long long rbound(unsigned long long l, unsigned long long r) {
  while (l < r) {
    unsigned long long mid = 1 + (l + r) / 2;
    if (ok(mid) > c)
      r = mid - 1;
    else
      l = mid;
  }
  return r;
}
int main() {
  n = rdi(), c = rdi();
  for (int i = (1); i <= (n); ++i) a[i] = rdi(), b[i] = rdi();
  if (accumulate(a + 1, a + 1 + n, 0ULL)) {
    if (c == n)
      puts("-1");
    else
      puts("0");
    return 0;
  }
  unsigned long long mn = lbound(1, inf * (unsigned long long)inf * 2LL);
  unsigned long long mx = rbound(1, inf * (unsigned long long)inf * 2LL);
  if (ok(mn) != c)
    puts("0");
  else
    cout << mx - mn + 1 << endl;
  return 0;
}
