#include <bits/stdc++.h>
using namespace std;
const int maxN = 200010;
long long n, r;
int l[maxN], t[maxN];
long long ans[100010];
int main() {
  scanf("%lld %lld", &n, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &l[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &t[i]);
  for (int i = 1; i <= n; i++) {
    if (t[i] < l[i]) {
      puts("-1");
      return 0;
    }
  }
  long long now = 0;
  long long rem = 0;
  long long cnt = 0;
  for (int i = 1; i <= n; i++) {
    long long tmp = min((long long)l[i], rem);
    rem -= tmp;
    l[i] -= tmp;
    t[i] -= tmp;
    now += tmp;
    if (t[i] >= 2 * l[i]) {
      now += 2 * l[i];
      continue;
    }
    long long k = (l[i] * 2ll - t[i] + r - 1) / r;
    if (cnt + k <= 100000)
      for (long long j = now + t[i] * 2ll - l[i] * 2; j < now + t[i]; j += r)
        ans[cnt++] = j;
    else
      cnt += k;
    rem = k * r - 2ll * l[i] + t[i];
    now += t[i];
  }
  if (cnt <= 100000) {
    printf("%lld\n", cnt);
    for (int i = 0; i < cnt; i++) printf("%lld ", ans[i]);
  } else
    printf("%lld\n", cnt);
  puts("");
  return 0;
}
