#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return b ? gcd(b, a % b) : a;
}
long long int lcm(long long int a, long long int b) {
  return a * b / gcd(a, b);
}
const int N = 1e5 + 10;
int a[N], f[N], ans[N], cnt[N], l[N], r[N], n, m;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] <= n) cnt[a[i]]++;
  }
  for (int i = 1; i <= m; i++) scanf("%d%d", l + i, r + i);
  for (int i = 1; i <= n; i++) {
    if (cnt[i] >= i) {
      f[0] = 0;
      for (int j = 1; j <= n; j++) f[j] = a[j] != i ? f[j - 1] : f[j - 1] + 1;
      for (int j = 1; j <= n; j++)
        if (f[r[j]] - f[l[j] - 1] == i) ans[j]++;
    }
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
