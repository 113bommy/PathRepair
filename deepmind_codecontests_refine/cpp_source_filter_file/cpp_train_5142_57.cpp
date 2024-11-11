#include <bits/stdc++.h>
using namespace std;
inline bool SR(int &x) { return scanf("%d", &x) == 1; }
inline bool SR(long long &x) { return scanf("%lld", &x) == 1; }
inline bool SR(double &x) { return scanf("%lf", &x); }
inline bool SR(char *s) { return scanf("%s", s); }
inline bool RI() { return 1; }
template <typename I, typename... T>
bool RI(I &x, T &...tail) {
  return SR(x) && RI(tail...);
}
inline void SP(const int x) { printf("%d", x); }
inline void SP(const long long x) { printf("%lld", x); }
inline void SP(const double x) { printf("%.10f", x); }
inline void SP(const char *s) { printf("%s", s); }
inline void PL() { puts(""); }
template <typename I, typename... T>
void PL(const I x, const T... tail) {
  SP(x);
  if (sizeof...(tail)) putchar(' ');
  PL(tail...);
}
template <typename I>
inline void _DOING(const char *s, I &&x) {
  cerr << s << " = " << x << '\n';
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
  return x = (x * 0xdefacedll + 1ll) % 0x7fffffffll;
}
int main() {
  for (int i = 0; i < int(9); i++) printf("%d??<>%d\n", i, i + 1);
  PL("9??>>??0");
  PL("??<>1");
  for (int i = 0; i < int(10); i++) printf("?%d>>%d?\n", i, i);
  PL(">>?");
  return 0;
}
