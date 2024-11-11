#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = long double;
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
  vector<ll> a(n);
  ll mx = 200000;
  vector<ll> R(mx + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        R[j] = i;
        R[a[i] / j] = i;
      }
    }
  }
  set<pair<ll, ll>> kek;
  vector<ll> c(mx + 1);
  ll val = 0;
  ll ans = 0;
  kek.insert({n, 0});
  for (int i = n - 1; i >= 0; i--) {
    ll M = 0;
    for (ll j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        c[a[i] / j]++;
        if (c[a[i] / j] >= 2) M = max(M, a[i] / j);
        if (j * j != a[i]) {
          c[j]++;
          if (c[j] >= 2) M = max(M, j);
        }
      }
    }
    ll V = kek.begin()->second;
    if (M <= V) {
      val += V;
      continue;
    }
    kek.insert({i, M});
    val += M;
  }
  c.clear();
  c.resize(mx + 1);
  ll M = 0;
  for (int i = 0; i < n; i++) {
    val -= kek.begin()->second;
    while (kek.begin()->first <= i) kek.erase(kek.begin());
    ans += val;
    if (i + 1 == n) break;
    vector<ll> d;
    ll S = M;
    for (int j = 1; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        d.push_back(a[i] / j);
        if (a[i] != j * j) d.push_back(j);
      }
    }
    for (ll x : d) {
      c[x]++;
      if (c[x] >= 2) M = max(M, x);
      ll p = R[x];
      if (p <= i) continue;
      auto it = kek.lower_bound({p, 0});
      if (it != kek.end() and it->second >= x) continue;
      it = kek.lower_bound({p + 1, 0});
      ll prv = it->second;
      ll z = i;
      if (it != kek.begin()) {
        it--;
        z = max(z, it->first);
      }
      val -= (p - z) * prv;
      it = kek.lower_bound({p + 1, 0});
      while (it != kek.begin()) {
        it--;
        if (it->second <= x) {
          z = i;
          if (it != kek.begin()) {
            it--;
            z = max(z, it->first);
            it++;
          }
          val -= (it->first - z) * (it->second);
          kek.erase(it);
          it = kek.lower_bound({p + 1, 0});
        } else
          break;
      }
      it = kek.lower_bound({p, 0});
      z = i;
      if (it != kek.begin()) {
        it--;
        z = max(z, it->first);
      }
      val += (p - z) * x;
      kek.insert({p, x});
    }
    if (S == M) continue;
    auto it = kek.lower_bound({n, 0});
    ll z = i;
    if (it != kek.begin()) {
      it--;
      z = max(z, it->first);
      it++;
    }
    val -= (n - z) * S;
    kek.erase(it);
    it = kek.lower_bound({n, 0});
    while (it != kek.begin()) {
      it--;
      if (it->second <= M) {
        z = i;
        if (it != kek.begin()) {
          it--;
          z = max(z, it->first);
          it++;
        }
        val -= (it->first - z) * (it->second);
        kek.erase(it);
        it = kek.lower_bound({n, 0});
      } else
        break;
    }
    it = kek.lower_bound({n, 0});
    z = i;
    if (it != kek.begin()) {
      it--;
      z = max(z, it->first);
    }
    val += (n - z) * M;
    kek.insert({n, M});
  }
  cout << ans << endl;
}
