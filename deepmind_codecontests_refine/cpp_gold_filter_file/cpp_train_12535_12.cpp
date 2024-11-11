#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long int pw(long long int a, long long int b, long long int mod) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
  return pw(a * a % mod, b / 2, mod) % mod;
}
const long long int MAXN = 2e4 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
struct edge {
  long long int u, v, w, L, R;
};
long long int n, m, k, cost, s[2], f, dist[2][MAXN], mark[MAXN];
edge E[MAXN];
vector<long long int> adj[MAXN];
priority_queue<pair<long long int, long long int>,
               vector<pair<long long int, long long int>>,
               greater<pair<long long int, long long int>>>
    pq;
void Dijk(long long int ind) {
  fill(mark, mark + MAXN, 0);
  fill(dist[ind], dist[ind] + MAXN, INF);
  dist[ind][s[ind]] = 0;
  pq.push({0, s[ind]});
  while (!pq.empty()) {
    long long int u = pq.top().second;
    pq.pop();
    if (mark[u]) continue;
    mark[u] = 1;
    for (long long int i : adj[u]) {
      long long int v = E[i].v, w = E[i].w;
      if (dist[ind][v] <= dist[ind][u] + w) continue;
      dist[ind][v] = dist[ind][u] + w;
      pq.push({dist[ind][v], v});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> m >> k >> s[0] >> s[1] >> f;
  for (long long int i = 0; i < m; i++) {
    cin >> E[i].u >> E[i].v >> E[i].w;
    adj[E[i].u].push_back(i);
  }
  for (long long int i = m; i < m + k; i++) {
    cin >> E[i].u >> E[i].v >> E[i].L >> E[i].R;
    E[i].w = E[i].R;
    adj[E[i].u].push_back(i);
  }
  for (long long int i = 0; i < k; i++) {
    Dijk(0);
    Dijk(1);
    for (long long int j = m; j < m + k; j++) {
      if (E[j].w != E[j].L && dist[0][E[j].u] < dist[1][E[j].u]) {
        E[j].w = E[j].L;
      }
    }
  }
  Dijk(0);
  Dijk(1);
  if (dist[0][f] > dist[1][f]) return cout << "LOSE" << '\n', 0;
  cout << (dist[0][f] == dist[1][f] ? "DRAW" : "WIN") << '\n';
  for (long long int i = m; i < m + k; i++) {
    cout << E[i].w << ' ';
  }
  cout << '\n';
  return 0;
}
