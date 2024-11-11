#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
const int inf = 2000000000;
const int mod = 1007050321;
const bool aut = 788480;
const int base = 521;
const int N = 1000005;
const long double e = 0.000001;
mt19937_64 random_num(
    chrono::high_resolution_clock::now().time_since_epoch().count());
int n, m;
long long a[N], h[N];
vector<int> adj[N];
map<int, int> dem;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) a[i] = random_num();
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
    h[u] += a[v];
    h[v] += a[u];
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dem[h[i]], dem[h[i]]++;
    for (int v : adj[i])
      if (v < i && h[v] + a[v] == h[i] + a[i]) ans++;
  }
  printf("%lld", ans);
  return 0;
}
