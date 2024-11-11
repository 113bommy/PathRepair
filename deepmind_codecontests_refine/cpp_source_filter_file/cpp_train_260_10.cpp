#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c)
    if (b & i) res = 1LL * res * a % c;
  return res;
}
const int N = 1 << 20;
long long a[N], b[N], c[N];
int t[N];
void fwt(long long *a, int l, int r) {
  if (l == r) return;
  int m = (l + r) >> 1;
  for (int i = (l); i <= (m); ++i) c[i] = a[i], a[i] += a[m + i - l + 1];
  for (int i = (m + 1); i <= (r); ++i) a[i] = c[i - m + l - 1] - a[i];
  fwt(a, l, m);
  fwt(a, m + 1, r);
}
int n, m;
int main() {
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (1); j <= (m); ++j) {
      char c;
      while (isspace(c = getchar()))
        ;
      if (c == '1') t[j] |= (1 << (i - 1));
    }
  }
  for (int i = (0); i <= ((1 << n) - 1); ++i) {
    int x = __builtin_popcount(i);
    a[i] = min(x, n - x);
  }
  for (int i = (1); i <= (m); ++i) b[t[i]] = 1;
  fwt(a, 0, (1 << n) - 1);
  fwt(b, 0, (1 << n) - 1);
  for (int i = (0); i <= ((1 << n) - 1); ++i) a[i] *= b[i];
  fwt(a, 0, (1 << n) - 1);
  for (int i = (0); i <= ((1 << n) - 1); ++i) a[i] >>= n;
  int ans = n * m;
  for (int i = (0); i <= ((1 << n) - 1); ++i) getmin(&ans, (int)a[i]);
  cout << ans << endl;
  return 0;
}
