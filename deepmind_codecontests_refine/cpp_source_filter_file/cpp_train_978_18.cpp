#include <bits/stdc++.h>
using namespace std;
int n;
long long a[1000005], d[1000005], cnt, num[1000005], ans;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
int main() {
  srand(19260817);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  int k = 12;
  while (k--) {
    long long x = a[(rand() << 15 | rand()) % n + 1];
    cnt = 0;
    for (long long i = 1; i * i <= x; i++)
      if (x % i == 0) {
        d[++cnt] = i, i * i != x && (d[++cnt] = x / i);
      }
    sort(d + 1, d + 1 + cnt);
    for (int i = 1; i <= cnt; i++) num[i] = 0;
    for (int i = 1; i <= n; i++)
      num[lower_bound(d + 1, d + 1 + cnt, gcd(x, a[i])) - d]++;
    for (int i = cnt - 1; i >= 1; i--) {
      int tmp = 0;
      for (int j = i + 1; j <= cnt; j++)
        if (d[j] % d[i] == 0) tmp += num[j];
      if ((num[i] + tmp) * 2 >= n) {
        ans = max(ans, d[i]);
        break;
      }
    }
  }
  printf("%I64d\n", ans);
}
