#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, k, now;
int idx;
long long l, r, mid, mmax = 0, num;
long long a[N], aa[N], b[N];
priority_queue<pair<long long, int> > q;
bool check(long long mid) {
  now = 0;
  for (int i = 1; i <= n; i++) aa[i] = a[i];
  while (q.size()) q.pop();
  for (int i = 1; i <= n; i++)
    if (a[i] / b[i] < k - 1) q.push(make_pair(-a[i] / b[i], i));
  while (q.size() && now <= k) {
    if (q.size() > k - now) return false;
    num = -q.top().first;
    idx = q.top().second;
    q.pop();
    if (num < (long long)now) return false;
    aa[idx] += mid;
    num = aa[idx] / b[idx];
    if (num < k - 1) q.push(make_pair(-num, idx));
    now++;
  }
  if (q.size()) return false;
  return true;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), mmax = max(mmax, b[i]);
  l = 0, r = mmax * k;
  while (l < r) {
    mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (check(l))
    printf("%lld\n", l);
  else
    printf("-1\n");
  return 0;
}
