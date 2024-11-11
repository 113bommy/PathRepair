#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
int n, m;
ll d[N];
int id[N];
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w);
    d[u] -= w;
    d[v] += w;
  }
  for (int i = 1; i <= n; i++) id[i] = i;
  sort(id + 1, id + n + 1, [](int i, int j) { return d[i] < d[j]; });
  vector<tuple<int, int, ll>> ans;
  for (int i = 1, j = n; i < j and d[id[i]]; i++) {
    while (i < j and d[id[i]] and -d[id[i]] >= d[id[j]]) {
      ans.emplace_back(id[i], id[j], d[id[j]]);
      d[id[i]] += d[id[j]];
      d[id[j]] = 0;
      j--;
    }
    if (d[id[i]]) {
      ans.emplace_back(id[i], id[j], d[id[i]]);
      d[id[j]] += d[id[i]];
      d[id[i]] = 0;
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto e : ans) {
    int u, v;
    ll w;
    tie(u, v, w) = e;
    printf("%d %d %lld\n", u, v, w);
  }
}
