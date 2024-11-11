#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18, N = 2e5;
long long now, n, m, bou, dam, inc, ans, mx[N], st[N], reg[N];
vector<pair<long long, long long>> mon[N];
map<long long, int> a;
int main(int argc, char *argv[]) {
  scanf("%lld%lld%lld%lld%lld", &n, &m, &bou, &inc, &dam);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld%lld", mx + i, st + i, reg + i);
    mon[i].push_back(make_pair(0, st[i]));
  }
  for (int i = 1; i <= m; ++i) {
    long long tim, enemy, h;
    scanf("%lld%lld%lld", &tim, &enemy, &h);
    mon[enemy].push_back(make_pair(tim, h));
  }
  for (int i = 1; i <= n; ++i) {
    sort(mon[i].begin(), mon[i].end());
    for (size_t j = 0; j < mon[i].size(); ++j) {
      long long t = mon[i][j].first, x = mon[i][j].second;
      if (x > dam) continue;
      long long r =
          (reg[i] && mx[i] > dam) ? (t + (dam - x) / reg[i] + 1) : INF + 1;
      ;
      if (j + 1 < mon[i].size()) r = min(r, mon[i][j + 1].first);
      ;
      ++a[t], --a[r], a[r - 1];
    }
  }
  for (auto i = a.begin(); i != a.end(); ++i) {
    now += i->second;
    if (i->first == INF && inc && now) {
      printf("-1\n");
      return 0;
    }
    ans = max(ans, now * (i->first * inc + bou));
  }
  printf("%lld\n", ans);
  return 0;
}
