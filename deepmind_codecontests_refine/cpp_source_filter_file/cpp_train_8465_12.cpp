#include <bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 10;
const long long base = 727;
vector<long long> adj[maxN];
vector<pair<long long, long long> > edge;
long long pw[maxN];
long long h[maxN];
map<long long, long long> cnt;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  pw[0] = 1;
  for (long long i = 1; i < maxN; i++) pw[i] = pw[i - 1] * 727;
  long long n, m;
  cin >> n >> m;
  for (long long i = 0; i < m; i++) {
    long long v, u;
    cin >> v >> u;
    v--, u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
    edge.push_back(make_pair(v, u));
    h[v] += pw[u];
    h[u] += pw[v];
  }
  for (long long i = 0; i < n; i++) cnt[h[i]]++;
  long long res = 0;
  for (map<long long, long long>::iterator it = cnt.begin(); it != cnt.end();
       it++) {
    long long x = it->second;
    res += ((x * (x - 1)) >> 1);
  }
  for (long long i = 0; i < n; i++) h[i] += pw[i];
  for (long long i = 0; i < edge.size(); i++) {
    long long v = edge[i].first, u = edge[i].first;
    if (h[v] == h[u]) res++;
  }
  cout << res << endl;
  return 0;
}
