#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
using ll = int64_t;
const int N = 3010;
const int MOD = 1000000000 + 7;
int n;
int s[N];
int ways[N][N];
bool is_first[N][N];
bool good[1 << 4];
int sums[N];
void clear() {
  for (int i = 0; i < (1 << 4); i++) good[i] = true;
  good[0b1100] = false;
  good[0b1010] = false;
  good[0b0111] = false;
  good[0b1111] = false;
}
void add(int& a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
bool prime(ll x) {
  for (ll i = 2; i * i <= x; i++)
    if (x % i == 0) return false;
  return true;
}
ll random_bits(ll bits) {
  ll ans = 0;
  for (ll i = 0; i < bits; i++) {
    ans <<= 1;
    ans |= (rand() & 1);
  }
  return ans;
}
ll random_mod() {
  ll mod = random_bits(40);
  while (!prime(mod)) {
    ++mod;
  }
  return mod;
}
int main() {
  srand(__rdtsc());
  const ll P = 43;
  const ll HMOD = random_mod();
  clear();
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int l = 0; l < n; l++) {
    ways[l][l] = 1;
    for (int r = l + 1; r <= n; r++) {
      int letter = 0;
      for (int len = 1; len <= 4 && r - len >= l; len++) {
        letter <<= 1;
        letter |= s[r - len];
        if (len != 4 || good[letter]) {
          add(ways[l][r], ways[l][r - len]);
        }
      }
    }
  }
  vector<pair<ll, int>> hashes;
  hashes.reserve(n);
  for (int len = 1; len <= n; len++) {
    hashes.clear();
    ll hash = 0;
    ll m = 1;
    for (int i = 0; i < len; i++) {
      hash *= P;
      hash %= HMOD;
      hash += s[i];
      hash %= HMOD;
      m *= P;
      m %= HMOD;
    }
    hashes.push_back({hash, len});
    for (int i = len + 1; i <= n; i++) {
      hash *= P;
      hash -= m * s[i - len - 1];
      hash %= HMOD;
      if (hash < 0) hash += HMOD;
      hash += s[i - 1];
      hash %= HMOD;
      hashes.push_back({hash, i});
    }
    sort(hashes.begin(), hashes.end());
    ll previous = -1;
    for (auto p : hashes) {
      assert(p.first >= 0 && p.first < HMOD);
      if (p.first != previous) {
        is_first[p.second - len][p.second] = true;
      }
      previous = p.first;
    }
  }
  for (int l = 0; l < n; l++) {
    for (int r = 1; r <= n; r++) {
      if (is_first[l][r]) {
        add(sums[r], ways[l][r]);
      }
    }
  }
  for (int len = 2; len <= n; len++) {
    add(sums[len], sums[len - 1]);
  }
  for (int len = 1; len <= n; len++) {
    cout << sums[len] << "\n";
  }
  return 0;
}
