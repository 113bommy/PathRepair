#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const int N = 2e5 + 5;
int aa, bb, ST[4 * N], n, m, i, j, k, ans[N];
pair<int, int> a[N];
pair<pair<int, int>, pair<int, int> > q[N];
vector<pair<pair<int, int>, pair<int, int> > > qu[N];
vector<int> v[N], v2[N];
int update(int k, int bas, int son, int x, int y) {
  if (bas > x || son < x) return ST[k];
  if (bas == son && bas == x) {
    ST[k] = y;
    return ST[k];
  }
  return ST[k] = max(update((k + k), bas, (bas + son >> 1), x, y),
                     update((k + k + 1), (bas + son >> 1) + 1, son, x, y));
}
int query(int k, int bas, int son, int x, int y) {
  if (bas > y || son < x) return 0;
  if (x <= bas && son <= y) return ST[k];
  return max(query((k + k), bas, (bas + son >> 1), x, y),
             query((k + k + 1), (bas + son >> 1) + 1, son, x, y));
}
void solve() {
  for (int i = 1; i <= aa; i++) {
    sort(v2[i].begin(), v2[i].end());
    sort(v[i].begin(), v[i].end());
    if (v2[i].empty())
      update(1, 1, bb, i, inf);
    else
      update(1, 1, bb, i, v2[i].front());
  }
  int cur;
  for (int i = 1; i <= aa; i++) {
    for (__typeof(qu[i].begin()) it = qu[i].begin(); it != qu[i].end(); it++) {
      if (query(1, 1, bb, it->first.first, it->first.second) <=
          it->second.first) {
        ans[it->second.second] = 1;
      }
    }
    for (__typeof(v[i].begin()) it = v[i].begin(); it != v[i].end(); it++) {
      cur = upper_bound(v2[*it].begin(), v2[*it].end(), i) - v2[*it].begin();
      if (cur == v2[*it].size())
        cur = inf;
      else
        cur = v2[*it][cur];
      update(1, 1, bb, *it, cur);
    }
  }
}
int main() {
  scanf("%d %d %d %d", &bb, &aa, &n, &m);
  aa = 200000;
  bb = 200000;
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &a[i].first, &a[i].second);
    v[a[i].first].push_back(a[i].second);
    v2[a[i].second].push_back(a[i].first);
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d %d", &q[i].first.first, &q[i].first.second,
          &q[i].second.first, &q[i].second.second);
    qu[q[i].first.first].push_back(
        make_pair(make_pair(q[i].first.second, q[i].second.second),
                  make_pair(q[i].second.first, i)));
  }
  solve();
  for (int i = 1; i <= aa; i++) {
    v[i].clear();
    v2[i].clear();
    qu[i].clear();
  }
  swap(aa, bb);
  for (int i = 1; i <= n; i++) {
    swap(a[i].first, a[i].second);
    v[a[i].first].push_back(a[i].second);
    v2[a[i].second].push_back(a[i].first);
  }
  for (int i = 1; i <= m; i++) {
    swap(q[i].first.first, q[i].first.second);
    swap(q[i].second.first, q[i].second.second);
    qu[q[i].first.first].push_back(
        make_pair(make_pair(q[i].first.second, q[i].second.second),
                  make_pair(q[i].second.first, i)));
  }
  solve();
  for (int i = 1; i <= m; i++) {
    if (ans[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
