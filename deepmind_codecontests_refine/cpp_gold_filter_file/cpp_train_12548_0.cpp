#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline long long lin() {
  long long x;
  scanf("%lld", &x);
  return x;
}
char ch[4000010];
inline string get() {
  scanf("%s", ch);
  return string(ch);
}
inline void read(long long *a, long long n) {
  for (long long i = 0; i < n; i++) a[i] = in();
}
template <class blank>
inline void out(blank x) {
  cout << x << "\n";
  exit(0);
}
template <class blank, class blank2>
inline void smin(blank &a, blank2 b) {
  a = a <= b ? a : b;
}
template <class blank, class blank2>
inline void smax(blank &a, blank2 b) {
  a = a >= b ? a : b;
}
const long long maxn = 1e6 + 10;
const long long maxm = 4e6 + 10;
const long long maxlg = 20;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long inf = 2e18 + 10;
const double eps = 1e-9;
long long a[maxn];
int32_t main() {
  long long n = in();
  if (n == 2) out(-1);
  a[0] = 6;
  a[1] = 15;
  for (long long i = 2; i < n; i++) a[i] = 10;
  for (long long i = 2; i < n; i++) a[i] *= (i - 1);
  for (long long i = 0; i < n; i++) cout << a[i] << "\n";
}
