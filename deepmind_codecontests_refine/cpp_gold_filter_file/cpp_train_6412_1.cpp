#include <bits/stdc++.h>
using namespace std;
int n, k, mx;
long long a[500005], b[500005], ans, c[500005], val;
priority_queue<long long, vector<long long>, greater<long long> > qa;
priority_queue<long long, vector<long long>, less<long long> > qb;
int func(long long x) {
  mx = 0;
  val = 0;
  long long d, e, f;
  for (int i = 1; i <= n; i++) {
    c[i] = b[i] - x;
  }
  while (!qa.empty()) qa.pop();
  while (!qb.empty()) qb.pop();
  for (int i = 1; i <= n; i++) {
    d = 0;
    qa.push(a[i]);
    e = qa.top();
    f = qb.empty() ? -1e18 : qb.top();
    d = min(d, c[i] - f);
    d = min(d, c[i] + e);
    val += d;
    if (d == c[i] + e) {
      mx++;
      qa.pop();
      qb.push(c[i]);
    } else if (d == c[i] - f) {
      qb.pop();
      qb.push(c[i]);
    }
  }
  return mx;
}
int main() {
  long long st, en, mid;
  int i, u;
  scanf("%d %d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (i = 1; i <= n; i++) scanf("%I64d", b + i);
  u = 50;
  st = 0;
  en = 2e9 + 1;
  while (u--) {
    mid = (st + en) / 2;
    if (func(mid) >= k) {
      ans = val;
      en = mid;
    } else
      st = mid;
  }
  printf("%I64d", ans + 1ll * k * en);
}
