#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
using namespace std;
namespace {
namespace shik {
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" SCNd64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <class T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
void _W(const int64_t &x) { printf("%" PRId64, x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template <class T>
void _W(const vector<T> &x) {
  for (auto i = x.begin(); i != x.end(); _W(*i++))
    if (i != x.cbegin()) putchar(' ');
}
void W() {}
template <class T, class... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
template <class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - begin(v));
}
template <class T>
inline T bit(T x, int i) {
  return (x >> i) & 1;
}
template <class T>
inline bool chkmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
const int N = 5e5 + 10;
int n, d;
int64_t k, a[N], b[N];
void build() {
  int l = 1, r = 0;
  int64_t s = 0;
  for (int i = (1); i <= int(n); i++) {
    while (l < i - d) s -= a[l++];
    while (r + 1 <= n && r + 1 <= i + d) s += a[++r];
    b[i] = s;
  }
}
int64_t out[N];
bool chk(int64_t m) {
  for (int i = (1); i <= int(n); i++) out[i] = 0;
  int64_t s = 0, c = 0;
  for (int i = (1); i <= int(n); i++) {
    if (b[i] + s < m) {
      int64_t t = m - (b[i] + s);
      s += t;
      c += t;
      if (i + d + d <= n) out[i + d + d] += c;
    }
    s -= out[i];
    if (c > m) break;
  }
  return c <= k;
}
void main() {
  R(n, d, k);
  for (int i = (1); i <= int(n); i++) R(a[i]);
  build();
  int64_t l = 0, r = 2e18;
  while (l != r) {
    int64_t m = (l + r + 1) / 2;
    if (chk(m))
      l = m;
    else
      r = m - 1;
  }
  W(l);
}
}  // namespace shik
}  // namespace
int main() {
  shik::main();
  return 0;
}
