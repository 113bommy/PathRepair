#include <bits/stdc++.h>
using namespace std;
const int mo = 1e9 + 7, N = 1e6 + 5;
int n, p[N], fac[N], f[N], t[N];
long long ans, sum = 1;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  reverse(p + 1, p + n + 1);
  fac[0] = 1;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int x = p[i]; x; x -= x & -x) cnt += t[x];
    (ans += sum * cnt) %= mo;
    (ans += (long long)cnt * (cnt - 1) / 2 % mo * fac[i - 1] % mo +
            (long long)cnt * f[i - 1]) %= mo;
    fac[i] = (long long)fac[i - 1] * i % mo;
    for (int x = p[i]; x <= n; x += x & -x) t[x]++;
    f[i] = ((long long)i * (i - 1) / 2 % mo * fac[i - 1] % mo +
            (long long)cnt * f[i - 1]) %
           mo;
    (sum += (long long)cnt * fac[i - 1]) %= mo;
  }
  printf("%I64d\n", (ans + mo) % mo);
  scanf("\n");
}
