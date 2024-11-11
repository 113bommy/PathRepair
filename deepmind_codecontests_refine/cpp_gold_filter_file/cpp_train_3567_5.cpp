#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') {
      w = -1;
    }
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return w * s;
}
long long f[1000005][2], c1, c2, c3, d, a[1000005];
int n;
int main() {
  n = read();
  c1 = read();
  c2 = read();
  c3 = read();
  d = read();
  for (int i = 1; i <= n; i++) {
    a[i] = read();
  }
  f[1][0] = c1 * a[1] + c3;
  f[1][1] = min(c2, c1 * (a[1] + 1));
  for (int i = 1; i < n; i++) {
    f[i + 1][1] = f[i][0] + d + min(c2, c1 * (a[i + 1] + 1));
    f[i + 1][1] = min(f[i + 1][1],
                      f[i][1] + d + min(c2, c1 * (a[i + 1] + 1)) + c1 + 2 * d);
    f[i + 1][0] = f[i][0] + c1 * a[i + 1] + c3 + d;
    f[i + 1][0] =
        min(f[i + 1][0], f[i][1] + d + c1 * a[i + 1] + c3 + c1 + 2 * d);
    f[i + 1][0] = min(f[i + 1][0], f[i][1] + d + min(c2, c1 * (a[i + 1] + 1)) +
                                       d + c1 + d + c1);
  }
  cout << min(f[n][0], f[n - 1][1] + d + c1 * a[n] + c3 + d + c1);
  return 0;
}
