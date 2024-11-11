#include <bits/stdc++.h>
using namespace std;
pair<pair<long long, long long>, pair<long long, long long> > v[200005];
long long pref[10], n, s, ans;
long long f(long long a, long long b) {
  long long rsp = 0LL, fa, fb, pd, auxa, auxb;
  for (int i = n - 1; i >= 0; i--) {
    pd = v[i].first.second, fa = v[i].second.first, fb = v[i].second.second;
    if (fa >= fb)
      auxa = min(a, pd), auxb = max(pd - a, 0LL);
    else
      auxa = max(pd - b, 0LL), auxb = min(b, pd);
    a -= auxa, b -= auxb;
    rsp += (auxa * fa), rsp += (auxb * fb);
  }
  return rsp;
}
int main() {
  long long tot = 0, p, p1, i;
  scanf("%lld%lld", &n, &s);
  for (i = 0; i < n; i++) {
    scanf("%lld%lld%lld", &v[i].first.second, &v[i].second.first,
          &v[i].second.second),
        v[i].first.first = abs(v[i].second.first - v[i].second.second);
    tot += v[i].first.second;
    if (v[i].second.first >= v[i].second.second)
      pref[1] += v[i].first.second;
    else
      pref[2] += v[i].first.second;
  }
  sort(v, v + n);
  ans = 0LL;
  p = tot / s + (tot % s != 0);
  p1 = pref[1] / s + (pref[1] % s != 0);
  for (i = p1 - 1; i <= p1 + 1; i++)
    if (i >= 0 && p - i >= 0) ans = max(ans, f(i * s, (p - i) * s));
  printf("%lld\n", ans);
}
