#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
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
inline bool chkmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chkmin(T &a, const T &b) {
  return b < a ? a = b, true : false;
}
template <class T, class F = less<T>>
void sort_uniq(vector<T> &v, F f = F()) {
  sort(begin(v), end(v), f);
  v.resize(unique(begin(v), end(v)) - begin(v));
}
template <class T>
using MaxHeap = priority_queue<T>;
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
const int N = 1e5 + 10;
const int64_t INF = 1e18;
struct E {
  int to;
  int64_t k;
};
int n;
int64_t a[N], b[N];
vector<E> e[N];
int64_t go(int p) {
  int64_t s = a[p] - b[p];
  long double sd = s;
  for (auto i : e[p]) {
    auto x = go(i.to);
    if (x >= 0) {
      sd += x;
      s += x;
    } else {
      sd += (long double)i.to * x;
      if (sd < -INF) throw 0;
      s += i.to * x;
    }
  };
  return s;
}
int main() {
  R(n);
  for (int i = (1); i <= int(n); i++) R(a[i]);
  for (int i = (1); i <= int(n); i++) R(b[i]);
  for (int i = (2); i <= int(n); i++) {
    int x;
    int64_t k;
    R(x, k);
    e[x].push_back({i, k});
  }
  try {
    auto x = go(1);
    W(x >= 0 ? "YES" : "NO");
  } catch (int) {
    W("NO");
  }
  return 0;
}
