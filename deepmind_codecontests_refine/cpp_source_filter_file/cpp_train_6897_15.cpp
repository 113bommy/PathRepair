#include <bits/stdc++.h>
using namespace std;
struct topx {
  set<pair<int, int>> s1, s2;
  int x, sum;
  topx() : x(0), sum(0) {}
  bool fixup() {
    while (s1.size() < x) {
      if (s2.size() == 0) return false;
      auto it = s2.begin();
      s1.insert(*it);
      sum += it->first;
      s2.erase(it);
    }
    while (s1.size() > x) {
      auto it = s1.end();
      s2.insert(*(--it));
      sum -= it->first;
      s1.erase(it);
    }
    return true;
  }
  bool set_x(int nx) {
    assert(nx >= x);
    x = nx;
    return fixup();
  }
  void remove(int val, int pos) {
    auto it = s1.find({val, pos});
    if (it != s1.end()) {
      sum -= val;
      s1.erase(it);
    }
    s2.erase({val, pos});
    fixup();
  }
  void add(int val, int pos) {
    s1.insert({val, pos});
    sum += val;
    fixup();
  }
};
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  topx extra;
  vector<pair<int, int>> v[4];
  set<pair<int, int>> print_aux;
  for (int i = 0; i < n; i++) {
    int t, a, b;
    scanf("%d %d %d", &t, &a, &b);
    print_aux.insert({t, i});
    v[2 * a + b].emplace_back(t, i);
    if (a + b == 0) extra.add(t, i);
  }
  for (int i = 1; i < 4; i++) sort(v[i].begin(), v[i].end());
  int st = max(0, max(2 * k - m, k - (int)min(v[1].size(), v[2].size())));
  int end = min((int)v[3].size(), k);
  if (st > end) {
    printf("-1\n");
    return 0;
  }
  int cost = 0;
  auto process = [&extra, &cost](int sz, vector<pair<int, int>>& v) {
    for (int i = 0; i < v.size(); i++)
      if (i < sz)
        cost += v[i].first;
      else
        extra.add(v[i].first, v[i].second);
  };
  process(st, v[3]);
  process(k - st, v[1]);
  process(k - st, v[2]);
  assert(extra.set_x(m - 2 * k + st));
  int ans = cost + extra.sum, best = st;
  for (int i = st + 1; i <= end; i++) {
    extra.remove(v[3][i - 1].first, v[3][i - 1].second);
    cost += v[3][i - 1].first;
    int aux = k - i;
    for (int z = 1; z <= 2; z++) {
      extra.add(v[z][i].first, v[z][i].second);
      cost -= v[z][i].first;
    }
    assert(extra.set_x(m - 2 * k + i));
    int new_cost = cost + extra.sum;
    if (new_cost < ans) {
      ans = new_cost;
      best = i;
    }
  }
  vector<int> to_print;
  for (int i = 0; i < best; i++) {
    to_print.push_back(v[3][i].second);
    print_aux.erase(v[3][i]);
  }
  for (int i = 0; i < k - best; i++) {
    to_print.push_back(v[1][i].second);
    to_print.push_back(v[2][i].second);
    print_aux.erase(v[1][i]);
    print_aux.erase(v[2][i]);
  }
  while (to_print.size() < m) {
    to_print.push_back(print_aux.begin()->second);
    print_aux.erase(print_aux.begin());
  }
  printf("%d\n", ans);
  for (int i = 0; i < to_print.size(); i++) printf("%d ", to_print[i] + 1);
  printf("\n");
}
