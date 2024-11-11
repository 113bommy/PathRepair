#include <bits/stdc++.h>
using namespace std;
long long n;
long long v[112345];
long long low, a;
bool check(long long k) {
  for (long long j = 0; j < n; j++) {
    long long l = INT_MIN;
    long long r = INT_MAX;
    long long b = v[j] + k;
    for (long long i = 0; i < n; i++) {
      if (i == j) continue;
      if (i > j) {
        long long inf = ((v[i] - k - b) + ((i - j) - 1)) / (i - j);
        long long sup = (v[i] + k - b) / (i - j);
        l = max(l, inf);
        r = min(r, sup);
      } else {
        long long inf = ((v[i] - k - b)) / (i - j);
        long long sup = ((v[i] + k - b) + ((i - j) + 1)) / (i - j);
        swap(inf, sup);
        l = max(l, inf);
        r = min(r, sup);
      }
    }
    if (l <= r) {
      a = l;
      low = (-j) * a + (v[j] + k);
      return true;
    }
    l = INT_MIN;
    r = INT_MAX;
    b = v[j] - k;
    for (long long i = 0; i < n; i++) {
      if (i == j) continue;
      if (i > j) {
        long long inf = ((v[i] - k - b) + ((i - j) - 1)) / (i - j);
        long long sup = (v[i] + k - b) / (i - j);
        l = max(l, inf);
        r = min(r, sup);
      } else {
        long long inf = ((v[i] - k - b)) / (i - j);
        long long sup = ((v[i] + k - b) + ((i - j) + 1)) / (i - j);
        swap(inf, sup);
        l = max(l, inf);
        r = min(r, sup);
      }
    }
    if (l <= r) {
      a = l;
      low = (-j) * a + (v[j] - k);
      return true;
    }
  }
  return false;
}
int32_t main() {
  scanf("%lld", &n);
  for (long long i = 0; i < n; i++) {
    scanf("%lld", &v[i]);
  }
  sort(v, v + n);
  long long l = 0, r = 10000;
  long long ans = -1;
  while (l <= r) {
    long long m = (l + r) / 2;
    if (check(m)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }
  printf("%lld\n%lld %lld\n", ans, low, a);
}
