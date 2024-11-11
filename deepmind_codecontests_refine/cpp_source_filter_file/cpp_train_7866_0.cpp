#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int m, n;
int a[maxn];
long long b[maxn];
long long sum[2];
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
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    sum[0] = (sum[0] + a[i]) % m;
    sum[1] = (sum[1] + (long long)a[i] * a[i]) % m;
  }
  sort(a + 1, a + 1 + n);
  if (n == 1) {
    printf("%d", a[1]);
    return 0;
  }
  for (int i = 2; i <= n; i++) {
    int d = (m + a[i] - a[1]) % m;
    int x = (sum[0] - (long long)n * (n - 1) / 2 % m * d % m + m) % m *
            fp(n, m - 2, m) % m;
    int ans = 1LL * n * x % m * x % m;
    ans = (ans + 1LL * n * (n - 1) % m * d % m * x % m) % m;
    ans = (ans + 1LL * n * (n - 1) * (2 * n - 1) / 6 % m * d % m * d % m) % m;
    if (ans == sum[1]) {
      b[1] = x;
      for (int j = 2; j <= n; j++) {
        b[j] = (b[j - 1] + d + m) % m;
      }
      sort(b + 1, b + n + 1);
      bool ok = 1;
      for (int j = 1; j <= n; j++) {
        if (a[j] != b[j]) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        printf("%d %d\n", x, d);
        return 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}
