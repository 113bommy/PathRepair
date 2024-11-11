#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 2;
vector<int> adj[N], lis;
set<int> adj1[N];
int sz[N];
struct change {
  int x, y, y1;
};
vector<change> ans_lis;
void dfs1(int x, int p) {
  for (int i : adj[x]) {
    if (i != p) {
      adj1[i].insert(x);
      adj1[x].insert(i);
      dfs1(i, x);
    }
  }
  if (adj1[x].size() == 1) {
    lis.push_back(x);
  }
}
void dfs(int x, int p) {
  sz[x] = 1;
  for (int i : adj[x]) {
    if (i != p) {
      dfs(i, x);
      sz[x] += sz[i];
    }
  }
}
int findcen(int x, int p, int siz) {
  for (int i : adj[x]) {
    if (i != p && sz[i] > siz / 2) {
      return findcen(i, x, siz);
    }
  }
  return x;
}
void solve(int x, int p) {
  int now = x, now1 = p;
  vector<pair<int, int> > adj_lis;
  dfs1(x, p);
  if (!lis.size()) {
    return;
  }
  while (lis.size()) {
    ans_lis.push_back({now1, now, lis.back()});
    now = lis.back();
    lis.pop_back();
    while (true) {
      if (adj1[now].size() != 1) {
        break;
      }
      adj_lis.push_back({now1, now});
      auto ite = adj1[now].begin();
      adj1[*ite].erase(now);
      now1 = now;
      now = *ite;
      adj1[now1].erase(ite);
    }
  }
  adj_lis.push_back({now1, now});
  for (int i = adj_lis.size() - 2; i >= 0; i--) {
    ans_lis.push_back({adj_lis[i].first, adj_lis[i].second, now});
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, i, j, k, l, cen, cen1 = 0;
  cin >> n;
  for (i = 1; i < n; i++) {
    cin >> j >> k;
    adj[j].push_back(k);
    adj[k].push_back(j);
  }
  dfs(1, 1);
  cen = findcen(1, 1, n);
  dfs(cen, cen);
  if (!(n & 1)) {
    for (i = 0; i < adj[cen].size(); i++) {
      if (sz[adj[cen][i]] == n / 2) {
        cen1 = adj[cen][i];
        break;
      }
    }
  }
  if (!cen1) {
    for (i = 0; i < adj[cen].size(); i++) {
      solve(adj[cen][i], cen);
    }
  } else {
    for (i = 0; i < adj[cen].size(); i++) {
      if (adj[cen][i] != cen1) {
        solve(adj[cen][i], cen);
      }
    }
    for (i = 0; i < adj[cen1].size(); i++) {
      if (adj[cen1][i] != cen) {
        solve(adj[cen1][i], cen1);
      }
    }
  }
  cout << ans_lis.size() << '\n';
  for (i = 0; i < ans_lis.size(); i++) {
    cout << ans_lis[i].x << ' ' << ans_lis[i].y << ' ' << ans_lis[i].y1 << '\n';
  }
}
