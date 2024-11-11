#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0;
  bool flg = false;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') flg = true;
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return flg ? -x : x;
}
const long long INF = 2e17;
long long X[128], Y[128];
int n;
long long a, b, c, d;
long long myabs(long long x) { return x < 0 ? -x : x; }
long long getdis(long long x, long long y, long long X, long long Y) {
  return myabs(x - X) + myabs(y - Y);
}
void solve() {
  X[0] = read(), Y[0] = read();
  a = read(), b = read(), c = read(), d = read();
  long long x = read(), y = read(), t = read();
  while (X[n] * a + c <= INF && Y[n] * b + d <= INF) {
    X[n + 1] = X[n] * a + c;
    Y[n + 1] = Y[n] * b + d;
    ++n;
  }
  int ans = 0;
  for (int l(0), _l(n); l <= _l; l++)
    for (int r(l), _r(n); r <= _r; r++) {
      bool ok = 0;
      for (int k(l), _k(r); k <= _k; k++) {
        ok = ok || getdis(x, y, X[k], Y[k]) + getdis(X[k], Y[k], X[l], Y[l]) +
                           getdis(X[l], Y[l], X[r], Y[r]) <=
                       t;
        ok = ok || getdis(x, y, X[k], Y[k]) + getdis(X[k], Y[k], X[r], Y[r]) +
                           getdis(X[l], Y[l], X[r], Y[r]) <=
                       t;
      }
      if (ok) ans = max(ans, r - l + 1);
    }
  printf("%d\n", ans);
}
int main() {
  for (int T = 1; T--;) solve();
  return 0;
}
