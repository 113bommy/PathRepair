#include <bits/stdc++.h>
using namespace std;
long long par[123456][18];
long long dist[123456], u[123456], v[123456], d[123456], lev[123456];
long long visit[123456], touch[123456];
vector<long long> vec;
vector<vector<long long> > adj(123456);
int dfs(int cur) {
  visit[cur] = 1;
  int i;
  int flag = 0, gg, haha;
  for (i = 0; i < adj[cur].size(); i++) {
    haha = adj[cur][i];
    gg = ((cur ^ u[haha]) ^ v[haha]);
    if (visit[gg]) {
      if (touch[haha]) continue;
      touch[haha] = 1;
      flag = 1;
    } else {
      touch[haha] = 1;
      par[gg][0] = cur;
      lev[gg] = lev[cur] + 1;
      dist[gg] = dist[cur] + d[haha];
      dfs(gg);
    }
  }
  if (flag) {
    vec.push_back(cur);
  }
  return 0;
}
long long iinf;
long long wow[123456];
int doshort(int ver, int n) {
  int i;
  for (i = 0; i < n; i++) {
    wow[i] = iinf;
  }
  set<pair<long long, long long> > seti;
  wow[ver] = 0;
  for (i = 0; i < n; i++) {
    seti.insert(make_pair(wow[i], i));
  }
  pair<long long, long long> papa;
  long long cur, haha, gg;
  while (!seti.empty()) {
    papa = *(seti.begin());
    seti.erase(papa);
    cur = papa.second;
    for (i = 0; i < adj[cur].size(); i++) {
      haha = adj[cur][i];
      gg = ((cur ^ u[haha]) ^ v[haha]);
      if (wow[gg] > wow[cur] + d[haha]) {
        seti.erase(make_pair(wow[gg], gg));
        wow[gg] = wow[cur] + d[haha];
        seti.insert(make_pair(wow[gg], gg));
      }
    }
  }
  return 0;
}
int lca(int p, int q) {
  if (lev[p] > lev[q]) {
    swap(p, q);
  }
  int i;
  for (i = 17; i >= 0; i--) {
    if (lev[q] - (1 << i) >= lev[p]) {
      q = par[q][i];
    }
  }
  if (p == q) return p;
  for (i = 17; i >= 0; i--) {
    if (par[p][i] != par[q][i]) {
      p = par[p][i];
      q = par[q][i];
    }
  }
  return par[p][0];
}
long long foo[22][123456];
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  iinf = (1000 * 1000 * 1000 + 5);
  iinf *= (1000 * 1000 * 1000 + 5);
  int i;
  for (i = 0; i < m; i++) {
    cin >> u[i] >> v[i] >> d[i];
    u[i]--;
    v[i]--;
    adj[u[i]].push_back(i);
    adj[v[i]].push_back(i);
  }
  par[0][0] = -1;
  dist[0] = 0;
  lev[0] = 0;
  dfs(0);
  int j;
  for (j = 1; j < 18; j++) {
    for (i = 0; i < n; i++) {
      if (par[i][j - 1] == -1)
        par[i][j] = -1;
      else
        par[i][j] = par[par[i][j - 1]][j - 1];
    }
  }
  for (i = 0; i < vec.size(); i++) {
    doshort(vec[i], n);
    for (j = 0; j < n; j++) {
      foo[i][j] = wow[j];
    }
  }
  int q;
  cin >> q;
  int x, y;
  long long mini, gg;
  for (j = 0; j < q; j++) {
    cin >> x >> y;
    x--;
    y--;
    mini = iinf;
    for (i = 0; i < vec.size(); i++) {
      mini = min(mini, foo[i][x] + foo[i][y]);
    }
    gg = lca(x, y);
    mini = min(mini, dist[x] + dist[y] - 2 * dist[gg]);
    cout << mini << endl;
  }
  return 0;
}
