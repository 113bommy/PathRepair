#include <bits/stdc++.h>
using namespace std;
template <typename T1, typename T2>
inline T1 max(T1 a, T2 b) {
  return a < b ? b : a;
}
template <typename T1, typename T2>
inline T1 min(T1 a, T2 b) {
  return a < b ? a : b;
}
const char lf = '\n';
namespace ae86 {
const int bufl = 1 << 15;
char buf[bufl], *s = buf, *t = buf;
inline int fetch() {
  if (s == t) {
    t = (s = buf) + fread(buf, 1, bufl, stdin);
    if (s == t) return EOF;
  }
  return *s++;
}
inline int ty() {
  int a = 0;
  int b = 1, c = fetch();
  while (!isdigit(c)) b ^= c == '-', c = fetch();
  while (isdigit(c)) a = a * 10 + c - 48, c = fetch();
  return b ? a : -a;
}
}  // namespace ae86
using ae86::ty;
const int _ = 307, __ = _ * _;
long double lgi[__] = {0}, slgi[__] = {0};
void fuck(int n = __ - 1) {
  lgi[0] = -1;
  for (int i = 1; i <= n; i++) lgi[i] = log(i);
  slgi[0] = 0, slgi[1] = 0;
  for (int i = 2; i <= n; i++) slgi[i] = slgi[i - 1] + lgi[i];
}
long double lgC(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return slgi[n] - slgi[m] - slgi[n - m];
}
int n, m, tar;
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  fuck();
  n = ty(), m = ty(), tar = ty();
  long double ans = 0;
  for (int i = 0; i <= tar && i <= n; i++)
    for (int j = 0, cnt; j <= tar && j <= n; j++)
      if ((cnt = i * n + j * n - i * j) <= tar)
        ans = min(ans + exp(lgC(n, i) + lgC(n, j) + lgC(m - cnt, tar - cnt) -
                            lgC(m, tar)),
                  1e99);
  cout << setprecision(11) << fixed << ans << lf;
  return 0;
}
