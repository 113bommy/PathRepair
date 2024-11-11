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
const int _ = 3007;
inline void failure() {
  cout << "no" << lf;
  exit(0);
}
struct cxk {
  int x, d;
  cxk(int x_ = 0, int d_ = 0) { x = x_, d = d_; }
  friend int operator<(cxk a, cxk b) { return a.d < b.d; }
} ps[_];
int n, m;
char ans[_][_] = {0};
int main() {
  ios::sync_with_stdio(0), cout.tie(nullptr);
  m = ty(), n = ty();
  for (int i = 1; i <= m; i++) ps[i].x = i;
  int mival = 1e9;
  long long sval = 0;
  for (int i = m - n + 1; i <= m; i++)
    ps[i].d = ty(), mival = min(mival, ps[i].d), sval += ps[i].d;
  if (sval > m * (m - 1)) failure();
  long long lef = m * (m - 1) - sval;
  for (int i = 1; i <= m - n; i++)
    ps[i].d = lef / (m - n) + (i <= lef % (m - n));
  if (m > n && ps[1].d > sval) failure();
  sort(ps + 1, ps + m + 1), sval = 0;
  for (int i = 1; i <= m; i++) {
    sval += ps[i].d;
    if (sval < i * (i - 1)) failure();
  }
  for (int i = 1; i <= m; i++) ans[i][i] = 'X';
  for (int i = m; i >= 1; i--) {
    sort(ps + 1, ps + i + 1);
    for (int j = 1; j < i; j++) {
      if (ps[i].d >= 2)
        ps[i].d -= 2, ans[ps[i].x][ps[j].x] = 'W', ans[ps[j].x][ps[i].x] = 'L';
      else if (ps[i].d)
        ps[i].d--, ps[j].d--, ans[ps[i].x][ps[j].x] = 'D',
                              ans[ps[j].x][ps[i].x] = 'D';
      else
        ps[j].d -= 2, ans[ps[i].x][ps[j].x] = 'L', ans[ps[j].x][ps[i].x] = 'W';
    }
  }
  cout << "yes" << lf;
  for (int i = 1; i <= m; i++, cout << lf)
    for (int j = 1; j <= m; j++) cout << ans[i][j];
  return 0;
}
