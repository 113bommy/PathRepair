#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int b, long long int mod) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
  return pw(a * a % mod, b / 2, mod) % mod;
}
const long long int MAXN = 1e5 + 10;
const long long int MAXK = 1e4 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int h, n, m, k, dist[MAXK], mark[MAXK], seen[MAXN];
pair<long long int, long long int> A[MAXN];
vector<pair<long long int, long long int>> adj[MAXK];
set<pair<long long int, long long int>> st;
priority_queue<pair<long long int, long long int>,
               vector<pair<long long int, long long int>>,
               greater<pair<long long int, long long int>>>
    pq;
void Dijk() {
  fill(dist, dist + MAXK, INF);
  fill(mark, mark + MAXK, 0);
  dist[0] = 0;
  pq.push({0, 0});
  while (!pq.empty()) {
    long long int u = pq.top().second;
    pq.pop();
    if (mark[u]) continue;
    mark[u] = 1;
    for (pair<long long int, long long int>& e : adj[u]) {
      if (dist[e.first] <= dist[u] + e.second) continue;
      dist[e.first] = dist[u] + e.second;
      pq.push({dist[e.first], e.first});
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> h >> n >> m >> k;
  for (long long int i = 1; i <= n; i++) {
    cin >> A[i].first >> A[i].second;
    A[i].first--;
    if (A[i].first % k == 0) {
      st.insert({A[i].second, -i});
      seen[i] = 1;
    }
  }
  Dijk();
  while (m--) {
    long long int type;
    cin >> type;
    if (type == 1) {
      long long int x;
      cin >> x;
      for (long long int i = 0; i < k; i++) {
        adj[i].push_back({(i + x) % k, x});
      }
      Dijk();
      for (long long int i = 1; i <= n; i++) {
        if (!seen[i] && dist[A[i].first % k] <= A[i].first) {
          seen[i] = 1;
          st.insert({A[i].second, -i});
        }
      }
    }
    if (type == 2) {
      long long int x, val;
      cin >> x >> val;
      if (seen[x]) st.erase({A[x].second, -x});
      A[x].second -= val;
      if (seen[x]) st.insert({A[x].second, -x});
    }
    if (type == 3) {
      if (st.empty()) {
        cout << 0 << '\n';
        continue;
      }
      auto it = st.end();
      it--;
      cout << (*it).first << '\n';
      st.erase(it);
    }
  }
  return 0;
}
