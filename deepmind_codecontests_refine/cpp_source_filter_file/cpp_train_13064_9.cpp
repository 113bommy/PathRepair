#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = double;
const ll mod = 1000000007;
ll gcd(ll a, ll b) {
  if (a == 0 or b == 0) return a + b;
  return gcd(b, a % b);
}
ll sum(ll a, ll b) {
  a += b;
  a %= mod;
  return a;
}
ll sub(ll a, ll b) {
  a += mod - b;
  a %= mod;
  return a;
}
inline ll mul(ll a, ll b) {
  if (a * b < mod) return a * b;
  return a * b % mod;
}
inline ll pew(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
int parent[600001];
int rnk[600001];
void make_set(int v) {
  parent[v] = v;
  rnk[v] = 0;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (rnk[a] < rnk[b]) swap(a, b);
    parent[b] = a;
    if (rnk[a] == rnk[b]) ++rnk[a];
  }
}
vector<vector<ll>> g;
vector<ll> d, sz4, sz3;
int k4 = 0, ok = 1, k3 = 0;
void dfs(int u, int p) {
  int S4 = k4;
  int S3 = k3;
  sz4[u] = 0;
  sz3[u] = 0;
  if (d[u] >= 4) {
    S4--;
    sz4[u]++;
  }
  if (d[u] == 3) {
    S3--;
    sz3[u]++;
  }
  int cur = 0;
  for (int v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
    S4 -= sz4[v];
    S3 -= sz3[v];
    sz4[u] += sz4[v];
    sz3[u] += sz3[v];
    if (sz4[v] > 0) {
      cur++;
      continue;
    }
    int L = sz3[v];
    if (d[v] == 3) L--;
    if (L > 0) cur++;
  }
  if (S4 != 0) {
    cur++;
  } else {
    if (u != 0) {
      int L = sz3[p];
      if (d[p] == 3) L--;
      if (L > 0) cur++;
    }
  }
  if (cur > 2) {
    ok = 0;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  g.resize(n);
  d.resize(n);
  sz3.resize(n);
  sz4.resize(n);
  for (int i = 1; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    a--, b--;
    g[a].push_back(b);
    g[b].push_back(a);
    d[a]++, d[b]++;
  }
  for (int i = 0; i < n; i++) {
    if (d[i] >= 4) k4++;
    if (d[i] == 3) k3++;
  }
  dfs(0, -1);
  if (ok == 1)
    cout << "Yes\n";
  else
    cout << "No\n";
}
