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
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  map<ll, ll> kek;
  vector<ll> p(10);
  p[0] = 1;
  for (int i = 1; i <= 9; i++) {
    p[i] = p[i - 1] * 11;
  }
  vector<ll> a(n);
  vector<vector<ll>> g(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; j++) {
      a[i] += (s[j] - '0' + 1) * p[j];
    }
    vector<ll> cur;
    for (int x = 0; x < 9; x++) {
      for (int y = x + 1; y <= 9; y++) {
        cur.push_back(a[i] % p[y] / p[x]);
      }
    }
    sort(cur.begin(), cur.end());
    for (int j = 0; j < cur.size(); j++) {
      if (j + 1 < cur.size() and cur[j] == cur[j + 1]) continue;
      g[i].push_back(cur[j]);
      kek[cur[j]]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < g[i].size(); j++) {
      if (kek[g[i][j]] != 1) continue;
      ll v = g[i][j];
      while (v > 0) {
        cout << (char)((v % 11 - 1) + '0');
        v /= 11;
      }
      cout << "\n";
      break;
    }
  }
}
