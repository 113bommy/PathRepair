#include <bits/stdc++.h>
using namespace std;
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int n, indeg[205], outdeg[205];
multiset<int> adj[205];
vector<pair<int, int> > edges;
vector<int> current, odd_degs;
bool done[205], odd_deg_vertex[205];
multiset<pair<int, int> > extras;
void dfs(int v) {
  done[v] = true;
  current.push_back(v);
  for (auto vv : adj[v])
    if (!done[vv]) dfs(vv);
}
void hierholzer(int v) {
  while (!adj[v].empty()) {
    int vv = *(adj[v].begin());
    adj[v].erase(adj[v].begin());
    adj[vv].erase(adj[vv].find(v));
    if (extras.find({v, vv}) == extras.end()) {
      outdeg[v]++;
      indeg[vv]++;
      edges.push_back({v, vv});
    } else {
      extras.erase({v, vv});
      extras.erase({vv, v});
    }
    hierholzer(vv);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    int e;
    cin >> n >> e;
    edges.clear();
    extras.clear();
    for (int i = 1; i <= n; i++) {
      indeg[i] = outdeg[i] = 0;
      done[i] = false;
      odd_deg_vertex[i] = false;
      adj[i].clear();
    }
    while (e--) {
      int a, b;
      cin >> a >> b;
      adj[a].insert(b);
      adj[b].insert(a);
    }
    for (int i = 1; i <= n; i++) {
      if (!done[i]) {
        dfs(i);
        for (auto v : current)
          if ((int)adj[v].size() % 2 == 1) {
            odd_deg_vertex[v] = true;
            odd_degs.push_back(v);
          }
        for (int i = 0; i < (int)odd_degs.size() - 1; i++) {
          adj[odd_degs[i]].insert(odd_degs[i + 1]);
          adj[odd_degs[i + 1]].insert(odd_degs[i]);
          extras.insert({odd_degs[i], odd_degs[i + 1]});
          extras.insert({odd_degs[i + 1], odd_degs[i]});
        }
        hierholzer(i);
        current.clear();
        odd_degs.clear();
      }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
      if (!odd_deg_vertex[i]) ans += (indeg[i] == outdeg[i]);
    cout << ans << endl;
    for (auto e : edges) cout << e.first << " " << e.second << endl;
  }
  return 0;
}
