#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
using ll = long long;
using ld = long double;
ll MOD = 998244353;
const ll root = 3;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0xc0c0c0c0c0c0c0c0;
const int mxN = 200001;
ll basis[36];
int sz = 0;
int n, m;
void insert(ll mask) {
  for (int i = (0); i < (m); ++i) {
    if ((mask & 1LL << i) == 0) continue;
    if (!basis[i]) {
      basis[i] = mask;
      sz++;
      return;
    }
    mask ^= basis[i];
  }
}
ll arr[mxN];
ll res[36];
ll p2[mxN];
int ord[36];
int ord2[36];
int dp[36][1 << 15];
void solve() {
  cin >> n >> m;
  for (int i = (0); i < (n); ++i) {
    cin >> arr[i];
    insert(arr[i]);
  }
  for (int i = (0); i < (m); ++i) {
    if (!basis[i]) continue;
    for (int j = (0); j < (m); ++j) {
      if (j == i) continue;
      if (basis[j] & (1 << i)) basis[j] ^= basis[i];
    }
  }
  memset(ord, -1, sizeof(ord));
  memset(ord2, -1, sizeof(ord2));
  int curr = 0;
  int curr2 = 0;
  for (int i = (0); i < (m); ++i) {
    if (basis[i])
      ord[i] = curr++;
    else
      ord2[i] = curr2++;
  }
  if (sz <= 20) {
    for (int i = (0); i < (1 << sz); ++i) {
      ll val = 0;
      for (int j = (0); j < (m); ++j) {
        if (ord[j] != -1 && (i & (1 << ord[j]))) {
          val ^= basis[j];
        }
      }
      res[__builtin_popcount(val)]++;
    }
  } else {
    dp[0][0] = 1;
    int id = 0;
    for (int i = (0); i < (m); ++i) {
      if (basis[i]) {
        ll rbase = 0;
        for (int j = (0); j < (m); ++j) {
          if (ord2[j] != -1 && (basis[i] & (1LL << j))) rbase ^= 1LL << ord2[j];
        }
        basis[i] = rbase;
      }
    }
    for (int i = (0); i < (sz); ++i) {
      while (ord[id] != i) id++;
      for (int j = (sz)-1; j >= (0); --j) {
        for (int msk = (0); msk < (1 << (m - sz)); ++msk) {
          dp[j + 1][msk ^ basis[id]] =
              (dp[j + 1][msk ^ basis[id]] + dp[j][msk]) % MOD;
        }
      }
    }
    for (int i = (0); i < (sz + 1); ++i) {
      for (int j = (0); j < (1 << (m - sz)); ++j) {
        res[i + __builtin_popcount(j)] =
            (res[i + __builtin_popcount(j)] + dp[i][j]) % MOD;
      }
    }
  }
  for (int i = (0); i < (m + 1); ++i) {
    cout << (res[i] * p2[n - sz]) % MOD << " ";
  }
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  p2[0] = 1;
  for (int i = (1); i < (mxN); ++i) {
    p2[i] = (p2[i - 1] * 2LL) % MOD;
  }
  int T = 1;
  for (int tc = (1); tc < (T + 1); ++tc) {
    solve();
  }
  return 0;
}
