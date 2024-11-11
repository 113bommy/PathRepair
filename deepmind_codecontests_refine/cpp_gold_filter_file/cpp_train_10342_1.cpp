#include <bits/stdc++.h>
using namespace std;
long long par[2000];
long long sz[2000];
void make_set() {
  for (long long i = 0; i < 2000; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}
long long find_set(long long a) {
  if (par[a] == a) return a;
  return find_set(par[a]);
}
void union_set(long long a, long long b) {
  a = find_set(a);
  b = find_set(b);
  par[b] = a;
  sz[a] += sz[b];
}
int main() {
  long long n;
  cin >> n;
  make_set();
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long m;
  cin >> m;
  vector<vector<pair<long long, long long>>> adj(n);
  for (long long i = 0; i < m; i++) {
    long long x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    adj[x].push_back(make_pair(y, w));
  }
  priority_queue<pair<long long, pair<long long, long long>>,
                 vector<pair<long long, pair<long long, long long>>>,
                 greater<pair<long long, pair<long long, long long>>>>
      q;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < adj[i].size(); j++) {
      q.push(make_pair(adj[i][j].second, make_pair(i, adj[i][j].first)));
    }
  }
  long long cost = 0;
  while (!q.empty()) {
    pair<long long, pair<long long, long long>> p = q.top();
    q.pop();
    long long w = p.first;
    long long x = p.second.first;
    long long y = p.second.second;
    if (par[y] == y && find_set(x) != find_set(y)) {
      union_set(x, y);
      cost += w;
    }
  }
  long long cnt = 0;
  for (long long i = 0; i < n; i++) {
    if (par[i] == i) cnt++;
  }
  if (cnt > 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << cost << endl;
}
