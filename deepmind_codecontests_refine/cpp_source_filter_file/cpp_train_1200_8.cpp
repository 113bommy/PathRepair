#include <bits/stdc++.h>
using namespace std;
const int N = 700005;
int m, p[N], s[N], l[N];
bool used[N];
long long n, ans, a[N], f[N];
int main() {
  scanf("%lld", &n), m = sqrt(n);
  for (int i = 2; i <= m; i++) {
    s[i] = s[i - 1];
    if (!used[i]) p[++p[0]] = i, s[i]++;
    for (int j = 1, x = i << 1; j <= p[0] && x <= m; j++, x = i * p[j]) {
      used[x] = 1;
      if (!(i % p[j])) break;
    }
  }
  for (long long i = n; i; i = n / (n / i + 1))
    a[0]++, f[a[0]] = a[a[0]] = n / i;
  for (int i = 1; i <= p[0]; i++)
    for (int j = a[0]; j; j--) {
      long long k = a[j] / p[i];
      if (k < p[i]) break;
      k = k < m ? k : a[0] - n / k + 1, f[j] -= f[k] - i + l[k] + 1, l[j] = i;
    }
  for (int i = 1; i <= p[0]; i++) {
    int x = a[0] - p[i] + 1;
    ans += f[x] - p[0] + l[x];
  }
  printf("%lld", ans + s[(int)cbrt(n)]);
  return 0;
}
