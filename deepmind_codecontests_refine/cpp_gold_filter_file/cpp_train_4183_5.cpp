#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
vector<vector<int>> adjlist;
vector<int> pairs, dist;
bool bfs(int n) {
  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (pairs[i] < 0) {
      dist[i] = 0;
      q.push(i);
    } else
      dist[i] = -1;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : adjlist[u]) {
      if (pairs[v] < 0) return true;
      if (dist[pairs[v]] < 0) {
        dist[pairs[v]] = dist[u] + 1;
        q.push(pairs[v]);
      }
    }
  }
  return false;
}
bool dfs(int u) {
  for (int v : adjlist[u]) {
    if (pairs[v] < 0 || (dist[pairs[v]] > dist[u] && dfs(pairs[v]))) {
      pairs[v] = u;
      pairs[u] = v;
      return true;
    }
  }
  dist[u] = -1;
  return false;
}
int hopcroft_karp(int n) {
  int ans = 0;
  pairs.assign((int)(adjlist).size(), -1);
  dist.resize(n);
  for (int i = 0; i < n; ++i)
    for (int w : adjlist[i])
      if (pairs[w] < 0) {
        pairs[i] = w;
        pairs[w] = i;
        ++ans;
        break;
      }
  while (bfs(n))
    for (int i = 0; i < n; ++i)
      if (pairs[i] < 0) ans += dfs(i);
  return ans;
}
ll adj[107][107];
struct base {
  int x;
  ll d;
};
struct ship {
  int x;
  ll a, f;
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      if (i != j) adj[i][j] = 100000000000000;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  for (int k = 0; k < n; ++k)
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
      }
  int s, b;
  ll k, h;
  cin >> s >> b >> k >> h;
  vector<base> bases;
  vector<ship> ships;
  for (int i = 0; i < s; ++i) {
    int x;
    ll a, f;
    cin >> x >> a >> f;
    --x;
    ships.push_back(ship{x, a, f});
  }
  for (int i = 0; i < b; ++i) {
    int x;
    ll d;
    cin >> x >> d;
    --x;
    bases.push_back(base{x, d});
  }
  adjlist = vector<vector<int>>(s + b);
  dist = vector<int>(s + b);
  pairs = vector<int>(s + b);
  for (int i = 0; i < s; ++i)
    for (int j = 0; j < b; ++j) {
      if (adj[ships[i].x][bases[j].x] <= ships[i].f &&
          ships[i].a >= bases[j].d) {
        adjlist[i].push_back(j + s);
        adjlist[j + s].push_back(i);
      }
    }
  int canAttack = hopcroft_karp(s);
  ll best = 1000000000000000000;
  for (int dummy = 0; dummy < s + 1; ++dummy) {
    ll cost = dummy * h;
    int freeShips = s - dummy;
    cost += min(canAttack, freeShips) * k;
    best = min(best, cost);
  }
  cout << best << endl;
}
