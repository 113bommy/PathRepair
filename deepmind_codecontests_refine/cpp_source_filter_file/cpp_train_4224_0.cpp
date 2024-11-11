#include <bits/stdc++.h>
using namespace std;
template <typename T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%" PRId64, &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <typename T, typename... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
template <typename T>
void _W(const T &x) {
  cout << x;
}
void _W(const int &x) { printf("%d", x); }
template <typename T>
void _W(const vector<T> &x) {
  for (auto i = x.cbegin(); i != x.cend(); i++) {
    if (i != x.cbegin()) putchar(' ');
    _W(*i);
  }
}
void W() {}
template <typename T, typename... U>
void W(const T &head, const U &...tail) {
  _W(head);
  putchar(sizeof...(tail) ? ' ' : '\n');
  W(tail...);
}
const int N = 1e4 + 10;
int n;
long long c, a[N], b[N], d[N];
int main() {
  R(n, c);
  for (int i = 0; i < int(n); i++) R(a[i]);
  for (int i = 0; i < int(n); i++) R(b[i]);
  for (int i = 0; i < int(n); i++) d[i] = b[i] - a[i] + (n - 1LL - i) * c;
  sort(d, d + n);
  auto s = accumulate(a, a + n, 0);
  auto ans = s;
  for (int i = 0; i < int(n); i++) {
    s += d[i] - i * c;
    ;
    ans = min(ans, s);
  }
  W(ans);
  return 0;
}
