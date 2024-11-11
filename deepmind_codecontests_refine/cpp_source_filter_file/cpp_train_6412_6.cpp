#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int n, m, cnt;
long long ans, sum, a[N], b[N];
priority_queue<pair<long long, bool> > q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &b[i]);
  long long l = -1e9, r = 1e9, mid;
  while (l <= r) {
    while (q.size()) q.pop();
    mid = (l + r) >> 1;
    sum = cnt = 0;
    for (int i = 1; i <= n; i++) {
      q.push(make_pair(mid - a[i], 0));
      if (b[i] - q.top().first < 0) {
        if (!q.top().second) cnt++;
        sum += b[i] - q.top().first;
        q.pop();
        q.push(make_pair(b[i], 1));
      }
    }
    if (cnt >= m)
      ans = sum + mid * m, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
  return 0;
}
