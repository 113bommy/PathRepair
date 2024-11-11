#include <bits/stdc++.h>
using namespace std;
const int nMax = 100010;
long long a[nMax], sum[nMax];
map<long long, long long> mp;
int main() {
  long long base, luck, pre, ans, mis, t;
  int n, i, j, k;
  while (scanf("%I64d%I64d%d", &base, &luck, &n) != EOF) {
    sum[0] = 0;
    ans = 0;
    for (i = 1; i <= n; i++) {
      scanf("%I64d", a + i);
      if ((!sum[i - 1]) && (!a[i]))
        sum[i] = 0;
      else {
        sum[i] = (sum[i - 1] + a[i]) % (base - 1);
        if (!sum[i]) sum[i] = base - 1;
      }
    }
    pre = 1;
    if (!luck) {
      for (i = 1; i <= n; i++)
        if (!a[i]) {
          ans += pre;
          pre++;
        } else
          pre = 1;
      goto output;
    }
    mp.clear();
    t = 0;
    mp[0]++;
    for (i = 1; i <= n; i++) {
      if (a[i] == 0) {
        ans += t;
        mp[sum[i]] = mp[sum[i]] + 1;
        continue;
      }
      mis = sum[i] - luck;
      if (mis < 0) mis += base - 1;
      if (mis == 0)
        t = mp[base - 1] + mp[0];
      else
        t = mp[mis];
      ans += t;
      mp[sum[i]] = mp[sum[i]] + 1;
    }
  output:
    printf("%I64d\n", ans);
  }
  return 0;
}
