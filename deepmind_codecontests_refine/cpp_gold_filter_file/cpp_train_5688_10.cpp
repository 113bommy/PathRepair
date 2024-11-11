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
int ksm(int b, int k) {
  int ans = 1;
  while (k) {
    if (k & 1) ans = 1ll * ans * b % 1000000007;
    b = 1ll * b * b % 1000000007;
    k >>= 1;
  }
  return ans;
}
int seq[5005], a[5005];
int main() {
  int n = read(), k = read();
  seq[0] = 1;
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
    for (int j = i; j > 0; --j) {
      seq[j] = (1ll * seq[j] * a[i] % 1000000007 - seq[j - 1] + 1000000007) %
               1000000007;
    }
    seq[0] = 1ll * seq[0] * a[i] % 1000000007;
  }
  int ans = 0, mul = 1, inv = ksm(n, 1000000007 - 2);
  for (int i = 0; i <= n; ++i) {
    ans = (ans + 1ll * seq[i] * mul % 1000000007) % 1000000007;
    mul = 1ll * mul * (k - i) % 1000000007 * inv % 1000000007;
  }
  printf("%d\n", (seq[0] - ans + 1000000007) % 1000000007);
  return 0;
}
