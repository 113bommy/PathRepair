#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9, mod = 1e9 + 7;
const int N = 1e5 + 5;
int S = 1, t1, t2, n, m, k, x, y, z, size[N], root[N], h[N], sum[N];
long long res[N];
vector<pair<pair<int, int>, pair<int, int> > > edges;
vector<pair<int, int> > v[N];
int findset(int x) {
  return root[x] = (root[x] == x) ? root[x] : findset(root[x]);
}
void merge(int x, int y) {
  if ((t1 = findset(x)) == (t2 = findset(y))) return;
  root[t1] = t2;
  size[t2] += size[t1];
  size[t1] = 0;
}
int prepare(int node, int last, int col) {
  sum[node] = size[node];
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++)
    if (it->first != last) {
      sum[node] += prepare(it->first, node, S);
      h[it->first] = col;
    }
  return sum[node];
}
void solve(int node, int last, int all) {
  for (__typeof(v[node].begin()) it = v[node].begin(); it != v[node].end();
       it++) {
    if (it->first == last) continue;
    res[it->second] = 2LL * (all - sum[it->first]) * sum[it->first];
    solve(it->first, node, all);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    scanf("%d %d %d", &x, &y, &z);
    edges.push_back(make_pair(make_pair(z, i), make_pair(x, y)));
  }
  sort(edges.begin(), edges.end());
  for (int i = 1; i <= n; i++) root[i] = i, size[i] = 1;
  for (int i = 0; i <= (int)edges.size() - 1; i++) {
    int last = i;
    while (i < (int)edges.size() - 1 &&
           edges[i + 1].first.first == edges[last].first.first)
      i++;
    vector<int> temp;
    ++S;
    for (int j = last; j <= i; j++) {
      int x = findset(edges[j].second.first);
      int y = findset(edges[j].second.second);
      temp.push_back(x);
      temp.push_back(y);
      v[x].push_back(make_pair(y, edges[j].first.second));
      v[y].push_back(make_pair(x, edges[j].first.second));
    }
    sort(temp.begin(), temp.end());
    temp.resize(unique(temp.begin(), temp.end()) - temp.begin());
    for (__typeof(temp.begin()) it = temp.begin(); it != temp.end(); it++)
      if (h[*it] != S) prepare(*it, 0, S);
    for (__typeof(temp.begin()) it = temp.begin(); it != temp.end(); it++)
      if (h[*it] != S) solve(*it, 0, sum[*it]);
    for (__typeof(temp.begin()) it = temp.begin(); it != temp.end(); it++) {
      for (__typeof(v[*it].begin()) it2 = v[*it].begin(); it2 != v[*it].end();
           it2++)
        merge(*it, it2->first);
      v[*it].clear();
    }
  }
  long long mx = *max_element(res + 1, res + n), cnt = 0;
  for (int i = 1; i <= n - 1; i++) cnt += res[i] == mx;
  printf("%lld %lld\n", mx, cnt);
  for (int i = 1; i <= n - 1; i++)
    if (res[i] == mx) printf("%d ", i);
  return 0;
}
