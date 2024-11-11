#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n), t(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }
  priority_queue<long long, vector<long long>, greater<long long>> q;
  ;
  long long prev_sum_t = 0;
  for (int i = 0; i < n; i++) {
    long long ans = 0;
    q.push(v[i] + prev_sum_t);
    while (!q.empty() && q.top() - prev_sum_t < t[i]) {
      ans += q.top() - prev_sum_t;
      q.pop();
    }
    ans += 1ll * q.size() * t[i];
    prev_sum_t += t[i];
    cout << ans << ' ';
  }
  return 0;
}
