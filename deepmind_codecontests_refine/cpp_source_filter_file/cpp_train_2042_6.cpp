#include <bits/stdc++.h>
using namespace std;
int n;
long long x, y;
long long ans;
long long num[1000005 * 2];
long long sum[1000005 * 2];
long long sta = 1000000 * 2;
long long primes[1000005 * 2];
int isp[1000005 * 2];
int cnt;
void init() {
  cnt = 0;
  for (int i = 2; i <= sta / 2; i++) {
    if (isp[i] == 0) primes[cnt] = i, cnt++;
    for (int j = 0; j < cnt && primes[j] * i <= sta / 2; j++) {
      isp[primes[j] * i] = i;
      if (i % primes[j] == 0) break;
    }
  }
}
int main() {
  init();
  long long maxn = 0;
  while (~scanf("%d%lld%lld", &n, &x, &y)) {
    for (int i = 0; i <= 1000003 * 2; i++) sum[i] = num[i] = 0;
    ans = 1e18;
    int f = 0;
    for (int i = 0; i < n; i++) {
      long long tp;
      scanf("%lld", &tp);
      maxn = max(tp, maxn);
      if (i == 0 && tp == 669707) f = 1;
      num[tp]++;
      sum[tp] += (-tp);
    }
    for (int i = 1000002 * 2; i >= 0; i--) {
      num[i] += num[i + 1];
      sum[i] += sum[i + 1];
    }
    int id = 0;
    for (int i = 0; i < cnt; i++) {
      long long tans = 0;
      for (int j = 0; primes[i] * j < sta / 2; j++) {
        int ad = x / y;
        long long bg = min(sta / 2 + 10, (j + 1) * primes[i] - 1);
        long long ed = j * primes[i] + 1;
        long long mid = max(ed, (j + 1) * primes[i] - ad);
        mid = min(mid, bg + 1);
        long long ans1 = (num[ed] - num[mid]) * x;
        long long ans2 =
            (sum[mid] - sum[bg + 1]) - (num[mid] - num[bg + 1]) * (-bg - 1);
        ans2 *= y;
        tans += (ans1 + ans2);
      }
      if (ans > tans) id = primes[i];
      ans = min(ans, tans);
    }
    printf("%lld\n", ans);
  }
}
