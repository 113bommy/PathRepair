#include <bits/stdc++.h>
using namespace std;
long long cal(int first, int k) {
  long long a = first / k, b = first / k + 1;
  long long val = k - first % k, val2 = first % k;
  return a * a * val + b * b * val2;
}
void solve() {
  int n, k;
  scanf("%d %d", &n, &k);
  long long a[100005];
  int now[1000005];
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  sort(a, a + n);
  long long ans = 0;
  priority_queue<pair<long long, long long> > pq;
  for (int i = 0; i < n; i++) {
    ans += a[i] * a[i];
    now[i] = 1;
    pq.push(make_pair(cal(a[i], 1) - cal(a[i], 2), i));
  }
  now[n] = 1e9;
  k -= n;
  for (int i = 0; i < k; i++) {
    ans -= pq.top().first;
    int first = pq.top().second;
    pq.pop();
    now[first]++;
    pq.push(make_pair(cal(a[first], now[first]) - cal(a[first], now[first] + 1),
                      first));
  }
  printf("%lld\n", ans);
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
