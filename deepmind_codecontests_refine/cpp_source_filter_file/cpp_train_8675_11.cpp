#include <bits/stdc++.h>
using namespace std;
inline bool SR(int &x) { return scanf("%d", &x) == 1; }
inline bool SR(long long &x) { return scanf("%lld", &x) == 1; }
inline bool SR(double &x) { return scanf("%lf", &x) == 1; }
inline bool SR(char *s) { return scanf("%s", s) == 1; }
inline bool RI() { return true; }
template <typename I, typename... T>
inline bool RI(I &x, T &...tail) {
  return SR(x) && RI(tail...);
}
inline void SP(const int x) { printf("%d", x); }
inline void SP(const long long x) { printf("%lld", x); }
inline void SP(const double x) { printf("%.16lf", x); }
inline void SP(const char *s) { printf("%s", s); }
inline void PL() { puts(""); }
template <typename I, typename... T>
inline void PL(const I x, const T... tail) {
  SP(x);
  if (sizeof...(tail)) putchar(' ');
  PL(tail...);
}
template <typename I>
void _DOING(const char *s, I &&x) {
  cerr << s << " = " << x << endl;
}
template <typename I, typename... T>
void _DOING(const char *s, I &&x, T &&...tail) {
  int c = 0;
  while (*s != ',' || c != 0) {
    if (*s == '(' || *s == '[' || *s == '{') c++;
    if (*s == ')' || *s == ']' || *s == '}') c--;
    cerr << *s++;
  }
  cerr << " = " << x << " , ";
  _DOING(s + 1, tail...);
}
const int INF = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3fll;
inline int RAND() {
  static int x = 880301;
  return (x = x * 0xdefaced + 1) % 0x7fffffff;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int cx = 1, cy = 1;
  while (n--) {
    string s;
    cin >> s;
    if (s == "UR")
      cx++;
    else if (s == "UL")
      cy++;
    else if (s == "DR")
      cx++;
    else if (s == "DL")
      cy++;
    else
      cx++, cy++;
  }
  long long ans = 1ll * cx * cy;
  cout << ans << '\n';
  return 0;
}
