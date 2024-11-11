#include <bits/stdc++.h>
using namespace std;
int n, i;
long long m;
long long c[100011], w[100011];
priority_queue<pair<long long, int>, vector<pair<long long, int> >,
               greater<pair<long long, int> > >
    H;
int ans[100011][2];
long long sol;
int main() {
  scanf("%d%lld", &n, &m);
  for (i = 1; i <= n; i++) scanf("%lld", &c[i]);
  for (i = 1; i <= n; i++) scanf("%lld", &w[i]);
  for (i = 1; i <= n; i++) {
    ans[i][0] = c[i] / 100;
    ans[i][1] = c[i] %= 100;
    m -= c[i];
    if (c[i] == 0) continue;
    H.push(make_pair(w[i] * (100 - c[i]), i));
    while (m < 0) {
      m += 100;
      ans[H.top().second][0]++;
      ans[H.top().second][1] = 0;
      sol += H.top().first;
      H.pop();
    }
  }
  printf("%lld\n", sol);
  for (i = 1; i <= n; i++) printf("%lld %lld\n", ans[i][0], ans[i][1]);
  return 0;
}
