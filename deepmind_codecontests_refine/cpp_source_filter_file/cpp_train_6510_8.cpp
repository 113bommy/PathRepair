#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  scanf("%lld", &n);
  long long a[n + 1];
  map<long long, long long> mp;
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]), mp[a[i]]++;
  scanf("%lld", &m);
  long long audio[m + 1], sub[m + 1];
  for (long long i = 1; i <= m; i++) scanf("%lld", &audio[i]);
  for (long long i = 1; i <= m; i++) scanf("%lld", &sub[i]);
  long long max_pl = 0, max_al = 0, ans = 0;
  for (long long i = 1; i <= m; i++) {
    long long c, d;
    c = mp[audio[i]];
    d = mp[sub[i]];
    if (c > max_pl) {
      max_pl = c;
      ans = i;
      max_al = d;
    } else if (c == max_pl && d > max_al) {
      max_al = d;
      ans = i;
    }
  }
  printf("%lld\n", ans);
}
