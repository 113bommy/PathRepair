#include <bits/stdc++.h>
#pragma GCC Optimize("O3")
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  priority_queue<int> pq;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int t;
    cin >> t;
    t -= i;
    pq.push(t);
    if (pq.top() > t) {
      ans += pq.top() - t;
      pq.pop();
      pq.push(t);
    }
  }
  cout << ans;
  return 0;
}
