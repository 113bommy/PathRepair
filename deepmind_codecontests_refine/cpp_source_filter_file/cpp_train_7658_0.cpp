#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 5;
vector<pair<int, int> > adj[MAX];
vector<int> bad[MAX];
pair<int, int> p[MAX];
int x[MAX], y[MAX], w[MAX], s[MAX], L[MAX];
int st[MAX], en[MAX], sons[MAX];
long long sum_st[MAX], bit[MAX];
int tempo = 1, max_level = 0, n;
void update(int idx, long long val) {
  while (idx <= n) {
    bit[idx] += val;
    idx += idx & -idx;
  }
}
long long query(int idx) {
  long long sum = 0;
  while (idx) {
    sum += bit[idx];
    idx -= idx & -idx;
  }
  return sum;
}
long long get_st_sum(int node) {
  return sum_st[node] -
         (query(en[node]) - (st[node] > 1 ? query(st[node] - 1) : 0));
}
long long dfs(int source) {
  st[source] = tempo++;
  for (auto &each : adj[source]) {
    if (each.first != p[source].first) {
      long long cur = dfs(each.first);
      L[each.first] = L[source] + 1;
      sum_st[source] += w[each.second];
      sum_st[source] += cur;
      if (cur > s[each.second]) {
        bad[L[source]].push_back(each.second);
      }
    }
  }
  en[source] = tempo - 1;
  return sum_st[source];
}
int main() {
  scanf("%d", &n);
  for (int i = int(1); i < int(n); i++) {
    scanf("%d %d %d %d", x + i, y + i, w + i, s + i);
    p[y[i]] = make_pair(x[i], i);
    adj[x[i]].emplace_back(y[i], i);
    sons[x[i]]++;
  }
  dfs(1);
  set<pair<int, int> > avail;
  for (int i = int(1); i < int(n + 1); i++) {
    if (sons[i] == 0) {
      avail.emplace(st[i], i);
    }
  }
  for (int i = int(n); i >= int(0); i--) {
    for (auto &each : bad[i]) {
      int down = y[each];
      while (s[each] < get_st_sum(down)) {
        auto it = avail.lower_bound(make_pair(st[down], 0));
        if (it != avail.end() && it->second == down) {
          it = next(it);
        }
        if (it == avail.end() || st[it->second] > en[down]) {
          puts("-1");
          return 0;
        }
        int id = it->second;
        int k = p[id].second;
        long long need = get_st_sum(down) - s[each];
        long long has = min((long long)w[k] - 1, s[k] - get_st_sum(id));
        long long to_use = min(need, has);
        w[k] -= to_use;
        s[k] -= to_use;
        has -= to_use;
        update(id, to_use);
        if (has == 0) {
          avail.erase(it);
          sons[x[k]]--;
          if (sons[x[k]] == 0) {
            avail.emplace(st[x[k]], x[k]);
          }
        }
      }
    }
  }
  printf("%d\n", n);
  for (int i = int(1); i < int(n); i++) {
    printf("%d %d %d %d\n", x[i], y[i], w[i], s[i]);
  }
  return 0;
}
