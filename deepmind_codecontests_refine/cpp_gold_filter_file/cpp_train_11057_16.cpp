#include <bits/stdc++.h>
using namespace std;
long long read() {
  int f = 1;
  long long res = 0;
  char ch;
  do {
    ch = getchar();
    if (ch == '-') f = -f;
  } while (ch < '0' || ch > '9');
  do {
    res = res * 10 + ch - '0';
    ch = getchar();
  } while (ch >= '0' && ch <= '9');
  return f == 1 ? res : -res;
}
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const int N = 400005;
const int mod = 998244353;
const long long INF = 1e18;
int n, m;
long long A[N], B[N];
char str[N];
int head[N], to[N * 2], nxt[N * 2], tot = 1, weight[N * 2];
void addEdge(int u, int v, int w = 1) {
  tot++;
  nxt[tot] = head[u];
  to[tot] = v;
  head[u] = tot;
  weight[tot] = w;
}
void initGraph() {
  for (int i = 0; i <= n; i++) head[i] = 0;
  tot = 1;
}
int countOne(long long set) {
  int res = 0;
  while (set) {
    res++;
    set &= set - 1;
  }
  return res;
}
bool contain(long long set, int i) { return (set & (1LL << i)) > 0; }
long long myPow(long long a, long long p) {
  if (p == 0) return 1;
  long long res = myPow(a, p / 2);
  res *= res;
  res %= mod;
  if (p % 2 == 1) {
    res *= a;
    res %= mod;
  }
  return res % mod;
}
void addMode(long long &a, long long b) {
  a = (a + b) % mod;
  if (a < 0) a += mod;
}
long long mul(long long a, long long b) {
  long long res = a % mod * (b % mod) % mod;
  if (res < 0) res += mod;
  return res;
}
vector<int> sz;
vector<vector<pair<int, int>>> graph;
long long res[2];
void dfsz(int u, int f) {
  sz[u] = 1;
  for (pair<int, int> v : graph[u]) {
    if (v.first == f) continue;
    dfsz(v.first, u);
    sz[u] += sz[v.first];
  }
  for (pair<int, int> v : graph[u]) {
    if (v.first == f) continue;
    int part = n * 2 - sz[v.first];
    res[1] += 1LL * min(sz[v.first], part) * v.second;
    if (part & 1) {
      res[0] += v.second;
    }
  }
}
void solve() {
  cin >> n;
  graph.clear();
  graph.resize(n * 2);
  sz.clear();
  sz.resize(n * 2);
  res[0] = res[1] = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    graph[v].push_back(make_pair(u, w));
    graph[u].push_back(make_pair(v, w));
  }
  dfsz(0, -1);
  cout << res[0] << " " << res[1] << endl;
}
int main() {
  fast_io();
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    solve();
  }
  return 0;
}
