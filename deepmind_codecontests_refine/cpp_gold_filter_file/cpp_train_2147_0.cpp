#include <bits/stdc++.h>
using namespace std;
int k[5], t[5], n;
long long ans, now, start, x;
priority_queue<long long> pq[5];
long long Max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int main() {
  cin >> k[1] >> k[2] >> k[3];
  cin >> t[1] >> t[2] >> t[3];
  cin >> n;
  for (int i = 1; i <= 3; ++i)
    for (int j = 1; j <= n && j <= k[i]; ++j) pq[i].push(-1);
  while (n--) {
    cin >> now;
    start = now;
    for (int i = 1; i <= 3; ++i) {
      x = pq[i].top();
      pq[i].pop();
      now = Max(-x, now) + t[i];
      pq[i].push(-now);
    }
    ans = Max(ans, now - start);
  }
  cout << ans;
  return 0;
}
