#include <bits/stdc++.h>
using namespace std;
long long a[600001], ans[600001];
priority_queue<pair<long long, long long> > q;
int main() {
  long long answer = 0, i, j, n, k;
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= k; i++) q.push({a[i], i});
  for (i = k + 1; i <= n + k + 1; i++) {
    q.push({a[i], i});
    answer += q.top().first * (i - q.top().second);
    ans[q.top().second] = i;
    q.pop();
  }
  cout << answer << endl;
  for (i = 1; i <= n; i++) cout << ans[i] << " ";
  return 0;
}
