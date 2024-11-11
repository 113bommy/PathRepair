#include <bits/stdc++.h>
using namespace std;
int n, k;
long long b[100005], a[100005], h[100005], p, m;
bool Check(long long x) {
  priority_queue<pair<long long, int>, vector<pair<long long, int> >,
                 greater<pair<long long, int> > >
      q;
  for (int i = 1; i <= n; i++) {
    b[i] = x;
    long long o = x / a[i] + 1;
    if (o <= m) q.push(pair<long long, int>(o, i));
  }
  long long cnt = m * k;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= k; j++) {
      if (q.empty()) break;
      pair<long long, int> c = q.top();
      q.pop();
      int y = c.second;
      long long o;
      if (c.first < i) return 0;
      b[y] += p, o = b[y] / a[y] + 1;
      if (o <= m) q.push(pair<long long, int>(o, y));
      cnt--;
    }
  }
  if (!q.empty()) return 0;
  for (int i = 1; i <= n; i++) {
    long long k1 = b[i] - a[i] * m;
    if (k1 >= h[i]) continue;
    long long o = (h[i] - k1 - 1) / p + 1;
    cnt -= o;
  }
  if (cnt < 0) return 0;
  return 1;
}
int main() {
  scanf("%d%I64d%d%I64d", &n, &m, &k, &p);
  long long l = 0, r = (m + 1) * 1000000000;
  for (int i = 1; i <= n; i++)
    scanf("%I64d%I64d", &h[i], &a[i]), l = max(l, a[i]);
  while (l < r) {
    long long mid = (l + r) / 2;
    if (Check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%I64d\n", l);
  return 0;
}
