#include <bits/stdc++.h>
using namespace std;
int mpow(int base, int exp);
void ipgraph(int m);
void dfs(int u, int par);
const long long mod = 1000000007 * 1000000007;
const int N = 1e6 + 3, M = N;
vector<int> g[N];
int a[N];
long long h[N], val[N];
vector<pair<int, int> > E;
long long r() { return rand() * 32000 + rand(); }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, n, k, j, m;
  cin >> n >> m;
  srand(1234);
  for (i = 1; 1 < n + 1 ? i < n + 1 : i > n + 1; 1 < n + 1 ? i += 1 : i -= 1)
    h[i] = (r() * r() + r() + r()) % mod;
  ipgraph(m);
  long long ans = 0;
  for (pair<int, int> e : E) {
    int u = e.first, v = e.second;
    val[u] = (val[u] + mod - h[v]) % mod;
    val[v] = (val[v] + mod - h[u]) % mod;
    ans += val[u] == val[v];
    val[u] = (val[u] + h[v]) % mod;
    val[v] = (val[v] + h[u]) % mod;
  }
  vector<long long> fin;
  for (i = 1; 1 < n + 1 ? i < n + 1 : i > n + 1; 1 < n + 1 ? i += 1 : i -= 1)
    fin.push_back(val[i]);
  sort(fin.begin(), fin.end());
  long long c = 1;
  for (i = 1; 1 < fin.size() ? i < fin.size() : i > fin.size();
       1 < fin.size() ? i += 1 : i -= 1) {
    if (fin[i] == fin[i - 1])
      c++;
    else
      ans += c * (c - 1) / 2, c = 1;
  }
  ans += c * (c - 1) / 2;
  cout << ans << endl;
  return 0;
}
int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
void ipgraph(int m) {
  int i, u, v;
  for (i = 0; i < m; i++) {
    cin >> u >> v;
    val[u] = (val[u] + h[v]) % mod;
    val[v] = (h[u] + val[v]) % mod;
    E.push_back({u, v});
    u++, v++;
    g[u - 1].push_back(v - 1);
    g[v - 1].push_back(u - 1);
  }
}
void dfs(int u, int par) {
  for (int v : g[u]) {
    if (v == par) continue;
    dfs(v, u);
  }
}
