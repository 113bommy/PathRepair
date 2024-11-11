#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
int mul(int a, int b) { return 1ll * a * b % mod; }
vector<pair<int, int> > g[N];
vector<int> T[N];
vector<int> f[N];
vector<int> s[N];
int Fuck[N];
void dfs(int u, int p) {
  for (int i = 0; i < (int)g[u].size(); ++i)
    if (g[u][i].first == p) {
      g[u].erase(g[u].begin() + i);
      break;
    }
  sort(g[u].begin(), g[u].end());
  for (pair<int, int> e : g[u]) T[u].emplace_back(e.first);
  T[u].emplace_back(N);
  f[u].resize(T[u].size());
  s[u].resize(T[u].size());
  int Mul = 1;
  Fuck[u] = 1;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i].second;
    int t = g[u][i].first;
    dfs(v, t);
    int j = lower_bound(T[v].begin(), T[v].end(), t) - T[v].begin();
    f[u][i] = mul(Mul, s[v].back() - (j > 0 ? s[v][j - 1] : 0) + mod);
    Mul = mul(Mul, Fuck[v] + (j > 0 ? s[v][j - 1] : 0));
    if (t < p) Fuck[u] = mul(Fuck[u], Fuck[v] + (j > 0 ? s[v][j - 1] : 0));
    if (t > p) Fuck[u] = mul(Fuck[u], s[v].back());
  }
  f[u].back() = Mul;
  Mul = 1;
  for (int i = (int)g[u].size() - 1; i >= 0; --i) {
    int v = g[u][i].second;
    f[u][i] = mul(Mul, f[u][i]);
    Mul = mul(Mul, s[v].back());
  }
  for (int i = 0; i < (int)T[u].size(); ++i) {
    if (i) s[u][i] = s[u][i - 1];
    add(s[u][i], f[u][i]);
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int x;
    cin >> x;
    int y;
    cin >> y;
    g[x].emplace_back(i, y);
    g[y].emplace_back(i, x);
  }
  dfs(1, 0);
  cout << s[1].back() << endl;
}
