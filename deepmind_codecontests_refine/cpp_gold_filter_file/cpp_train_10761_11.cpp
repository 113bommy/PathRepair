#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 5;
const int mod = (int)1e9 + 7;
const int logN = 17;
const int inf = 1e9 + 7;
const int N = 2e5 + 5;
int dp[N], n, m, x, y, z, t, p;
pair<int, pair<int, int> > H[N];
pair<int, int> up[N];
vector<int> g[N];
vector<pair<pair<int, int>, pair<int, int> > > v;
set<pair<int, int> > S;
map<int, vector<pair<int, int> > > add, del;
map<int, int> event;
int inter(int x, int y) {
  return min(H[x].second.second, H[y].second.second) -
         max(H[x].second.first, H[y].second.first);
}
int dfs(int node) {
  if (dp[node] != -1) return dp[node];
  int &r = dp[node];
  if (g[node].size() == 0) return r = 2 * inf;
  r = 0;
  for (__typeof(g[node].begin()) it = g[node].begin(); it != g[node].end();
       it++) {
    r = max(r, min(inter(node, *it), dfs(*it)));
  }
  return r;
}
void ADD(int x, int y, int c) {
  __typeof(S.begin()) it = S.lower_bound(make_pair(y, 0));
  if (it != S.end()) {
    int node = it->second;
    up[x] = make_pair(c, node);
  }
  if (it != S.begin()) {
    it--;
    int node = it->second;
    if (up[node].second) {
      v.push_back(make_pair(make_pair(up[node].first, c),
                            make_pair(node, up[node].second)));
    }
    up[node] = make_pair(c, x);
  }
  S.insert(make_pair(y, x));
}
void DEL(int x, int y, int c) {
  __typeof(S.begin()) it = S.lower_bound(make_pair(y, 0));
  if (up[x].second) {
    v.push_back(
        make_pair(make_pair(up[x].first, c), make_pair(x, up[x].second)));
    up[x] = make_pair(0, 0);
  }
  if (it != S.begin()) {
    it--;
    int node = it->second;
    if (up[node].second)
      v.push_back(make_pair(make_pair(up[node].first, c),
                            make_pair(node, up[node].second)));
    up[node] = make_pair(0, 0);
    it++;
    __typeof(S.begin()) it2 = it;
    it2--;
    S.erase(it);
    it = it2;
    it++;
    if (it != S.end()) {
      up[node] = make_pair(c, it->second);
    }
  } else {
    S.erase(it);
  }
}
int ok(int l, int r, int x, int y) {
  if (inter(x, y) == r - l) return true;
  return false;
}
int main() {
  scanf("%d %d", &n, &t);
  H[1] = make_pair(inf, make_pair(-inf, inf));
  ++n;
  for (int i = 2; i <= n; i++) {
    scanf("%d %d %d", &H[i].first, &H[i].second.first, &H[i].second.second);
  }
  for (int i = 1; i <= n; i++) {
    add[H[i].second.first].push_back(make_pair(H[i].first, i));
    del[H[i].second.second].push_back(make_pair(H[i].first, i));
    event[H[i].second.second] = event[H[i].second.first] = true;
  }
  for (__typeof(event.begin()) it = event.begin(); it != event.end(); it++) {
    vector<pair<int, int> > &add = ::add[it->first];
    vector<pair<int, int> > &del = ::del[it->first];
    for (__typeof(add.begin()) it2 = add.begin(); it2 != add.end(); it2++)
      ADD(it2->second, it2->first, it->first);
    for (__typeof(del.begin()) it2 = del.begin(); it2 != del.end(); it2++)
      DEL(it2->second, it2->first, it->first);
  }
  for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
    if (ok(it->first.first, it->first.second, it->second.first,
           it->second.second)) {
      g[it->second.second].push_back(it->second.first);
    }
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", dfs(1));
  return 0;
}
