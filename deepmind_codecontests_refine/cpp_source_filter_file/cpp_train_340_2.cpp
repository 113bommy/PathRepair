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
const int _ = 307, lglg = 9;
const long long linf = 0x3f3f3f3f3f3f3f3f;
int n, m;
long long xdis[lglg + 1][_][_] = {0};
void make(long long z[_][_], long long a[_][_], long long b[_][_]) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      long long temp = -linf;
      for (int k = 1; k <= n; k++) temp = max(temp, a[i][k] + b[k][j]);
      z[i][j] = temp;
    }
}
long long now[_][_], temp[_][_];
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  n = ty(), m = ty();
  memset(xdis, -64, sizeof(xdis));
  for (int i = 1; i <= n; i++) xdis[0][i][i] = 0;
  for (int i = 1, a, b; i <= m; i++)
    a = ty(), b = ty(), xdis[0][a][b] = ty(), xdis[0][b][a] = ty();
  for (int i = 1; i <= lglg; i++) make(xdis[i], xdis[i - 1], xdis[i - 1]);
  memset(now, -64, sizeof(now));
  for (int i = 1; i <= n; i++) now[i][i] = 0;
  long long ans = 0;
  for (int i = lglg; i >= 0; i--) {
    make(temp, now, xdis[i]);
    int got = 0;
    for (int j = 1; j <= n; j++)
      if (temp[j][j] > 0) {
        got = j;
        break;
      }
    if (!got) ans += 1 << i, memcpy(now, temp, sizeof(now));
  }
  if (ans > n) ans = 0;
  cout << ans << lf;
  return 0;
}
