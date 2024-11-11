#include <bits/stdc++.h>
using namespace std;
long long num[1010], ans;
void ok(long long x, long long y, long long n, long long m) {
  for (long long i = 0; i < 10; i++) num[i] = 0;
  if (!n) num[0]++;
  if (!m) num[0]++;
  while (n) {
    num[x % 7]++;
    x /= 7;
    n /= 7;
  }
  while (m) {
    num[y % 7]++;
    y /= 7;
    m /= 7;
  }
  for (int i = 0; i < 10; i++)
    if (num[i] > 1) return;
  ans++;
}
int main() {
  long long n, m;
  scanf("%lld%lld", &n, &m);
  if (1ll * n * m > 1e7) {
    puts("0");
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) ok(i, j, n - 1, m - 1);
  }
  printf("%lld\n", ans);
  return 0;
}
