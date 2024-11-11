#include <bits/stdc++.h>
using namespace std;
long long n, x;
priority_queue<long long> q;
long long ans;
int main() {
  scanf("%lld", &n);
  for (int i = (1); i <= (n); ++i) {
    scanf("%lld", &x);
    q.push(-x);
    q.push(-x);
    ans += q.top() + x;
    q.pop();
  }
  printf("%lld", ans);
  return 0;
}
