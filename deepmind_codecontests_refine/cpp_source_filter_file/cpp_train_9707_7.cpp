#include <bits/stdc++.h>
using namespace std;
long long n, k, first, last, res, ans, mid, a[100001], maxn[100001];
long long read() {
  char c = 0;
  long long sum = 0;
  while (c < '0' || c > '9') c = getchar();
  while ('0' <= c && c <= '9') sum = sum * 10 + c - '0', c = getchar();
  return sum;
}
bool check(long long x) {
  res = 0;
  long long l, r, m;
  for (int i = 1; i <= n; ++i) {
    l = 0, r = a[i], maxn[i] = 0;
    while (l <= r) {
      m = (l + r) / 2;
      if (a[i] - 3 * m * m + 3 * m - 1 >= x)
        l = m + 1, maxn[i] = max(maxn[i], m);
      else
        r = m - 1;
    }
    res += maxn[i];
  }
  return (res >= k);
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  first = ans = -1e18, last = 1e18;
  while (first <= last) {
    mid = (first + last) / 2;
    if (check(mid))
      first = mid + 1, ans = max(ans, mid);
    else
      last = mid - 1;
  }
  check(ans);
  int cnt = res - k;
  for (int i = 1; i <= n; ++i)
    while (cnt && a[i] - 3 * maxn[i] * maxn[i] + 3 * maxn[i] - 1 == ans)
      maxn[i]--, cnt--;
  for (int i = 1; i <= n; ++i) printf("%lld ", maxn[i]);
  puts("");
  return 0;
}
