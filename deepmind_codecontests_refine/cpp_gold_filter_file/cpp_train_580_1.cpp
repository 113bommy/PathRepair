#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = double;
ll mod = 1000000007;
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
  cin >> mod;
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      a[i] = (a[i - 1] + a[i]) % mod;
    } else
      a[i] %= mod;
  }
  ll P = a[n - 1];
  ll g = gcd(P, mod);
  P /= g;
  mod /= g;
  map<int, vector<ll>> kek;
  for (int i = 0; i < n; i++) {
    kek[a[i] % g].push_back(i);
  }
  ll phi = 1;
  ll lft = mod;
  for (ll j = 2; j * j <= lft; j++) {
    if (lft % j == 0) {
      lft /= j;
      phi *= (j - 1);
      while (lft % j == 0) {
        phi *= j;
        lft /= j;
      }
    }
  }
  if (lft > 1) phi *= lft - 1;
  ll P1 = pew(P, phi - 1);
  vector<ll> ans(n);
  for (auto lul : kek) {
    vector<ll> cur = lul.second;
    int sz = cur.size();
    vector<ll> x(sz);
    vector<pair<ll, ll>> x1(sz);
    for (int i = 0; i < sz; i++) {
      x[i] = a[cur[i]] / g;
      x1[i].first = x[i] * P1 % mod;
      x1[i].second = -i;
    }
    sort(x1.begin(), x1.end());
    for (int i = 0; i < sz; i++) {
      int p = -x1[i].second;
      if (i + 1 < sz)
        ans[cur[p]] = x1[i + 1].first - x1[i].first;
      else
        ans[cur[p]] = x1[0].first - x1[i].first + mod;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
}
