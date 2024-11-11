#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC diagnostic ignored "-Wunused-function"
using namespace std;
namespace {
namespace unolight {
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(int64_t &x) { scanf("%" PRId64, &x); }
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
void _W(const double &x) { printf("%.16f\n", x); }
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
template <class T>
inline bool chmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - begin(v));
}
char B[10][10];
void main() {
  int ans = 100;
  for (int i = 0; i < 8; i++) scanf("%s", B[i]);
  for (int mask = 0; mask < (1 << 16); mask++) {
    char C[10][10] = {};
    for (int i = 0; i < int(8); i++)
      for (int j = 0; j < int(8); j++) C[i][j] = 'W';
    for (int i = 0; i < 8; i++) {
      if (mask >> i & 1) {
        for (int j = 0; j < 8; j++) C[i][j] = 'B';
      }
    }
    for (int i = 0; i < 8; i++) {
      if (mask >> (i + 8) & 1) {
        for (int j = 0; j < 8; j++) C[j][i] = 'B';
      }
    }
    bool ok = true;
    for (int i = 0; i < int(8); i++)
      for (int j = 0; j < int(8); j++)
        if (B[i][j] ^ C[i][j]) {
          ok = 0;
          break;
        }
    if (!ok) continue;
    chmin(ans, __builtin_popcount(mask));
  }
  W(ans);
}
}  // namespace unolight
}  // namespace
int main() {
  unolight::main();
  return 0;
}
