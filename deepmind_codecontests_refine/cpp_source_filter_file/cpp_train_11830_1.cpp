#include <bits/stdc++.h>
using namespace std;
map<int, queue<pair<long long, int>>> taxis;
set<pair<long long, pair<int, int>>> zda;
long long timer = 0;
void dorzuc(int x, int id, long long t) { taxis[x].push({t, id}); }
void rob_event() {
  timer = max(timer, zda.begin()->first);
  dorzuc(zda.begin()->second.first, zda.begin()->second.second,
         zda.begin()->first);
  zda.erase(zda.begin());
}
pair<int, int> wybierz(int x) {
  auto it = taxis.lower_bound(x);
  auto id = it;
  if (id == taxis.end() || it->first > x) {
    id--;
  }
  auto chosen = it;
  if (it != taxis.end() && id != taxis.end()) {
    if (abs(x - it->first) == abs(x - id->first)) {
      if (it->second.front() < it->second.front()) {
        chosen = it;
      } else {
        chosen = id;
      }
    } else if (abs(x - it->first) < abs(x - it->first)) {
      chosen = it;
    } else {
      chosen = id;
    }
  } else if (chosen == taxis.end())
    chosen = id;
  int result = chosen->second.front().second;
  int gdzie = chosen->first;
  chosen->second.pop();
  if (chosen->second.empty()) {
    taxis.erase(chosen);
  }
  return {gdzie, result};
}
int main() {
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for (int i = 1; i <= k; i++) {
    int a;
    scanf("%d", &a);
    dorzuc(a, i, 0);
  }
  for (int i = 0; i < m; i++) {
    long long t;
    int a, b;
    scanf("%lld%d%d", &t, &a, &b);
    timer = max(t, timer);
    while ((not zda.empty() && zda.begin()->first <= timer) || taxis.empty())
      rob_event();
    auto p = wybierz(a);
    int id = p.second;
    int gdzie = p.first;
    {};
    printf("%d %lld\n", id, timer - t + abs(gdzie - a));
    zda.insert({timer + abs(gdzie - a) + abs(b - a), {b, id}});
  }
}
