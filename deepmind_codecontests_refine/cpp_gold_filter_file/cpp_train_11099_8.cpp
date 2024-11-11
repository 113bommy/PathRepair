#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > go_add[1000000 + 5];
vector<pair<int, int> > ret_add[1000000 + 5];
int go_cost[1000000 + 5], ret_cost[1000000 + 5];
multiset<int> go_avl[1000000 + 5], ret_avl[1000000 + 5];
int main() {
  int i, n, m, k, d, u, v, c, min_d, r;
  long long int mn = 0, curr = 0;
  scanf("%d %d %d", &n, &m, &k);
  k += 2;
  for (i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &d, &u, &v, &c);
    if (u == 0)
      ret_add[d].push_back(pair<int, int>(v, c));
    else
      go_add[d].push_back(pair<int, int>(u, c));
  }
  int counter = 0;
  for (d = 1; d <= 1000000; d++) {
    for (auto x : go_add[d]) {
      v = x.first;
      c = x.second;
      go_avl[v].insert(c);
      if (go_avl[v].size() == 1) counter++;
    }
    if (counter == n) break;
  }
  if (counter != n) {
    puts("-1");
    return 0;
  }
  for (i = 1; i <= n; i++) {
    go_cost[i] = *go_avl[i].begin();
    mn += go_cost[i];
  }
  min_d = d;
  for (d = 1000000; d >= min_d + k - 1; d--) {
    for (auto x : ret_add[d]) {
      v = x.first;
      c = x.second;
      ret_avl[v].insert(c);
    }
  }
  for (i = 1; i <= n; i++)
    if (ret_avl[i].size()) {
      ret_cost[i] = *(ret_avl[i].begin());
      mn += ret_cost[i];
    } else {
      puts("-1");
      return 0;
    }
  curr = mn;
  for (d = min_d + 1; d <= 1000000 - k + 1; d++) {
    r = d + k - 1;
    for (auto x : go_add[d]) {
      v = x.first;
      c = x.second;
      go_avl[v].insert(c);
      if (go_cost[v] > c) {
        curr -= go_cost[v];
        curr += c;
        go_cost[v] = c;
      }
    }
    for (auto x : ret_add[r - 1]) {
      v = x.first;
      c = x.second;
      ret_avl[v].erase(ret_avl[v].find(c));
      if (!ret_avl[v].size()) {
        cout << mn << endl;
        return 0;
      } else if (ret_cost[v] != *ret_avl[v].begin()) {
        curr -= ret_cost[v];
        ret_cost[v] = *ret_avl[v].begin();
        curr += ret_cost[v];
      }
    }
    mn = min(mn, curr);
  }
  cout << mn << endl;
  return 0;
}
