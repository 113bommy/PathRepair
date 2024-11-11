#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 9;
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int> > guys;
  set<pair<int, int> > alive;
  map<pair<int, int>, int> id, in;
  map<pair<int, int>, set<pair<int, int> > > adj, back_adj;
  map<int, pair<int, int> > back;
  for (int i = int(0); i < int(n); i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    guys.emplace_back(x, y);
    alive.emplace(x, y);
    id[make_pair(x, y)] = i;
    back[i] = make_pair(x, y);
  }
  for (auto &each : guys) {
    int x, y;
    tie(x, y) = each;
    if (y > 0) {
      if (alive.count(make_pair(x - 1, y - 1))) {
        adj[make_pair(x, y)].emplace(x - 1, y - 1);
        back_adj[make_pair(x - 1, y - 1)].emplace(x, y);
        in[make_pair(x - 1, y - 1)]++;
      }
      if (alive.count(make_pair(x, y - 1))) {
        adj[make_pair(x, y)].emplace(x, y - 1);
        back_adj[make_pair(x, y - 1)].emplace(x, y);
        in[make_pair(x, y - 1)]++;
      }
      if (alive.count(make_pair(x + 1, y - 1))) {
        adj[make_pair(x, y)].emplace(x + 1, y - 1);
        back_adj[make_pair(x + 1, y - 1)].emplace(x, y);
        in[make_pair(x + 1, y - 1)]++;
      }
    }
  }
  set<int> order;
  for (int i = int(0); i < int(n); i++) {
    int x, y;
    tie(x, y) = back[i];
    if (in[make_pair(x, y)] == 0) {
      order.insert(i);
    }
    pair<int, int> p = make_pair(x, y);
    bool good = true;
    for (auto &each_back : back_adj[p]) {
      good &= adj[each_back].size() > 1;
    }
    if (good) {
      order.insert(i);
    }
  }
  set<int> rolled;
  int player = 0;
  vector<int> vals;
  while (!order.empty()) {
    int val;
    if (player == 0) {
      val = *order.rbegin();
      order.erase(prev(order.end()));
    } else {
      val = *order.begin();
      order.erase(order.begin());
    }
    for (auto &each_back : back_adj[back[val]]) {
      adj[each_back].erase(back[val]);
      if (adj[each_back].size() == 1) {
        order.erase(id[*adj[each_back].begin()]);
      }
    }
    vals.push_back(val);
    rolled.insert(val);
    int x, y;
    tie(x, y) = back[val];
    for (auto &each : adj[make_pair(x, y)]) {
      in[each]--;
      auto p = make_pair(x, y);
      back_adj[each].erase(p);
      bool good = true;
      for (auto &each_back : back_adj[each]) {
        good &= adj[each_back].size() > 1;
      }
      if ((good || in[each] == 0) && !rolled.count(id[each])) {
        order.insert(id[each]);
      }
    }
    player = !player;
  }
  int ans = 0;
  int mult = 1;
  for (int i = int(vals.size() - 1); i >= int(0); i--) {
    ans = (ans + ((1LL * mult * vals[i]) % MOD)) % MOD;
    mult = (1LL * mult * n) % MOD;
  }
  printf("%d\n", ans);
  return 0;
}
