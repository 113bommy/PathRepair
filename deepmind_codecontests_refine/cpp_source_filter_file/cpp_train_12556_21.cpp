#include <bits/stdc++.h>
using namespace std;
char getc() {
  char c = getchar();
  while ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z') && (c < '0' || c > '9'))
    c = getchar();
  return c;
}
int gcd(int n, int m) { return m == 0 ? n : gcd(m, n % m); }
int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return x * f;
}
int n, a[21], p[21], ans;
char s[1 << 21];
void FWT(int n, int *a, int op) {
  for (int i = 2; i <= n; i <<= 1)
    for (int j = 0; j < n; j += i)
      for (int k = j; k < j + (i >> 1); k++) {
        int x = a[k], y = a[k + (i >> 1)];
        a[k] = (x + y) % 1000000007,
        a[k + (i >> 1)] = (x - y + 1000000007) % 1000000007;
        if (op == 1)
          a[k] = 1ll * a[k] * 500000004 % 1000000007,
          a[k + (i >> 1)] = 1ll * a[k + (i >> 1)] * 500000004 % 1000000007;
      }
}
signed main() {
  n = read();
  scanf("%s", s);
  for (int i = 0; i < (1 << n); i++) a[i] = s[i] - '0';
  FWT(1 << n, a, 0);
  for (int i = 0; i < (1 << n); i++) a[i] = 1ll * a[i] * a[i] % 1000000007;
  FWT(1 << n, a, 1);
  for (int i = 0; i < (1 << n); i++) {
    int u = n, j = i;
    while (j) j ^= j & -j, u--;
    ans = (ans + 1ll * a[i] * (1 << u)) % 1000000007;
  }
  cout << 3ll * ans % 1000000007;
  return 0;
}
