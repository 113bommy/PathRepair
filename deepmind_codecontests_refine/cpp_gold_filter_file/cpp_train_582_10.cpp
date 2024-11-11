#include <bits/stdc++.h>
using namespace std;
const long long N = 300010;
long long n, ans;
long long a[N];
priority_queue<long long, vector<long long>, greater<long long> > q;
signed main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i <= n; i++) {
    if (q.size() && a[i] - q.top() > 0) {
      ans += a[i] - q.top();
      q.pop();
      q.push(a[i]);
    }
    q.push(a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
