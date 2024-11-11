#include <bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
long long area = 2000000000000000000ll;
void input() {
  scanf("%I64d", &n);
  for (long long i = 1; i <= 2 * n; i++) scanf("%I64d", a + i);
  sort(a + 1, a + 2 * n + 1);
  for (long long i = 2; i <= n; i++) {
    area = min(area, (a[i + n - 1] - a[i]) * (a[2 * n] - a[1]));
  }
  area = min(area, (a[n] - a[1]) * (a[2 * n] - a[n + 1]));
  printf("%I64d", area);
}
signed main() {
  input();
  return 0;
}
