#include <bits/stdc++.h>
using namespace std;
int a[300000];
int s[2];
int b[300000];
int fp(int a, int k, int m) {
  int res = 1;
  while (k) {
    if (k & 1) res = 1LL * res * a % m;
    a = 1LL * a * a % m;
    k >>= 1;
  }
  return res;
}
int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  s[0] = s[1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[0] = (s[0] + a[i]) % m;
    s[1] = (s[1] + 1LL * a[i] * a[i]) % m;
  }
  if (n == 1) {
    return 0 * printf("%d 0\n", a[1]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    int d = (a[i] - a[1] + m) % m;
    int x = 1LL * (s[0] - 1LL * n * (n - 1) / 2 % m * d % m + m) % m *
            fp(n, m - 2, m) % m;
    int ans = 1LL * n * x % m * x % m;
    ans = (ans + 1LL * n * (n - 1) % m * d % m * x % m) % m;
    ans = (ans + 1LL * n * (n - 1) * (2 * n - 1) / 6 % m * d % m * d % m) % m;
    if (ans == s[1]) {
      b[1] = x;
      for (int j = 2; j <= n; j++) {
        b[j] = b[j - 1] + d;
        b[j] %= m;
      }
      sort(b + 1, b + n + 1);
      bool flag = true;
      for (int j = 1; j <= n; j++) {
        if (a[j] != b[j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        return 0 * printf("%d %d\n", x, d);
      }
    }
  }
  return 0 * printf("-1\n");
}
