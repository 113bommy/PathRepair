#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
long long n, k, ans, sum[N];
set<long long> a;
map<long long, long long> x;
signed main() {
  scanf("%d%lld", &n, &k);
  sum[0] = 0;
  for (long long i = 1; i <= n; i++)
    scanf("%lld", &sum[i]), sum[i] += sum[i - 1];
  a.insert(1);
  long long tmp = k;
  for (long long i = 1; i <= 60; i++) {
    if (tmp > 1e14) break;
    a.insert(tmp);
    tmp *= k;
  }
  long long ans = 0;
  x[0] = 1;
  for (long long i = 1; i <= n; i++) {
    for (set<long long>::iterator it = a.begin(); it != a.end(); it++)
      ans += x[sum[i] - *it];
    x[sum[i]]++;
  }
  printf("%lld\n", ans);
}
