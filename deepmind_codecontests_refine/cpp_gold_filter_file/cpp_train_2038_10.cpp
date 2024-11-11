#include <bits/stdc++.h>
using namespace std;
const int inf = 0x0f0f0f0f;
template <class S, class T>
inline pair<S, T> MP(S a, T b) {
  return make_pair(a, b);
}
template <class T>
inline auto LX(T &X) -> decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto LX(const T &X) -> const decltype((X.first)) {
  return X.first;
}
template <class T>
inline auto RX(T &X) -> decltype((X.second)) {
  return X.second;
}
template <class T>
inline auto RX(const T &X) -> const decltype((X.second)) {
  return X.second;
}
template <class T>
inline void RST(T &a) {
  memset(a, 0, sizeof(a));
}
template <class T>
inline void RST1(T &a) {
  memset(a, -1, sizeof(a));
}
template <class T>
inline void SINF(T &a) {
  memset(a, 0x0f, sizeof(a));
}
template <class S, class T>
inline void RST(S &a, T b) {
  fill((T *)a, (T *)a + (sizeof(a) / sizeof(b)), b);
}
template <class T>
inline void CLR(T &a) {
  a.clear();
}
template <class S, class T>
inline void CPY(S &a, T &b) {
  memcpy(a, b, sizeof(a));
}
template <class S, class T>
inline bool chkmin(S &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <class S, class T>
inline bool chkmax(S &a, T b) {
  return a < b ? a = b, 1 : 0;
}
template <class T>
inline T sqr(T x) {
  return x * x;
}
template <class T>
inline int SZ(T &a) {
  return (int)(a.size());
}
template <class T>
inline bool EPT(T &a) {
  return a.empty();
}
template <class T>
inline auto FRT(T &a) -> decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto FRT(const T &a) -> const decltype((a.front())) {
  return a.front();
}
template <class T>
inline auto BK(T &a) -> decltype(a.back()) & {
  return a.back();
}
template <class T>
inline auto BK(const T &a) -> const decltype((a.back())) {
  return a.back();
}
template <class T>
inline auto TOP(T &a) -> decltype((a.top())) {
  return a.top();
}
template <class T>
inline auto TOP(const T &a) -> const decltype((a.top())) {
  return a.top();
}
const double eps = 1e-9;
complex<double> S, T;
int n;
complex<double> a[110];
complex<double> get() {
  int x, y;
  scanf("%d%d", &x, &y);
  return complex<double>(x, y);
}
vector<pair<complex<double>, int> > c;
int pd(complex<double> a, complex<double> b, complex<double> p,
       complex<double> q) {
  double t = imag((p - a) * conj(b - a)) * imag((q - a) * conj(b - a));
  if (t > eps) return 0;
  if (t < -eps) return 1;
  return fabs(imag((b - a) * conj(q - p))) < eps ? 3 : 2;
}
int isintersect(complex<double> a, complex<double> b, complex<double> p,
                complex<double> q) {
  int x = pd(a, b, p, q), y = pd(p, q, a, b);
  if (!x || !y) return 0;
  if (x != 3) return x == 1 && y == 1 ? 1 : 2;
  return 3;
}
bool b;
complex<double> intersect(complex<double> a, complex<double> b,
                          complex<double> p, complex<double> q) {
  double x = imag((b - a) * conj(p - a)), y = imag((q - a) * conj(b - a));
  return (p * y + q * x) / (x + y);
}
int main() {
  S = get(), T = get();
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) a[i] = get();
  for (int i = 1; i <= n; i++) {
    int x = isintersect(S, T, a[i], a[i % n + 1]);
    if (x == 3) return printf("%.10lf\n", abs(T - S)), 0;
    b |= x;
  }
  if (!b) return printf("%.10lf\n", abs(T - S)), 0;
  for (int i = 1; i <= n; i++) {
    int x = isintersect(S, T, a[i], a[i % n + 1]);
    if (x) c.push_back(MP(intersect(S, T, a[i], a[i % n + 1]), i));
  }
  for (auto i = c.begin(); i != c.end(); i++)
    for (auto j = i + 1; j != c.end(); j++)
      if (abs(j->first - i->first) < eps) {
        c.erase(j);
        break;
      }
  if (SZ(c) == 1) return printf("%.10lf\n", abs(T - S)), 0;
  complex<double> aa = LX(c[0]), bb = LX(c[1]);
  int ai = RX(c[0]), bi = RX(c[1]);
  if (abs(aa - S) > abs(bb - S)) swap(aa, bb), swap(ai, bi);
  double d = abs(aa - S) + abs(T - bb), ans = d + 2 * abs(bb - aa);
  double x = d;
  complex<double> t = aa;
  for (int i = ai % n + 1; i != bi; i = i % n + 1) x += abs(a[i] - t), t = a[i];
  x += abs(a[bi] - t) + abs(bb - a[bi]);
  chkmin(ans, x);
  x = d;
  t = bb;
  for (int i = bi % n + 1; i != ai; i = i % n + 1) x += abs(a[i] - t), t = a[i];
  x += abs(a[ai] - t) + abs(aa - a[ai]);
  chkmin(ans, x);
  printf("%.10lf\n", ans);
  return 0;
}
