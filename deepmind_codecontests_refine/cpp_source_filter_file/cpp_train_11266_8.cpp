#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double Pi = acos(-1);
bool inline equ(double a, double b) { return fabs(a - b) < EPS; }
int _R(int &x) { return scanf("%d", &x); }
int _R(long long &x) { return scanf("%" PRId64, &x); }
int _R(double &x) { return scanf("%lf", &x); }
int _R(char *s) { return scanf("%s", s); }
int _R(char c) { return scanf("%c", &c); }
int R() { return 0; }
template <typename T, typename... U>
int R(T &x, U &...tail) {
  return _R(x) + R(tail...);
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
const int N = 2e5 + 10;
int n, p[N];
long long a[N];
long long c[N];
long long mn[N << 2], tag[N << 2];
void init(int i, int l, int r) {
  if (l == r) {
    mn[i] = c[l];
    tag[i] = 0;
    return;
  }
  init(((i)*2), l, ((l + r) / 2));
  init(((i)*2 + 1), ((l + r) / 2) + 1, r);
  mn[i] = min(mn[((i)*2)], mn[((i)*2 + 1)]);
}
void push(int i) {
  tag[((i)*2)] += tag[i];
  mn[((i)*2)] += tag[i];
  tag[((i)*2 + 1)] += tag[i];
  mn[((i)*2 + 1)] += tag[i];
  tag[i] = 0;
}
void upd(int i, int l, int r, int qa, int qb, long long x) {
  if (qa > qb) return;
  if (qb < l || r < qa) return;
  if (qa <= l && r <= qb) {
    mn[i] += x;
    tag[i] += x;
    return;
  }
  push(i);
  upd(((i)*2), l, ((l + r) / 2), qa, qb, x);
  upd(((i)*2 + 1), ((l + r) / 2) + 1, r, qa, qb, x);
  mn[i] = min(mn[((i)*2)], mn[((i)*2 + 1)]);
}
int pos[N];
int main() {
  R(n);
  for (int i = (1); i <= (n); i++) R(p[i]);
  for (int i = (1); i <= (n); i++) R(a[i]);
  for (int i = (n); i >= (1); i--) {
    c[i] = c[i + 1] + a[i + 1];
  }
  init(1, 2, n - 1);
  for (int i = (1); i <= (n); i++) pos[p[i]] = i;
  long long ans = mn[1];
  for (int i = (n); i >= (1); i--) {
    int id = pos[i];
    upd(1, 2, n - 1, id, n - 1, a[id]);
    upd(1, 2, n - 1, 2, id - 1, -a[id]);
    ans = min(ans, mn[1]);
  }
  W(ans);
}
