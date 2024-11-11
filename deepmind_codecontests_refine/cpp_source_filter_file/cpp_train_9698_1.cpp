#include <bits/stdc++.h>
using namespace std;
const int SZ = 100005;
long long boy[SZ];
long long girl[SZ];
map<int, int> rem;
priority_queue<long long> pq;
int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  long long mx = 0LL;
  long long ans = 0LL;
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    pq.push(x);
    mx = max(mx, x);
    rem[i] += (m - 1);
    ans += (long long)m * x;
  }
  for (int i = 0; i < m; i++) {
    long long x;
    scanf("%lld", &x);
    girl[i] = x;
    if (mx > x) {
      printf("-1");
      return 0;
    }
  }
  int t = pq.top();
  for (int i = 0; i < m; i++) {
    if (mx == girl[i]) continue;
    if (rem[t] > 0) {
      rem[t]--;
    } else {
      if (pq.size() > 1) {
        pq.pop();
        t = pq.top();
        rem[t]--;
      } else {
        printf("-1");
        return 0;
      }
    }
    ans += (girl[i] - t);
  }
  printf("%lld", ans);
  return 0;
}
