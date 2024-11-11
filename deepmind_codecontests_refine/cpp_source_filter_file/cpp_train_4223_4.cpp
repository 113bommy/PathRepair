#include <bits/stdc++.h>
using namespace std;
int dp[123000];
int n, m;
long long d, k, a, b, t;
void input() {}
void solve() {
  long long ans = 0;
  if (d <= k) {
    ans = (long long)a * (long long)d;
    printf("%d\n", ans);
    return;
  }
  d -= k;
  ans += (long long)a * (long long)k;
  long long i = (long long)(a - b) * (long long)k + (long long)t;
  if (i >= 0) {
    ans += (long long)b * (long long)d;
  } else {
    long long x = d / k;
    long long s = (long long)d - x * (long long)k;
    long long j1 = x * i + (long long)b * (long long)d;
    long long j2 = ((long long)a * (long long)k + (long long)t) * x +
                   (long long)t + (long long)a * s;
    ans += j1 < j2 ? j1 : j2;
  }
  printf("%lld\n", ans);
}
int main() {
  while (scanf("%lld %lld %lld %lld %lld", &d, &k, &a, &b, &t) != EOF) {
    solve();
  }
  return 0;
}
