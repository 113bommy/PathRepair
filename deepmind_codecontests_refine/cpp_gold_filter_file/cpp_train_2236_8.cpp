#include <bits/stdc++.h>
using namespace std;
long long n, k, s, m, Max;
priority_queue<long long> que;
int main() {
  scanf("%lld%lld", &n, &k);
  if (n <= k) {
    while (n--) {
      scanf("%lld%lld", &s, &m);
      printf("%lld\n", s + m);
    }
    return 0;
  }
  for (long long i = 0; i < k; i++) {
    scanf("%lld%lld", &s, &m);
    que.push(0 - s - m);
    Max = max(Max, s + m);
    printf("%lld\n", s + m);
  }
  for (long long i = k; i < n; i++) {
    scanf("%lld%lld", &s, &m);
    long long tp = 0 - que.top();
    que.pop();
    if (tp <= s) {
      printf("%lld\n", s + m);
      que.push(0 - s - m);
    } else {
      printf("%lld\n", tp + m);
      que.push(0 - tp - m);
    }
  }
  return 0;
}
