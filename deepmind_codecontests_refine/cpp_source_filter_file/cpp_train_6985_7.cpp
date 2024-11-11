#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T, typename U>
static void amin(T& x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static void amax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T>
void sout(T& w) {
  for (auto x : w) cout << x << ", ";
  cout << endl;
}
int i, j;
int q = 1e9 + 7;
inline int power(int a, long long b) {
  if (!b) return 1;
  int c = power(a, b >> 1);
  c = (long long)c * c % q;
  if (b & 1) c = (long long)c * a % q;
  return c;
}
int n, m, k;
vector<long long> c;
vector<vector<int> > chs;
vector<int> vis;
void dfs(int rt) {
  vis[rt] = 1;
  for (int ch : chs[rt])
    if (!vis[ch]) dfs(ch);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  c = vector<long long>(n);
  for (int i = 0; i < (int)(n); ++i) cin >> c[i];
  chs = vector<vector<int> >(n, vector<int>());
  vis = vector<int>(n);
  map<long long, vector<pair<int, int> > > graphs;
  for (int i = 0; i < (int)(m); ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    long long x = c[u] ^ c[v];
    graphs[x].push_back(pair<int, int>(u, v));
  }
  long long ans = 0;
  for (auto& g : graphs) {
    long long x = g.first;
    vector<pair<int, int> >& edges = g.second;
    set<int> nodes;
    for (pair<int, int>& edge : edges) {
      chs[edge.first].push_back(edge.second);
      chs[edge.second].push_back(edge.first);
      nodes.insert(edge.first);
      nodes.insert(edge.second);
    }
    int components = 0;
    for (int node : nodes)
      if (!vis[node]) {
        components++;
        dfs(node);
      }
    for (int node : nodes) {
      chs[node].clear();
      vis[node] = 0;
    }
    int rest = n - nodes.size();
    ans += (long long)power(2, components) * power(2, rest) % q;
  }
  long long number_free_xes = (1LL << k) - graphs.size();
  ans += number_free_xes * power(2, n) % q;
  ans %= q;
  cout << ans << endl;
}
