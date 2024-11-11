#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const long long INF = 1e18;
const int maxn = 200000 + 10;
const int maxm = 1000000000 + 7;
const int mod = 1000000000 + 7;
int gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long read() {
  char ch = getchar();
  long long x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m;
long long a[maxn];
long long num[maxn];
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read(), num[i] = 0;
    m = read();
    for (int i = 1; i <= m; ++i) {
      long long x = read(), y = read();
      num[y] = max(num[y], x);
    }
    for (int i = n - 1; i >= 1; --i) {
      num[i] = max(num[i], num[i + 1]);
    }
    bool ok = true;
    int ans = 1;
    int pos = 1;
    long long maxx = 0;
    for (int i = 1; i <= n; ++i) {
      maxx = max(maxx, a[i]);
      int len = i - pos + 1;
      if (num[len] < maxx) {
        ans++;
        pos = i;
        maxx = a[i];
      }
      if (num[1] < a[i]) ok = false;
    }
    if (ok)
      printf("%d\n", ans);
    else
      puts("-1");
  }
}
