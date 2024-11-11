#include <bits/stdc++.h>
using namespace std;
long long par[300000];
long long rnk[300000];
map<pair<long long, long long>, long long> mmpp;
long long st[300000][30];
long long vt[300000][30];
long long fnd(long long i) {
  if (par[i] == i)
    return i;
  else
    return fnd(par[i]);
}
void unon(long long i, long long j) {
  i = fnd(i);
  j = fnd(j);
  if (rnk[i] > rnk[j]) {
    par[j] = i;
  } else if (rnk[j] > rnk[i]) {
    par[i] = j;
  } else {
    par[j] = i;
    rnk[i]++;
  }
}
vector<long long> g[300000];
vector<pair<long long, pair<long long, long long> > > ege, bge;
vector<long long> mrk;
long long ht[300000];
void dfs(long long s, long long par, long long htt) {
  st[s][0] = par;
  if (par != s) vt[s][0] = mmpp[make_pair(min(s, par), max(s, par))];
  ht[s] = htt;
  for (long long i = 0; i < g[s].size(); i++) {
    if (g[s][i] != par) dfs(g[s][i], s, htt + 1);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) par[i] = i;
  for (i = 0; i < m; i++) {
    long long a, b, c;
    cin >> a >> b >> c;
    ege.push_back(make_pair(c, make_pair(a, b)));
    mrk.push_back(0);
  }
  bge = ege;
  sort((ege).begin(), (ege).end());
  for (i = 0; i < m; i++) {
    long long a = ege[i].second.first;
    long long b = ege[i].second.second;
    if (fnd(a) != fnd(b)) {
      unon(a, b);
      mrk[i] = 1;
      g[a].push_back(b);
      g[b].push_back(a);
      mmpp[make_pair(min(a, b), max(a, b))] = ege[i].first;
    }
  }
  dfs(1, 1, 1);
  for (j = 1; j <= 20; j++) {
    for (i = 1; i <= n; i++) {
      st[i][j] = st[st[i][j - 1]][j - 1];
      vt[i][j] = max(vt[i][j - 1], vt[st[i][j - 1]][j - 1]);
    }
  }
  ege = bge;
  for (i = 0; i < m; i++) {
    long long a = ege[i].second.first;
    long long b = ege[i].second.second;
    if (mmpp.find(make_pair(min(a, b), max(a, b))) != mmpp.end()) continue;
    if (ht[a] > ht[b]) swap(a, b);
    for (j = 20; j >= 0; j--) {
      if (ht[b] - ht[a] >= (long long)(1 << j)) {
        b = st[b][j];
      }
    }
    if (a != b) {
      for (j = 20; j >= 0; j--) {
        if (st[a][j] != st[b][j]) {
          a = st[a][j];
          b = st[b][j];
        }
      }
      a = st[a][0];
      b = st[b][0];
    }
    long long lca = a;
    a = ege[i].second.first;
    b = ege[i].second.second;
    long long ma = -1, mb = -1;
    for (j = 20; j >= 0; j--) {
      if (ht[st[a][j]] >= ht[lca]) {
        ma = max(ma, vt[a][j]);
        a = st[a][j];
      }
    }
    for (j = 20; j >= 0; j--) {
      if (ht[st[b][j]] >= ht[lca]) {
        mb = max(mb, vt[b][j]);
        b = st[b][j];
      }
    }
    cout << max(ma, mb) << "\n";
  }
  return 0;
}
