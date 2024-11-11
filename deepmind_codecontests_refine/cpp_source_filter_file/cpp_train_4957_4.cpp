#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, T;
  cin >> n >> T;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i], arr[i] -= (i + 1);
  int ans = 0;
  priority_queue<long long> pq;
  for (int i = 0; i < min(T - 1, n); i++) {
    pq.push(arr[i]);
    while (!pq.empty() && pq.top() < T - i - 1) pq.pop();
    ans = max(ans, (int)pq.size());
  }
  cout << ans;
}
