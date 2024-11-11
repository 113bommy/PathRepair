#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long r = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while (ch >= '0' && ch <= '9') {
    r = (r << 3) + (r << 1) + (ch ^ 48);
    ch = getchar();
  }
  return r;
}
long long t[20];
int st[10010], top;
long long bao(long long x) {
  if (x < 10) return x;
  top = 0;
  st[++top] = 8;
  x -= 8;
  while (x > 9) {
    x -= 9;
    st[++top] = 9;
  }
  st[++top] = x;
  long long ssum = 0;
  while (top) ssum = ssum * 10 + st[top--];
  return ssum;
}
long long bao2(long long x) {
  top = 0;
  while (x > 9) {
    x -= 9;
    st[++top] = 9;
  }
  st[++top] = x;
  long long ssum = 0;
  while (top) ssum = ssum * 10 + st[top--];
  return ssum;
}
int main() {
  t[0] = 1;
  for (int i = 1; i <= 18; i++) t[i] = t[i - 1] * 10;
  long long T = read();
  while (T--) {
    long long n = read(), k = read(), ans = 0x7fffffffffffff;
    if (k == 0) {
      printf("%lld\n", bao2(n));
      continue;
    }
    for (int i = n / 9; i >= 0; i--) {
      for (int j = 0; j <= 9; j++) {
        long long m = n, cnt = 0;
        for (int l = 0; l <= k; l++) {
          m -= (j + l) % 10;
          cnt = (j + l) / 10 ? cnt + 1 : cnt;
        }
        m = m - cnt - 9 * i * (k - cnt + 1);
        if (m < 0 || m % (k + 1)) continue;
        m /= (k + 1);
        ans = min(ans, bao(m) * t[i + 1] + t[i + 1] - 10 + j);
      }
    }
    printf("%lld\n", ans == 0x7fffffffffffff ? -1 : ans);
  }
}
