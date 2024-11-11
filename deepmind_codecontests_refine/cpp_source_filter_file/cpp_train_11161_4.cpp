#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int all[500000 + 10], l[500000 + 10], used[500000 + 10], r[500000 + 10], n,
    children[500000 + 10], ok;
vector<int> each[500000 + 10];
void dfs(int now, int prev) {
  if (prev == -1) {
    children[now] = each[now].size();
  } else {
    children[now] = each[now].size() - 1;
  }
  for (auto it : each[now]) {
    if (it != prev) {
      dfs(it, now);
      all[now] += all[it];
    }
  }
  all[now] += children[now];
}
void build(int now, int prev) {
  int tmp = ok;
  l[now] = ok + all[now] * 2 - children[now] + 1;
  for (auto it : each[now]) {
    if (it != prev) {
      build(it, now);
      ok--;
    }
  }
  ok = tmp + (all[now] + 1) * 2;
}
vector<int> r_bound;
int pt = 0;
void calc(int now, int prev) {
  for (auto it : each[now]) {
    if (it != prev) {
      calc(it, now);
    }
  }
  int SZ = each[now].size();
  if (SZ)
    for (int i = SZ - 1; i >= 0; --i)
      if (each[now][i] != prev) r[each[now][i]] = r_bound[pt++];
}
int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    each[u].push_back(v);
    each[v].push_back(u);
  }
  dfs(1, -1);
  build(1, -1);
  for (int i = 1; i <= n; ++i) used[l[i]] = 1;
  for (int i = 1; i <= 2 * n; ++i) {
    if (!used[i]) {
      r_bound.push_back(i);
    }
  }
  sort(r_bound.begin(), r_bound.end());
  calc(1, -1);
  r[1] = r_bound[pt++];
  for (int i = 1; i <= n; ++i) {
    printf("%d %d\n", l[i], r[i]);
  }
  return 0;
}
