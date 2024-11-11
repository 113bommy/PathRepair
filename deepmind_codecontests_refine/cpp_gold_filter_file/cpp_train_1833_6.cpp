#include <bits/stdc++.h>
using namespace std;
template <typename T>
void cmax(T& a, T b) {
  a = max(a, b);
}
template <typename T>
void cmin(T& a, T b) {
  a = min(a, b);
}
void _BG(const char* s) {}
template <typename T, typename... TT>
void _BG(const char* s, T a, TT... b) {
  for (int c = 0; *s && (c || *s != ','); ++s) {
    cerr << *s;
    switch (*s) {
      case '(':
      case '[':
      case '{':
        ++c;
        break;
      case ')':
      case ']':
      case '}':
        --c;
        break;
    }
  }
  cerr << " = " << a;
  if (*s) {
    cerr << ", ";
    _BG(++s, b...);
  } else
    cerr << endl;
}
bool RD(void) { return true; }
bool RD(char& a) { return scanf(" %c", &a) == 1; }
bool RD(char* a) { return scanf("%s", a) == 1; }
bool RD(double& a) { return scanf("%lf", &a) == 1; }
bool RD(int& a) { return scanf("%d", &a) == 1; }
bool RD(long long& a) { return scanf("%lld", &a) == 1; }
template <typename T, typename... TT>
bool RD(T& a, TT&... b) {
  return RD(a) && RD(b...);
}
void PT(const char a) { putchar(a); }
void PT(const char* a) { fputs(a, stdout); }
void PT(char* a) { fputs(a, stdout); }
void PT(const double a) { printf("%.16f", a); }
void PT(const int a) { printf("%d", a); }
void PT(const long long a) { printf("%lld", a); }
template <char sep = ' ', char end = '\n'>
void PL(void) {
  if (end) PT(end);
}
template <char sep = ' ', char end = '\n', typename T, typename... TT>
void PL(const T a, const TT... b) {
  PT(a);
  if (sizeof...(b) && sep) PT(sep);
  PL<sep, end>(b...);
}
const int N = 1e5 + 87;
int sl[N], sr[N], st[N], sb[N];
pair<int, int> x[N], y[N];
int main() {
  int d;
  RD(d);
  int n;
  RD(n);
  int m;
  RD(m);
  for (int i(0), _B(d); i < _B; ++i) {
    RD(x[i].first, y[i].first, x[i].second, y[i].second);
    if (x[i].first > x[i].second) swap(x[i].first, x[i].second);
    if (y[i].first > y[i].second) swap(y[i].first, y[i].second);
    ++sl[x[i].first];
    ++sr[x[i].second];
    ++st[y[i].first];
    ++sb[y[i].second];
  }
  for (int i(1), _B((n) + 1); i < _B; ++i) sl[i] += sl[i - 1];
  for (int i(1), _B((m) + 1); i < _B; ++i) st[i] += st[i - 1];
  for (int i(((n - 1) + 1) - 1), _B(1); i >= _B; --i) sr[i] += sr[i + 1];
  for (int i(((m - 1) + 1) - 1), _B(1); i >= _B; --i) sb[i] += sb[i + 1];
  int cl;
  RD(cl);
  int cr;
  RD(cr);
  int ct;
  RD(ct);
  int cb;
  RD(cb);
  for (int i(0), _B(d); i < _B; ++i) {
    if (sl[x[i].second - 1] - (x[i].first < x[i].second) == cl &&
        sr[x[i].first + 1] - (x[i].second > x[i].first) == cr &&
        st[y[i].second - 1] - (y[i].first < y[i].second) == ct &&
        sb[y[i].first + 1] - (y[i].second > y[i].first) == cb) {
      PL(i + 1);
      return 0;
    }
  }
  PL(-1);
}
