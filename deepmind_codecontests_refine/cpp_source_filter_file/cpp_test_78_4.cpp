#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  int p = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -p;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + (ch - '0'), ch = getchar();
  x = x * p;
}
int h[35], ans[114514], tot;
int gcd(int x, int y) {
  if (x % y == 0) return y;
  return gcd(y, x % y);
}
int main() {
  int t;
  read(t);
  while (t--) {
    memset(h, 0, sizeof(h));
    int n;
    read(n);
    int tot = 0;
    for (int i = 1; i <= n; ++i) {
      int now = 0;
      int x;
      read(x);
      while (x) {
        if (x & 1) h[now]++;
        x >>= 1;
        now++;
      }
    }
    int res = 0;
    for (int i = 0; i <= 30; ++i) {
      if (h[i]) res = h[i];
    }
    for (int i = 0; i <= 30; ++i) {
      if (h[i]) res = gcd(h[i], res);
    }
    tot = 0;
    if (!res)
      for (int i = 1; i <= n; ++i) printf("%d ", i);
    else {
      int q = sqrt(res);
      for (int i = 1; i <= q; ++i) {
        if (res % i == 0) {
          ans[++tot] = i;
          if (i * i != n) {
            ans[++tot] = res / i;
          }
        }
      }
      sort(ans + 1, ans + tot + 1);
      for (int i = 1; i <= tot; ++i) printf("%d ", ans[i]);
    }
    puts("");
  }
}
