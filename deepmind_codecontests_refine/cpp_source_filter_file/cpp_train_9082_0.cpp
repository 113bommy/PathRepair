#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long lxt() {
  long long aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
template <class T>
istream& operator>>(istream& is, vector<T>& input) {
  for (T& in : input) is >> in;
  return is;
}
template <class T>
ostream& operator<<(ostream& os, const vector<T>& input) {
  bool isFirst = true;
  for (T out : input) {
    if (isFirst) {
      os << out;
      isFirst = false;
    } else
      os << " " << out;
  }
  return os;
}
void solve() {
  long long l = lxt(), r = lxt(), m = lxt();
  long long mx = r - l;
  for (long long i = l; i <= r; i++) {
    long long x = (m / i);
    long long x1 = ((m + i - 1) / i);
    long long v = abs(m - x * i);
    long long v1 = abs(m - x1 * i);
    if (x > 0 && v >= 0 && v <= mx) {
      cout << i << ' ' << l + v << ' ' << l << '\n';
      return;
    }
    if (x1 > 0 && v1 >= 0 && v1 <= mx) {
      cout << i << ' ' << l << ' ' << l + v << '\n';
      return;
    }
  }
  assert(false);
}
int main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  int tc = nxt();
  while (tc--) {
    solve();
  }
  return 0;
}
