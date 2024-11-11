#include <bits/stdc++.h>
using namespace std;
long long modpow(long long a, long long b,
                 long long mod = (long long)(1e9 + 7)) {
  if (!b) return 1;
  a %= mod;
  return modpow(a * a % mod, b / 2, mod) * (b & 1 ? a : 1) % mod;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e5;
int n;
int subsz[maxn];
long double dp[maxn];
long long wsum[maxn];
vector<int> adj[maxn];
int a[maxn], b[maxn], wi[maxn];
int dfs(int v, int p) {
  subsz[v] = 1;
  wsum[v] = 0;
  vector<int> edges;
  for (int e : adj[v]) {
    int w = a[e] ^ b[e] ^ v;
    if (w != p) {
      subsz[v] += dfs(w, v);
      wsum[w] += 2 * wi[e];
      wsum[v] += wsum[w];
      edges.push_back(e);
    }
  }
  auto cmp = [&](int e1, int e2) {
    int x = a[e1] ^ b[e1] ^ v, y = a[e2] ^ b[e2] ^ v;
    return wsum[x] * subsz[y] < wsum[y] * subsz[x];
  };
  sort(edges.begin(), edges.end(), cmp);
  dp[v] = 0;
  long double temp = 0;
  for (int e : edges) {
    int w = a[e] ^ b[e] ^ v;
    dp[v] += subsz[w] * (dp[w] + wi[e] + temp);
    temp += wsum[w];
  }
  if (subsz[v] > 1) dp[v] /= subsz[v] - (v == 0);
  return subsz[v];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  for (int _ = 0; _ < t; _++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) adj[i].clear();
    for (int i = 0; i < n - 1; i++) {
      scanf("%d", &a[i]);
      scanf("%d", &b[i]);
      scanf("%d", &wi[i]);
      a[i]--;
      b[i]--;
      adj[a[i]].push_back(i);
      adj[b[i]].push_back(i);
    }
    dfs(0, -1);
    cout << setprecision(18) << dp[0] << endl;
  }
  return 0;
}
