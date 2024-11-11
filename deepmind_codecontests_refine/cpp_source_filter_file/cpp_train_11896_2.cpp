#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, d, m;
  scanf("%lld%lld%lld", &n, &d, &m);
  vector<long long> a, b;
  for (long long i = 0; i < n; ++i) {
    long long x;
    scanf("%lld", &x);
    if (x <= m)
      a.push_back(x);
    else
      b.push_back(x);
  }
  vector<long long> sa(a.size() + 1), sb(b.size() + 1);
  sort(a.begin(), a.end(), greater<long long>());
  sort(b.begin(), b.end(), greater<long long>());
  for (long long i = 0; i < (long long)a.size(); ++i) {
    sa[i + 1] = sa[i] + a[i];
  }
  for (long long i = 0; i < (long long)b.size(); ++i) {
    sb[i + 1] = sb[i] + b[i];
  }
  long long ans = 0;
  for (long long i = 1; i <= (long long)a.size(); ++i) {
    long long sum = 0;
    long long tt = (n - i - 1) / (d + 1) + 1;
    if (tt > (long long)b.size()) continue;
    sum += sa[i];
    sum += sb[tt];
    ans = max(ans, sum);
  }
  printf("%lld\n", ans);
  return 0;
}
