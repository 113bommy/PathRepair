#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
long long n, s, sum, a[maxn], to[maxn];
bool check(long long x) {
  for (int i = 1; i <= n; i++) {
    to[i] = a[i] + i * x;
  }
  sort(to + 1, to + n + 1);
  long long cnt = 0;
  for (int i = 1; i <= x; i++) {
    cnt += to[i];
  }
  if (cnt > s) return false;
  sum = cnt;
  return true;
}
int main() {
  scanf("%lld %lld", &n, &s);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", a + i);
  }
  long long l = 0, r = n, ans = -1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid)) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid - 1;
  }
  printf("%lld %lld\n", ans, sum);
  return 0;
}
