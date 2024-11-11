#include <bits/stdc++.h>
using namespace std;
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
int n, a[5000 + 5], num[5000 + 5], res[5000 + 5][5000 * 2 + 5],
    ans[5000 * 2 + 5];
inline int pow(int x, int k) {
  int sum = 1;
  for (; k; k >>= 1, x = 1LL * x * x % 1000000007)
    if (k & 1) sum = 1LL * sum * x % 1000000007;
  return sum;
}
int main() {
  n = read();
  num[1] = 1;
  for (int i = 1; i < n; ++i)
    a[i] = read(), num[i + 1] = 1LL * num[i] * a[i] % 1000000007;
  for (int i = 1; i <= n; ++i) {
    int x = 1, inv = pow(a[i], 1000000007 + 2);
    for (int j = 1; j <= 2 * n + 2; ++j) {
      x = i + j > n ? 0 : 1LL * x * a[i + j - 1] % 1000000007;
      int sum = (res[i][j] + x) % 1000000007;
      ans[j] = (ans[j] + 1LL * num[i] * sum) % 1000000007;
      if (i < n)
        res[i + 1][j + 1] = (1LL * res[i + 1][j + 1] + res[i][j] +
                             1LL * x * inv % 1000000007 * (a[i] - 1)) %
                            1000000007;
    }
    if (i < n) res[i + 1][1] = (res[i + 1][1] + 1) % 1000000007;
  }
  for (int i = 1; i <= n * 2 + 2; ++i)
    printf("%d ", 1LL * ans[i] * (1000000007 + 1) / 2 % 1000000007);
  return 0;
}
