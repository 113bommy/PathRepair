#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (ch < '0') ch = getchar();
  while (ch >= '0') {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
int m, n;
long long tmp, s[2] = {0, 0}, b[100100], a[100100];
long long do_exp(int a, int p) {
  long long ret = 1;
  for (; p; p >>= 1, a = 1LL * a * a % m)
    if (p & 1) (ret = ret * a) %= m;
  return ret;
}
int main() {
  scanf("%d %d", &m, &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", a + i);
    (s[0] += a[i]) %= m;
    (s[1] += a[i] * a[i]) %= m;
  }
  if (n == 1) {
    printf("%lld 0\n", a[1]);
    return 0;
  }
  if (n == m) {
    puts("0 1");
    return 0;
  }
  sort(a + 1, a + 1 + n);
  for (int i = 2; i <= n; ++i) {
    int d = (a[i] - a[i - 1]) % m;
    tmp = (s[0] - 1LL * n * (n - 1) / 2 % m * d % m + m) % m *
          do_exp(n, m - 2) % m;
    long long ret =
        (1LL * n * tmp % m * tmp % m + 1LL * n * (n - 1) % m * tmp % m * d % m +
         1LL * (n - 1) * n * (2 * n - 1) / 6 % m * d % m * d % m) %
        m;
    if (ret == s[1]) {
      b[1] = tmp;
      for (int i = 2; i <= n; ++i) b[i] = (b[i - 1] + d) % m;
      sort(b + 1, b + 1 + n);
      bool flag = 1;
      for (int i = 1; i <= n; ++i) flag &= (a[i] == b[i]);
      if (flag) {
        printf("%lld %d\n", tmp, d);
        return 0;
      }
    }
  }
  puts("-1");
  return 0;
}
