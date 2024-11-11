#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
int n;
int ans;
signed main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    q.push(x);
    if (q.size() && q.top() < x) {
      ans += x - q.top();
      q.pop();
      q.push(x);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
