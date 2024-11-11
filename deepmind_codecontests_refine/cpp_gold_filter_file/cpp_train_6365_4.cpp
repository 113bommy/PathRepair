#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  --k;
  auto kt = [&](long long x) {
    using T = pair<double, int>;
    priority_queue<T> pq;
    for (int i = 0; i < n; i++) {
      if (a[i] >= 1ll * b[i] * k) continue;
      pq.emplace(-1.0 * a[i] / b[i], i);
    }
    for (int i = 0; i <= k && (int)pq.size(); i++) {
      auto now = pq.top();
      pq.pop();
      if (-now.first < i) return false;
      now.first -= 1.0 * x / b[now.second];
      pq.push(now);
    }
    return true;
  };
  long long l = 0, r = 2e12;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (kt(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (l == 2e12 + 1) l = -1;
  cout << l << "\n";
}
