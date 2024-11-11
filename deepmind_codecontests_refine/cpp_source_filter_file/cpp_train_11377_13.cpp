#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long n, ans, f[N], now, sum;
char s[N];
signed main() {
  scanf("%lld", &n);
  scanf("%s", s + 1);
  for (long long i = 1; i <= n; i++) f[i] = n + 1;
  for (long long i = n; i >= 1; i--) {
    if (s[i] - '0')
      sum += f[++now] - i;
    else {
      while (now) f[now--] = now + i;
    }
    ans += sum;
  }
  printf("%lld\n", ans);
  return 0;
}
