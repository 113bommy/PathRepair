#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int n, k;
long long a[maxn], b[maxn], c[maxn];
bool check(long long x) {
  priority_queue<pair<long long, int> > q;
  for (int i = 0; i < n; ++i) {
    c[i] = a[i];
    q.push({-(c[i] / b[i] + 1), i});
  }
  int s = 0;
  while (!q.empty()) {
    pair<long long, int> tmp = q.top();
    tmp.first = -tmp.first;
    if (tmp.first >= k) break;
    q.pop();
    if (s >= tmp.first) {
      return 0;
    }
    if (!x) {
      return 0;
    }
    long long t = (tmp.first * b[tmp.second] - c[tmp.second] + x - 1) / x;
    if (s + t >= k) {
      return 0;
    }
    s += t;
    c[tmp.second] += t * x;
    tmp.first = -(c[tmp.second] / b[tmp.second] + 1);
    q.push(tmp);
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
  }
  int ma = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &b[i]);
    ma = max(ma, (int)b[i]);
  }
  long long ans = 1e13;
  long long l = 0, r = 1e12;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      r = mid - 1;
      ans = mid;
    } else
      l = mid + 1;
  }
  if (ans == 1e13) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
