#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1.0);
const int maxn = 200010;
const long long mo = 9901;
long long n, m, k;
long long ans, tmp, cnt, ansd, ans1;
long long c[maxn], a[maxn];
long long jud2(long long d, long long m, long long &ans1, long long &ansd) {
  long long up = a[0] + m, down = a[0] - m;
  for (int i = 1; i < n; i++) {
    long long xia = a[i] - m - i * d;
    long long shang = a[i] + m - i * d;
    if (xia > up)
      return 1;
    else if (shang < down)
      return 2;
    up = min(up, shang);
    down = max(down, xia);
  }
  ans1 = down;
  ansd = d;
  return 0;
}
long long jud1(long long m, long long &ans1, long long &ansd) {
  long long l = 0, r = a[1] + m - (a[0] - m);
  long long ans = r;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long k = jud2(mid, m, ans1, ansd);
    if (k == 1)
      l = mid + 1;
    else if (k == 2)
      r = mid;
    else
      return 1;
  }
  return !jud2(r, m, ans1, ansd);
}
int main() {
  int T, cas = 1;
  while (scanf("%lld", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    long long l = 0, r = a[n - 1] - a[0] + 1;
    while (l < r) {
      long long mid = (l + r) >> 1;
      if (jud1(mid, ans1, ansd)) {
        r = mid;
      } else
        l = mid + 1;
    }
    printf("%lld\n%lld %lld\n", r, ans1, ansd);
  }
  return 0;
}
