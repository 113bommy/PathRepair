#include <bits/stdc++.h>
const long long inf = 9223372036854775807;
using namespace std;
long long n, m, mid, ans;
long long a[100005], b[100005];
bool check(long long w) {
  long long j = 1;
  for (long long i = 1; i <= m; i++) {
    while (a[j] >= b[i] - w && a[j] <= b[i] + w && j <= n) j++;
    if (j == n + 1) return true;
  }
  return false;
}
int main() {
  scanf("%I64d%I64d", &n, &m);
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
  }
  for (long long i = 1; i <= m; i++) {
    scanf("%I64d", &b[i]);
  }
  b[0] = -inf;
  b[n + 1] = inf;
  long long l = 0, r = 2e9;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
      ans = mid;
    }
  }
  printf("%I64d", l);
  return 0;
}
