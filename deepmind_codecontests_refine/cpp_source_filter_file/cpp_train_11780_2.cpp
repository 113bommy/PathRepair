#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int q;
vector<int> v;
vector<int> vv;
int en[100002];
map<int, int> pos;
int las[100002];
int most[100002];
vector<int> g[100002];
vector<int> E;
vector<pair<int, int> > query[100002];
bool vis[100002];
deque<int> stk;
inline void dfs(int b) {
  vis[b] = true;
  stk.push_front(b);
  for (int go : g[b]) {
    dfs(go);
  }
  for (auto el : query[b]) {
    int id = el.first;
    int want = el.second;
    if (stk.size() <= want) {
      most[id] = -1;
    } else {
      most[id] = stk[want];
    }
  }
  stk.pop_front();
}
vector<pair<int, int> > ask[100002];
deque<pair<int, int> > dd;
int ans[100002];
int main() {
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    v.push_back(a);
    pos[a] = i;
  }
  for (int i = 0; i < m; i++) {
    int a;
    scanf("%d", &a);
    vv.push_back(a);
  }
  memset(las, -1, sizeof(las));
  for (int i = 0; i < m; i++) {
    int val = pos[vv[i]];
    if (val == n - 1) {
      E.push_back(i);
    }
    if (val == 0) {
      en[i] = i;
    } else {
      int pv = v[val - 1];
      if (las[pv] == -1) {
        en[i] = -1;
      } else {
        g[las[pv]].push_back(i);
        en[i] = en[las[pv]];
      }
    }
    las[vv[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    int lef = en[i];
    if (lef == -1) {
      most[i] = -1;
      continue;
    }
    if (vv[i] == v.back()) {
      most[i] = lef;
      continue;
    }
    lef--;
    int p = pos[vv[i]];
    p = n - p - 1 - 1;
    int z = lower_bound(E.begin(), E.end(), lef + 1) - E.begin();
    z--;
    if (z >= 0) {
      query[E[z]].push_back(make_pair(i, p));
    } else {
      most[i] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    if (vis[i] == false) {
      dfs(i);
    }
  }
  int id = 0;
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--;
    r--;
    ask[r].push_back(make_pair(l, id));
    id++;
  }
  for (int i = 0; i < m; i++) {
    while (dd.size() && dd.back().second < most[i]) {
      dd.pop_back();
    }
    dd.push_back(make_pair(i, most[i]));
    for (auto el : ask[i]) {
      int id = lower_bound(dd.begin(), dd.end(), make_pair(el.first, -1)) -
               dd.begin();
      if (dd[id].second >= el.first) {
        ans[el.second] = 1;
      } else {
        ans[el.second] = 0;
      }
    }
  }
  for (int i = 0; i < id; i++) {
    printf("%d", ans[i]);
  }
  puts("");
  return 0;
}
