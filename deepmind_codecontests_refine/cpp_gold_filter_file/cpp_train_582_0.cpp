#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 100;
long long a[N];
int main() {
  priority_queue<long long, vector<long long>, greater<long long> > q;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!q.empty() && q.top() < a[i]) {
      ans += a[i] - q.top();
      q.pop();
      q.push(a[i]);
      q.push(a[i]);
    } else {
      q.push(a[i]);
    }
  }
  printf("%lld\n", ans);
}
