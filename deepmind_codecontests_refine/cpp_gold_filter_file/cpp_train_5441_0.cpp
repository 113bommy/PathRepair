#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 5e5 + 10;
const long long INF = 2e18;
const double PI = acos(-1);
const double eps = 1e-6;
long long n, m;
long long x[MAXN], y[MAXN];
long long L, R, mid, X, Y;
char s[MAXN];
template <typename T>
inline void read(T &a) {
  a = 0;
  char c = getchar();
  long long f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  a *= f;
}
long long B(long long x, long long y) { return y - x; }
bool chk(long long l) {
  long long x1 = -INF, x2 = INF, y1 = -INF, y2 = INF, b1 = -INF, b2 = INF;
  for (long long i = 1; i <= n; ++i) {
    x1 = max(x1, x[i] - l);
    x2 = min(x2, x[i] + l);
    y1 = max(y1, y[i] - l);
    y2 = min(y2, y[i] + l);
    b1 = max(b1, x[i] - y[i] - l);
    b2 = min(b2, x[i] - y[i] + l);
  }
  x1 = max(x1, 0ll), y1 = max(y1, 0ll);
  if (x1 > x2 || y1 > y2 || b1 > b2) return false;
  if (x1 - y2 > b2 || x2 - y1 < b1) return false;
  X = min(x2, y2 + b2);
  Y = min(y2, X - b1);
  return true;
}
signed main() {
  read(n);
  for (long long i = 1, Len; i <= n; ++i) {
    scanf("%s", s + 1);
    Len = strlen(s + 1);
    for (long long p = 1; p <= Len; ++p) {
      if (s[p] == 'B')
        x[i]++;
      else
        y[i]++;
    }
  }
  chk(1);
  L = 0, R = 1e6;
  while (L < R) {
    mid = (L + R) >> 1;
    if (chk(mid))
      R = mid;
    else
      L = mid + 1;
  }
  cout << L << endl;
  for (long long i = 1; i <= X; ++i) putchar('B');
  for (long long i = 1; i <= Y; ++i) putchar('N');
  return 0;
}
