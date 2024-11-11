#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &a, T b) {
  return b < a ? a = b, 1 : 0;
}
template <typename T>
inline bool chkmax(T &a, T b) {
  return b > a ? a = b, 1 : 0;
}
inline long long read() {
  long long x(0), sgn(1);
  char ch(getchar());
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') sgn = -1;
  for (; isdigit(ch); ch = getchar()) x = (x * 10) + (ch ^ 48);
  return x * sgn;
}
void File() {}
map<long long, long long> f;
int main() {
  File();
  int n = read();
  f[read() - 1] = 0;
  for (register int i = (2), iend = (int)(n); i <= iend; ++i) {
    long long v = read();
    for (;;) {
      auto it = f.end();
      if (it == f.begin()) break;
      --it;
      long long a = it->first, b = it->second;
      if (a < v) break;
      chkmax(f[v - 1], b + (i - 1) * (a - a % v - v));
      chkmax(f[a % v], b + (i - 1) * (a - a % v));
      f.erase(it);
    }
  }
  long long ans = 0;
  for (auto it : f) chkmax(ans, n * it.first + it.second);
  printf("%lld\n", ans);
  return 0;
}
