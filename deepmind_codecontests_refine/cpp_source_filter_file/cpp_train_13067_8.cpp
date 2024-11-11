#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 15;
int ind[N], n, m, d, dp[N], Next[N];
pair<int, int> p[N];
void update(int x, int i) {
  while (x < N) {
    dp[x] = min(dp[x], i), x += x & (-x);
  }
}
int qq(int x) {
  int ret = m + 1;
  while (x) {
    ret = min(ret, dp[x]);
    x = x & (x - 1);
  }
  return ret;
}
int main() {
  int ind, fuel, cur = 0, i, j, x = 0, y, r = 0, next, v, rem, f = 0, u;
  cin >> d >> n >> m;
  fuel = n;
  long long ret = -1, cost = 0;
  for (i = 1; i <= m; ++i) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }
  sort(p + 1, p + 1 + m);
  p[m + 1].first = d, p[m + 1].second = 0;
  for (i = 0; i < N; ++i) dp[i] = m + 1;
  for (i = m; i >= 1; --i) {
    ind = qq(p[i].second), Next[i] = ind, update(p[i].second, i);
  }
  Next[0] = m + 1;
  y = 1;
  priority_queue<pair<int, pair<int, int> > > q;
  ind = 0;
  if (n >= d) {
    ret = 0;
  }
  while (1) {
    while (y <= m) {
      if (x + n >= p[y].first)
        q.push(make_pair(-p[y].second, make_pair(p[y].first, y))), ++y;
      else
        break;
    }
    if (x == d) break;
    u = Next[ind];
    if (x + n >= d) {
      rem = max(d - x - fuel, 0);
      if (ret == -1 || ret > cost + 1LL * f * rem) ret = cost + 1LL * f * rem;
    }
    if (p[u].first <= x + n) {
      assert(p[u].first > x);
      rem = p[u].first - x;
      rem = max(0, rem - fuel);
      fuel += rem;
      fuel -= (p[u].first - x);
      cost += rem * f;
      x = p[u].first, f = p[u].second, ind = u;
    } else {
      while (!q.empty()) {
        if (x >= q.top().second.first) {
          q.pop();
          continue;
        } else
          break;
      }
      if (q.empty()) break;
      u = q.top().second.second;
      rem = p[u].first - x;
      cost = cost + 1LL * (n - fuel) * f;
      fuel = n - rem;
      ind = u, x = p[u].first, f = p[u].second;
    }
  }
  cout << ret << endl;
}
