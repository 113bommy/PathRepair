#include <bits/stdc++.h>
using namespace std;
long long h[200009];
long long bfs(long long root, long long k) {
  long long count = h[root], steps = 0, rem = k - count;
  queue<pair<long long, long long>> q;
  q.push({root, 0});
  while (count < k && !q.empty()) {
    pair<long long, long long> u = q.front();
    long long v = u.first;
    q.pop();
    if (2 * v <= 200008 && h[2 * v] >= rem) {
      steps += (rem * (u.second + 1));
      count += rem;
      rem = 0;
    } else if (2 * v <= 200008) {
      steps += (h[2 * v] * (u.second + 1));
      count += h[2 * v];
      rem = k - count;
      if (2 * v + 1 <= 200008 && h[2 * v + 1] >= rem) {
        steps += (rem * (u.second + 1));
        count += rem;
        rem = 0;
      } else if (2 * v + 1 <= 200008) {
        steps += (h[2 * v + 1] * (u.second + 1));
        count += h[2 * v + 1];
        rem = k - count;
      }
    }
    if (2 * v <= 200008) q.push({2 * v, u.second + 1});
    if (2 * v + 1 <= 200008) q.push({2 * v + 1, u.second + 1});
  }
  if (rem <= 0)
    return steps;
  else
    return -1;
}
long long solve(long long k, long long m) {
  long long ans = INT_MAX;
  for (long long i = 1; i <= m; i++) {
    long long x = bfs(i, k);
    if (x != -1) ans = min(ans, x);
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    h[a[i]]++;
  }
  sort(a, a + n);
  cout << solve(k, a[n - 1]) << "\n";
  return 0;
}
