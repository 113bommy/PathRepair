#include <bits/stdc++.h>
using namespace std;
int v[100];
long long fib[100], f[100][2];
int main() {
  fib[1] = 1, fib[2] = 2;
  for (int i = 3; i <= 89; i++) fib[i] = fib[i - 1] + fib[i - 2];
  int T;
  scanf("%d", &T);
  while (T--) {
    int cnt = 0;
    long long n;
    scanf("%lld", &n);
    for (int i = 89; i >= 1; i--)
      if (n >= fib[i]) v[++cnt] = i, n -= fib[i];
    reverse(v + 1, v + cnt + 1);
    f[1][0] = (v[1] - 1) / 2, f[1][1] = 1;
    for (int i = 2; i <= cnt; i++) {
      f[i][0] = f[i - 1][0] + f[i - 1][1];
      f[i][1] = f[i - 1][0] * ((v[i] - v[i - 1]) / 2) +
                f[i - 1][1] * ((v[i] - v[i - 1] - 1) / 2);
    }
    printf("%lld\n", f[cnt][0] + f[cnt][1]);
  }
  return 0;
}
