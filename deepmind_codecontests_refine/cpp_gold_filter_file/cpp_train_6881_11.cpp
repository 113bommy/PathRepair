#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, mod = 1e9 + 7;
int a[N], b[N], ans, w, l[N], r[N], ss[N];
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
int main() {
  int n = read(), k = read() - 1;
  for (int i = 1; i <= n; i++) a[i] = read();
  a[0] = a[n + 1] = 1e9 + 1;
  b[w = 1] = 0;
  for (int i = 1; i <= n; i++) {
    while (a[b[w]] <= a[i]) w--;
    l[i] = b[w];
    b[++w] = i;
  }
  b[w = 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    while (a[b[w]] < a[i]) w--;
    r[i] = b[w];
    b[++w] = i;
  }
  for (int i = 1; i * k < n; i++)
    ss[i] = ((long long)i * k + 1 + ss[i - 1]) % mod;
  for (int i = 1; i <= n; i++) {
    int x = i - l[i] - 1, y = r[i] - i - 1, z = a[i];
    if (x > y) swap(x, y);
    int s = x / k, p = y / k, q = (x + y) / k;
    ans = (((long long)ss[s] + (long long)(p - s) * (x + 1) +
            (long long)(x + y - k * (p + 1) + 1 + x + y - k * q + 1) * (q - p) /
                2) %
               mod * z +
           ans) %
          mod;
  }
  printf("%d\n", ans);
  return 0;
}
