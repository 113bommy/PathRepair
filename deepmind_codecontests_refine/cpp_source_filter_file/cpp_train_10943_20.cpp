#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 998244353;
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
const int mxN = 2001;
ll dp[mxN][mxN];
int n;
int prv[mxN];
int arr[mxN][mxN];
bool done1[mxN];
bool done2[mxN];
ll fact[mxN];
struct BIT {
  int bit[mxN];
  void upd(int p, int x) {
    p++;
    while (p <= mxN - 1) {
      bit[p] += x;
      p += p & (-p);
    }
  }
  int sum(int p) {
    int res = 0;
    p++;
    while (p > 0) {
      res += bit[p];
      p -= p & (-p);
    }
    return res;
  }
  void clear() { memset(bit, 0, sizeof(bit)); }
} fri, nfri;
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  fact[0] = 1;
  for (int i = (1); i < (n + 1); ++i) {
    fact[i] = (fact[i - 1] * i) % MOD;
  }
  for (int i = (0); i < (n); ++i) {
    for (int j = (0); j < (n); ++j) {
      cin >> arr[i][j];
      arr[i][j]--;
    }
  }
  dp[0][0] = 1;
  for (int i = (2); i < (n + 1); ++i) {
    dp[i][0] = (ll)(i - 1) * (dp[i - 1][0] + dp[i - 2][0]) % MOD;
  }
  for (int j = (1); j < (n + 1); ++j) {
    for (int i = (0); i < (n + 1); ++i) {
      dp[i][j] = (dp[i][j - 1] * (ll)(i + j)) % MOD;
      if (i) {
        dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (ll)i) % MOD;
      }
    }
  }
  ll res = 0;
  ll incl = 0;
  for (int i = (0); i < (n); ++i) {
    fri.upd(i, 1);
  }
  for (int i = (0); i < (n); ++i) {
    int less = fri.sum(arr[0][i] - 1);
    incl = (incl + (ll)less * fact[n - i - 1]);
    fri.upd(arr[0][i], -1);
    prv[i] = arr[0][i];
  }
  res = (res + incl * binpow(dp[n][0], n - 1)) % MOD;
  fri.clear();
  for (int i = (1); i < (n); ++i) {
    incl = 0;
    memset(done1, false, sizeof(done1));
    memset(done2, false, sizeof(done2));
    for (int i = (0); i < (n); ++i) {
      nfri.upd(i, 1);
    }
    for (int j = (0); j < (n); ++j) {
      int f = fri.sum(n + 1);
      int nf = nfri.sum(n + 1);
      int cntf = fri.sum(arr[i][j] - 1);
      int cntnf = nfri.sum(arr[i][j] - 1);
      if (done1[prv[j]]) {
        if (f > 0) incl = (incl + (ll)(cntf)*dp[nf][f - 1]) % MOD;
        if (nf > 0) incl = (incl + (ll)(cntnf)*dp[nf - 1][f]) % MOD;
      } else {
        if (nf > 0) incl = (incl + (ll)(cntf)*dp[nf - 1][f]) % MOD;
        if (nf > 1)
          incl = (incl + (ll)(cntnf - (prv[j] < arr[i][j] ? 1 : 0)) *
                             dp[nf - 2][f + 1]) %
                 MOD;
      }
      done1[arr[i][j]] = 1;
      if (done2[arr[i][j]]) {
        fri.upd(arr[i][j], -1);
      } else {
        nfri.upd(arr[i][j], -1);
      }
      if (!done1[prv[j]]) {
        nfri.upd(prv[j], -1);
        fri.upd(prv[j], 1);
      }
      done2[prv[j]] = 1;
      prv[j] = arr[i][j];
    }
    fri.clear();
    nfri.clear();
    res = (res + incl * binpow(dp[n][0], n - i - 1)) % MOD;
  }
  cout << res << "\n";
  return 0;
}
