#include <bits/stdc++.h>
using namespace std;
int a[200010];
long long pre[200010];
long long n, ans, le, ri, w1, w2, v1, v2, maxh, cor, f, t;
char B[1 << 15], *S = B, *T = B;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x == 0) {
    putchar('0');
    putchar(' ');
    return;
  }
  if (x < 0) putchar('-'), x = -x;
  int len = 0, buf[15];
  while (x) buf[len++] = x % 10, x /= 10;
  for (int i = len - 1; i >= 0; i--) putchar(buf[i] + '0');
  putchar(' ');
  return;
}
long long move(int x, int y) {
  if (x <= y)
    return 0LL + ans - pre[y] + pre[x] + a[x] * (y - x);
  else
    return 0LL + ans + pre[x - 1] - pre[y - 1] + a[x] * (y - x);
}
int main() {
  maxh = -9.223372037e+18;
  n = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    pre[i] = pre[i - 1] + a[i];
    ans += 1LL * a[i] * i;
  }
  for (int i = 1; i <= n; i++) {
    le = 1;
    ri = n;
    cor = -9.223372037e+18;
    while (le + 1 <= ri) {
      w1 = le + (ri - le) / 3;
      w2 = ri - (ri - le) / 3;
      v1 = move(i, w1);
      v2 = move(i, w2);
      if (v1 > v2)
        ri = w2 - 1, cor = max(cor, v1);
      else
        le = w1 + 1, cor = max(cor, v2);
    }
    cor = max(cor, move(i, le));
    if (cor > maxh) {
      maxh = cor;
      f = i;
      t = le;
    }
  }
  printf("%I64d\n", maxh);
  return 0;
}
