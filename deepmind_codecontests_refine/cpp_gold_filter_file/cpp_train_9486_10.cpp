#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long vpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  if (b == 1) return a;
  long long temp = vpow(a, b / 2, p);
  temp *= temp;
  temp %= p;
  if (b % 2 == 0) return temp;
  temp = temp * a;
  temp %= p;
  return temp;
}
long long inverseMod(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long temp = vpow(b, p - 2, p);
  long long ans = temp * a;
  ans %= p;
  return ans;
}
struct per {
  long long v, w, i;
};
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  vector<per> adj[n];
  for (__typeof((m)) i = (0); i < (m); i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    per temp;
    temp.v = v;
    temp.w = w;
    temp.i = i;
    adj[u].push_back(temp);
    temp.v = u;
    adj[v].push_back(temp);
  }
  set<pair<long long, long long> > pq;
  vector<long long> dist(n, 1e15);
  dist[0] = 0;
  pq.insert({0, 0});
  vector<long long> par(n, -1);
  set<long long> ans;
  while (!pq.empty() && (long long)(long long)ans.size() < k) {
    pair<long long, long long> temp = *pq.begin();
    pq.erase(pq.begin());
    if (par[temp.second] != -1) ans.insert(par[temp.second]);
    long long u = temp.second;
    for (auto child : adj[temp.second]) {
      long long v = child.v;
      long long w = child.w;
      long long i = child.i;
      if (dist[v] > dist[u] + w) {
        if (pq.find({dist[v], v}) != pq.end()) pq.erase(pq.find({dist[v], v}));
        dist[v] = dist[u] + w;
        par[v] = i;
        pq.insert({dist[v], v});
      }
    }
  }
  cout << (long long)ans.size() << endl;
  for (auto it : ans) {
    cout << it + 1 << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cout << fixed << setprecision(12);
  while (t--) solve();
  return 0;
}
