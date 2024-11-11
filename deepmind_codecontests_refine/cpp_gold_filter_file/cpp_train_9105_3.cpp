#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 100000;
const long long MOD = 1e9 + 9;
long long n, a, b;
long long ans;
map<pair<long long, long long>, pair<long long, long long> > appr;
pair<long long, long long> arr[MAXN];
set<long long> now;
bool tf[MAXN];
void check(long long id, pair<long long, long long> pos) {
  tf[id] = 1;
  tf[id] &=
      !appr.count(pair<long long, long long>(pos.first - 1, pos.second + 1)) ||
      (appr[pair<long long, long long>(pos.first - 1, pos.second + 1)].second >
       1);
  tf[id] &=
      !appr.count(pair<long long, long long>(pos.first, pos.second + 1)) ||
      (appr[pair<long long, long long>(pos.first, pos.second + 1)].second > 1);
  tf[id] &=
      !appr.count(pair<long long, long long>(pos.first + 1, pos.second + 1)) ||
      (appr[pair<long long, long long>(pos.first + 1, pos.second + 1)].second >
       1);
  if (tf[id]) now.insert(id);
}
void cnt(pair<long long, long long> pos) {
  if (!appr.count(pos)) return;
  appr[pos].second = 0;
  if (appr.count(pair<long long, long long>(pos.first - 1, pos.second - 1)))
    appr[pos].second++;
  if (appr.count(pair<long long, long long>(pos.first, pos.second - 1)))
    appr[pos].second++;
  if (appr.count(pair<long long, long long>(pos.first + 1, pos.second - 1)))
    appr[pos].second++;
}
void del(long long id) {
  pair<long long, long long> pos = arr[id];
  appr.erase(pos);
  cnt(pair<long long, long long>(pos.first - 1, pos.second + 1));
  cnt(pair<long long, long long>(pos.first, pos.second + 1));
  cnt(pair<long long, long long>(pos.first + 1, pos.second + 1));
  pair<long long, long long> tmp[7] = {{-2, 0},  {-1, 0}, {1, 0}, {2, 0},
                                       {-1, -1}, {0, -1}, {1, -1}};
  for (long long i = 0; i < 7; i++) {
    if (appr.count(pair<long long, long long>(pos.first + tmp[i].first,
                                              pos.second + tmp[i].second)))
      check(appr[pair<long long, long long>(pos.first + tmp[i].first,
                                            pos.second + tmp[i].second)]
                .first,
            pair<long long, long long>(pos.first + tmp[i].first,
                                       pos.second + tmp[i].second));
  }
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> arr[i].first >> arr[i].second;
    appr[arr[i]] = pair<long long, long long>(i, 0);
  }
  for (auto i : appr) cnt(i.first);
  for (auto i : appr) check(i.second.first, i.first);
  for (long long i = 0; i < n; i++) {
    if (i % 2 == 0) {
      auto it = prev(now.end());
      while (!tf[*it]) it = prev(it), now.erase(next(it));
      ans = (ans * n + *it) % MOD;
      del(*it);
      now.erase(it);
    } else {
      auto it = now.begin();
      while (!tf[*it]) it = next(it), now.erase(*prev(it));
      ans = (ans * n + *it) % MOD;
      del(*it);
      now.erase(it);
    }
  }
  cout << ans << "\n";
}
