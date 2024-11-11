#include <bits/stdc++.h>
using namespace std;
const int Maxn = 100 * 1000 + 10;
long long n, m, k, d[Maxn], ans;
vector<int> adj[Maxn], wei[Maxn];
vector<pair<int, int> > rut;
set<pair<long long, int> > mys;
bool mark[Maxn];
int main() {
  cin >> n >> m >> k;
  int u, v, w;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    wei[u].push_back(w);
    wei[v].push_back(w);
  }
  for (int i = 0; i < k; i++) {
    scanf("%d%d", &u, &w);
    u--;
    rut.push_back(make_pair(u, w));
  }
  for (int i = 1; i < n; i++) {
    d[i] = LLONG_MAX;
    mys.insert(make_pair(d[i], i));
  }
  for (int i = 0; i < (int)adj[0].size(); i++) {
    if (d[adj[0][i]] > wei[0][i]) {
      mys.erase(make_pair(d[adj[0][i]], adj[0][i]));
      d[adj[0][i]] = wei[0][i];
      mys.insert(make_pair(d[adj[0][i]], adj[0][i]));
    }
  }
  for (int i = 0; i < k; i++) {
    if (d[rut[i].first] > rut[i].second) {
      mys.erase(make_pair(d[rut[i].first], rut[i].first));
      d[rut[i].first] = rut[i].second;
      mys.insert(make_pair(d[rut[i].first], rut[i].first));
      if (!mark[rut[i].first]) {
        mark[rut[i].first] = true;
        ans++;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    pair<long long, int> p = *mys.begin();
    if (p.first == LLONG_MAX) break;
    v = p.second;
    mys.erase(p);
    for (int j = 0; j < (int)adj[v].size(); j++) {
      if (d[v] + (long long)wei[v][j] <= d[adj[v][j]]) {
        mys.erase(make_pair(d[adj[v][j]], adj[v][j]));
        d[adj[v][j]] = d[v] + (long long)wei[v][j];
        mys.insert(make_pair(d[adj[v][j]], adj[v][j]));
        if (mark[adj[v][j]]) {
          ans--;
          mark[adj[v][j]] = false;
        }
      }
    }
  }
  cout << k - ans << endl;
  return 0;
}
