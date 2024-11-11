#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 7;
const long long M = 5000;
const long long mod = 1e9 + 7;
long long n, m;
pair<long long, long long> cost[N];
long long cnt[N];
bool visited[N];
int main() {
  scanf("%lld%lld", &n, &m);
  long long p, c;
  for (long long i = 1; i <= n; i++) {
    scanf("%lld%lld", &p, &c);
    if (p == 1) {
      cost[i].first = 0;
      cost[i].second = p;
    } else {
      cost[i].first = c;
      cost[i].second = p;
    }
    cnt[cost[i].second] += 1;
  }
  sort(cost + 1, cost + n + 1);
  long long ans = 1e16;
  long long now;
  long long cnttk = 0;
  long long cntnow[N];
  long long cnttkme = 0;
  for (long long i = 1; i <= m; i++) {
    now = 0;
    cnttk = 0;
    cnttkme = 0;
    for (long long j = 1; j <= m; j++) {
      cntnow[j] = cnt[j];
    }
    for (long long j = 1; j <= n; j++) {
      visited[j] = false;
    }
    for (long long j = 1; j <= n; j++) {
      if (cntnow[cost[j].second] >= i) {
        visited[j] = true;
        cntnow[cost[j].second] -= 1;
        now += cost[j].first;
        cnttkme += 1;
      }
    }
    for (long long j = 1; j <= n; j++) {
      if (cnttkme >= i) {
        break;
      }
      if (visited[j] == false) {
        cnttkme += 1;
        now += cost[j].first;
      }
    }
    if (cnttkme == i) {
      ans = min(ans, now);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
