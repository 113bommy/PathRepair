#include <bits/stdc++.h>
using namespace std;
long long n, a[1000100], ans, cnt;
priority_queue<long long> q;
int main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++) {
    q.push(-a[i]);
    q.push(-a[i]);
    ans += a[i] + q.top();
    q.pop();
  }
  printf("%lld", ans + 1);
  return 0;
}
