#include <bits/stdc++.h>
using namespace std;
struct node {
  long long int cost, ui;
};
vector<long long int> adj[1000009];
priority_queue<node> pq;
long long int dis[1000009], p[1000009];
map<pair<long long int, long long int>, long long int> mp;
bool cmp(long long int a, long long int b) { return a > b; }
bool operator<(node A, node B) { return A.cost > B.cost; }
void dij(long long int src, long long int des) {
  pq.push({0, src});
  for (long long int i = 1; i < des + 1; i++) dis[i] = (long long int)1e7 + 7;
  dis[src] = 0;
  while (!pq.empty()) {
    node t = pq.top();
    pq.pop();
    long long int u = t.ui;
    for (long long int i = 0; i < adj[u].size(); i++) {
      long long int v = adj[u][i];
      if (dis[u] + mp[{u, v}] < dis[v]) {
        dis[v] = dis[u] + mp[{u, v}];
        pq.push({dis[v], v});
        p[v] = u;
      }
    }
  }
  if (dis[des] == (long long int)1e7 + 7)
    cout << "-1";
  else {
    vector<long long int> path;
    path.push_back(des);
    long long int k = des;
    while (k != src) {
      k = p[k];
      path.push_back(k);
    }
    reverse(path.begin(), path.end());
    for (long long int i = 0; i < path.size(); i++) cout << path[i] << " ";
  }
}
void solve() {
  long long int n, m;
  cin >> n >> m;
  while (m--) {
    long long int a, b, c;
    cin >> a >> b >> c;
    if (a != b) {
      if (mp[{a, b}] || mp[{b, a}]) {
        mp[{a, b}] = min(mp[{a, b}], c);
        mp[{b, a}] = min(mp[{b, a}], c);
      } else {
        adj[a].push_back(b);
        adj[b].push_back(a);
        mp[{a, b}] = c;
        mp[{b, a}] = c;
      }
    }
  }
  dij(1, n);
}
int main() { solve(); }
