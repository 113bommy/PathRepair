#include <bits/stdc++.h>
using namespace std;
int n, m, src, des, x, y;
long long w;
vector<pair<int, long long> > adj[1000];
long long dist[1000][1000];
long long t[1000], c[1000];
bool vis[1000];
struct nodo1 {
  int ind;
  long long w;
  nodo1(){};
  nodo1(int _ind, int _w) {
    ind = _ind;
    w = _w;
  }
};
bool operator<(nodo1 p, nodo1 q) { return p.w > q.w; }
priority_queue<nodo1> Q;
int main() {
  while (cin >> n >> m >> src >> des) {
    src--;
    des--;
    for (int i = 0; i < m; ++i) {
      cin >> x >> y >> w;
      x--;
      y--;
      adj[x].push_back(make_pair(y, w));
      adj[y].push_back(make_pair(x, w));
    }
    for (int i = 0; i < n; ++i) cin >> t[i] >> c[i];
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; ++i) {
      Q.push(nodo1(i, 0));
      while (!Q.empty()) {
        nodo1 nodo = Q.top();
        Q.pop();
        int ind = nodo.ind;
        long long w = nodo.w;
        if (dist[i][ind] != -1) continue;
        dist[i][ind] = w;
        int nv = adj[ind].size();
        for (int k = 0; k < nv; ++k) {
          int nind = adj[ind][k].first;
          long long nw = adj[ind][k].second;
          if (dist[i][nind] == -1) Q.push(nodo1(nind, w + nw));
        }
      }
    }
    memset(vis, 0, sizeof(vis));
    bool ok = 0;
    Q.push(nodo1(src, 0));
    while (!Q.empty()) {
      nodo1 nodo = Q.top();
      Q.pop();
      int ind = nodo.ind;
      long long w = nodo.w;
      if (vis[ind]) continue;
      if (ind == des) {
        cout << w << endl;
        ok = 1;
        break;
      }
      vis[ind] = 1;
      for (int k = 0; k < n; k++)
        if (!vis[k] && dist[ind][k] != -1 && dist[ind][k] <= t[ind])
          Q.push(nodo1(k, w + c[ind]));
    }
    if (!ok) cout << -1 << endl;
  }
}
