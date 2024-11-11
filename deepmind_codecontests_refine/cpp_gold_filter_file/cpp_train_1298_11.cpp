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
const int N = 110000;
long long a[N], h[N];
int num[N];
int n, m, k;
long long p;
bool check(long long x) {
  for (int i = (1); i <= (m); ++i) num[i] = 0;
  for (int i = (1); i <= (n); ++i)
    if (x < a[i]) return false;
  long long cnt = 0;
  for (int i = (1); i <= (n); ++i) {
    long long y = h[i] - x + a[i] * m;
    if (y <= 0) continue;
    cnt += y / p;
    if (y % p) ++cnt;
  }
  if (cnt > 1LL * k * m) return false;
  for (int i = (1); i <= (n); ++i) {
    long long y = h[i] - x + a[i] * m;
    if (y <= 0) continue;
    int z = y / p;
    if (y % p) ++z;
    for (int j = (1); j <= (z); ++j) {
      int k = (x + p * (j - 1)) / a[i];
      getmin(&k, m);
      num[k]++;
    }
  }
  int res = 0;
  for (int i = (1); i <= (m); ++i) {
    res += k;
    if (res < num[i]) return false;
    res -= num[i];
  }
  return true;
}
int main() {
  cin >> n >> m >> k >> p;
  for (int i = (1); i <= (n); ++i) read(h + i), read(a + i);
  long long l = 0, r = 1e13, res;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << endl;
  return 0;
}
