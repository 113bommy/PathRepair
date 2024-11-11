#include <bits/stdc++.h>
using namespace std;
long long int vis[200005], comp, store[200005][2], ans[200005][2];
vector<long long int> res;
vector<long long int> c[200005], v[200005];
vector<pair<long long int, long long int> > edge;
vector<pair<long long int, long long int> > temp;
void dfs(long long int cur) {
  vis[cur] = comp;
  for (long long int i = 0; i < v[cur].size(); i++) {
    long long int x = v[cur][i];
    if (vis[x]) continue;
    temp.push_back(make_pair(x, cur));
    dfs(x);
  }
}
int main() {
  ios::sync_with_stdio(false);
  ;
  cin.tie(0);
  ;
  long long int i, j, n, m, s, t, ls, lt, x, y, f = 0;
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> x >> y;
    edge.push_back(make_pair(x, y));
  }
  cin >> s >> t >> ls >> lt;
  for (i = 0; i < edge.size(); i++) {
    x = edge[i].first;
    y = edge[i].second;
    if (x == s || x == t || y == s || y == t) continue;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  for (i = 1; i <= n; i++) {
    if (i == s || i == t || vis[i]) continue;
    comp++;
    dfs(i);
  }
  for (i = 1; i <= n; i++) v[i].clear();
  for (i = 0; i < edge.size(); i++) {
    x = edge[i].first;
    y = edge[i].second;
    if (x == s && y == t) {
      f = 1;
      continue;
    }
    if (x == t && y == s) {
      f = 1;
      continue;
    }
    if (x != s && x != t && y != s && y != t) continue;
    if (x == s) {
      v[x].push_back(vis[y]);
      v[vis[y]].push_back(x);
      store[vis[y]][0] = 1;
    }
    if (x == t) {
      v[x].push_back(vis[y]);
      v[vis[y]].push_back(x);
      store[vis[y]][1] = 1;
    }
    if (y == s) {
      v[y].push_back(vis[x]);
      v[vis[x]].push_back(y);
      store[vis[x]][0] = 1;
    }
    if (y == t) {
      v[y].push_back(vis[x]);
      v[vis[x]].push_back(y);
      store[vis[x]][1] = 1;
    }
  }
  for (i = 0; i < edge.size(); i++) {
    x = edge[i].first;
    y = edge[i].second;
    if (x == s && y == t) continue;
    if (x == t && y == s) continue;
    if (x != s && x != t && y != s && y != t) continue;
    if (x == s) ans[vis[y]][0] = i;
    if (x == t) ans[vis[y]][1] = i;
    if (y == s) ans[vis[x]][0] = i;
    if (y == t) ans[vis[x]][1] = i;
  }
  for (i = 1; i <= comp; i++) {
    if (store[i][0] && store[i][1]) continue;
    if (store[i][0]) {
      res.push_back(ans[i][0]);
      ls--;
    } else {
      lt--;
      res.push_back(ans[i][1]);
    }
  }
  if (ls < 0 || lt < 0) {
    cout << "No";
    return 0;
  }
  long long int pos;
  for (i = 1; i <= comp; i++) {
    if (store[i][0] && store[i][1]) {
      pos = i;
      res.push_back(ans[i][0]);
      res.push_back(ans[i][1]);
      ls--;
      lt--;
      break;
    }
  }
  if (!pos && !f) {
    cout << "No";
    return 0;
  }
  if (!pos && f) {
    temp.push_back(make_pair(s, t));
    ls--;
    lt--;
  } else {
    for (i = 1; i <= comp; i++) {
      if (store[i][0] && store[i][1] && i != pos) {
        if (ls >= lt) {
          res.push_back(ans[i][0]);
          ls--;
        } else {
          res.push_back(ans[i][1]);
          lt--;
        }
      }
    }
  }
  if (ls < 0 || lt < 0) {
    cout << "No";
    return 0;
  }
  cout << "Yes"
       << "\n";
  for (i = 0; i < res.size(); i++)
    cout << edge[res[i]].first << " " << edge[res[i]].second << "\n";
  for (i = 0; i < temp.size(); i++)
    cout << temp[i].first << " " << temp[i].second << "\n";
  return 0;
}
