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
inline bool chmax(T &a, const T &b) {
  return b > a ? a = b, true : false;
}
template <class T>
inline bool chmin(T &a, const T &b) {
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
int main() {
  int n, a, b;
  R(n, a, b);
  vector<int> v(n);
  if (a == 0 && b == 0) {
    for (int i = 0; i < int(n); i++) {
      v[i] = 1;
    }
    W(v);
    return 0;
  }
  if (b == 0) {
    if (a + 2 <= n) {
      W(-1);
      return 0;
    }
    v[0] = 1;
    v[1] = 1;
    for (int i = 0; i < int(a); i++) v[2 + i] = v[i + 1] + 1;
    for (int i = a + 2; i < n; i++) v[i] = 1;
    W(v);
    return 0;
  }
  if (a == 0) {
    int sum = 1;
    v[0] = 1;
    for (int i = 1; i <= b; i++) {
      v[i] = sum + 1;
      if (v[i] > 50000) {
        W(-1);
        return 0;
      }
      sum += v[i];
    }
    for (int i = b + 1; i < n; i++) {
      v[i] = 1;
    }
    W(v);
    return 0;
  }
  int sum = 1;
  v[0] = 1;
  for (int i = 1; i < 1 + b; i++) {
    v[i] = sum + 1;
    sum += v[i];
  }
  for (int i = b + 1; i < b + a + 1; i++) {
    v[i] = v[i - 1] + 1;
  }
  for (int i = b + a + 1; i < n; i++) {
    v[i] = 1;
  }
  W(v);
  return 0;
}
