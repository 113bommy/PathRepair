#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 5;
long long a[maxn];
long long b[maxn];
long long n, k;
long long sum;
inline long long f(long long x, long long y) {
  return x - 3 * y * y + 3 * y - 1;
}
inline long long calc(long long x, long long lim) {
  long long l = 1, r = a[x] + 1;
  while (l < r) {
    long long mid = l + (r - l) / 2;
    if (f(a[x], mid) >= lim) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  return l - 1;
}
inline void check(long long x) {
  sum = 0;
  for (int i = 1; i <= n; i++) {
    b[i] = calc(i, x);
    sum = sum + b[i];
  }
}
int main() {
  cin >> n >> k;
  long long l, r;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    l = min(l, f(a[i], a[i]));
    r = max(r, f(a[i], 0));
  }
  r++;
  while (l < r) {
    long long mid = l + (r - l) / 2;
    check(mid);
    if (sum >= k) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  l--;
  check(l);
  sum -= k;
  for (int i = 1; i <= n; i++) {
    if (sum > 0 && f(a[i], b[i]) == l && b[i] > 0) {
      b[i]--;
      sum--;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%lld ", b[i]);
  }
  return 0;
}
