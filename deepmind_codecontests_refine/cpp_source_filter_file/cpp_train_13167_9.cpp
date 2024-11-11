#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using ti = tuple<int, int, int>;
using lint = long long;
using li = pair<lint, int>;
const int N = 3 * 1e5 + 5;
const lint inf = 1e18 + 5;
int n, m, st;
vector<ti> a[N];
vector<ii> pr[N];
lint ans_val;
vector<int> ans_vec;
lint dist[N];
void make() {
  priority_queue<li, vector<li>, greater<li> > pq;
  fill(dist, dist + N, inf);
  pq.push(li(0, st));
  dist[st] = 0;
  while (!pq.empty()) {
    lint cd = pq.top().first;
    int cp = pq.top().second;
    pq.pop();
    for (size_t i = 0; i < a[cp].size(); i++) {
      int idx = get<0>(a[cp][i]);
      int np = get<1>(a[cp][i]);
      int ct = get<2>(a[cp][i]);
      lint nd = cd + (lint)(ct);
      if (dist[np] >= nd) {
        if (dist[np] > nd) {
          pr[np].clear();
          dist[np] = nd;
          pq.push(li(nd, np));
        }
        pr[np].push_back(ii(ct, cp));
      }
    }
  }
}
void go() {
  vector<li> v;
  for (int i = 1; i <= n; i++) {
    v.push_back(li(dist[i], i));
    sort(pr[i].begin(), pr[i].end());
  }
  sort(v.begin(), v.end());
  for (int i = 1; i < n; i++) {
    int idx = v[i].second;
    ans_val += (lint)(pr[i][0].first);
    ans_vec.push_back(pr[i][0].second);
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    a[x].push_back(ti(i, y, w));
    a[y].push_back(ti(i, x, w));
  }
  scanf("%d", &st);
  make();
  go();
  printf("%lld\n", ans_val);
  for (int e : ans_vec) {
    printf("%d ", e);
  }
  return 0;
}
