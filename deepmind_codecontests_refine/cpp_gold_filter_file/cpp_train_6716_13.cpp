#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<int> a, b;
vector<pair<int, int> > cost;
struct Item {
  long long cost;
  int id, day;
  bool operator<(const Item &t) const { return cost < t.cost; }
};
int n, m, k, s;
bool solve(int days, bool print = false) {
  int a_best = MOD, b_best = MOD, a_day, b_day;
  for (int i = 0; i < days; ++i) {
    if (a_best > a[i]) {
      a_best = a[i];
      a_day = i + 1;
    }
    if (b_best > b[i]) {
      b_best = b[i];
      b_day = i + 1;
    }
  }
  vector<Item> items;
  for (int i = 0; i < m; ++i)
    items.push_back(
        {(long long)cost[i].first * a_best + (long long)cost[i].second * b_best,
         i + 1, cost[i].first == 0 ? b_day : a_day});
  sort(items.begin(), items.end());
  long long total = 0;
  for (int i = 0; i < k; ++i) total += items[i].cost;
  if (print) {
    for (int i = 0; i < k; ++i) printf("%d %d\n", items[i].id, items[i].day);
  }
  return total <= s;
}
int main() {
  cin >> n >> m >> k >> s;
  a.resize(n);
  b.resize(n);
  cost.resize(m);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &cost[i].first, &cost[i].second);
    if (cost[i].first == 1) {
      swap(cost[i].second, cost[i].first);
      cost[i].second = 0;
    } else
      cost[i].first = 0;
  }
  cost.push_back({0, 0});
  int lo = 1, hi = n + 1, mid;
  while (lo < hi) {
    mid = (lo + hi) / 2;
    if (solve(mid))
      hi = mid;
    else
      lo = mid + 1;
  }
  if (lo > n) {
    puts("-1");
    return 0;
  }
  cout << lo << '\n';
  solve(lo, 1);
}
