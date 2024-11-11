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
struct node {
  long long p, s;
} b[maxn];
long long num[maxn];
int main() {
  int T = read();
  while (T--) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read(), num[i] = 0;
    m = read();
    for (int i = 1; i <= m; ++i) {
      b[i].p = read();
      b[i].s = read();
    }
    for (int i = 1; i <= m; ++i) {
      long long nows = b[i].s;
      long long nowp = b[i].p;
      num[nows] = max(num[nows], nowp);
    }
    for (int i = n; i >= 1; --i) {
      if (num[i] == 0)
        num[i] = num[i + 1];
      else {
        if (num[i] > num[i + 1]) continue;
        num[i] = num[i + 1];
      }
    }
    long long maxx = 0;
    int ans = 0;
    int pos = 1;
    bool ok = true;
    long long maxx1 = 0;
    int len;
    for (int i = 1; i <= n; ++i) {
      maxx = max(maxx, a[i]);
      maxx1 = max(maxx, a[i + 1]);
      len = i - pos + 1;
      if (i == n) {
        if (num[len] >= maxx) {
          ans++;
        } else
          ok = false;
      } else {
        if (num[len] >= maxx && num[len + 1] < maxx1) {
          ans++;
          maxx = a[i + 1];
          pos = i + 1;
        } else if (num[len] < maxx) {
          ok = false;
          break;
        }
      }
    }
    if (ok)
      printf("%d\n", ans);
    else
      puts("-1");
  }
}
