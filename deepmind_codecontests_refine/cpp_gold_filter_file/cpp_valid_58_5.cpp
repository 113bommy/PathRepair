#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)4e5 + 5;
const int MOD = 998244353;
const int K = 3500;
const int M = 60;
const long long S = (1ll << M) - 1;
int addMod(int a, int b, int m = MOD) { return a + b < m ? a + b : a + b - m; }
int mulMod(int a, int b, int m = MOD) { return a * 1ll * b % m; }
int binPow(int a, int b, int m = MOD) {
  int ret = 1;
  while (b > 0) {
    if (b & 1) {
      ret = mulMod(ret, a, m);
    }
    a = mulMod(a, a, m);
    b >>= 1;
  }
  return ret;
}
int fact[MAXN], inv[MAXN];
int n, m;
void pre() {
  fact[0] = 1;
  for (int i = (1); i < (MAXN); ++i) {
    fact[i] = mulMod(fact[i - 1], i);
  }
  inv[MAXN - 1] = binPow(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 1; i; --i) {
    inv[i - 1] = mulMod(inv[i], i);
  }
}
int C(int n, int k) { return mulMod(fact[n], mulMod(inv[k], inv[n - k])); }
bool bit(long long x, int p) { return x & (1ll << p); }
long long B[K + 1];
void solve() {
  cin >> n >> m;
  fill(B, B + K + 1, 0ll);
  for (int i = (0); i < (m); ++i) {
    int x, y;
    cin >> x >> y;
    --y;
    int idx = y / M;
    y %= M;
    B[idx] |= (1ll << y);
    for (int j = K - 1; j > idx; --j) {
      B[j + 1] |= bit(B[j], M - 1);
      B[j] = ((B[j] << 1) & S);
    }
    long long a = (B[idx] & ((1ll << y) - 1));
    long long b = (B[idx] ^ a);
    B[idx + 1] |= bit(b, M - 1);
    B[idx] = ((a + (b << 1)) & S);
  }
  int cnt = n - 1;
  for (int i = (0); i < (K); ++i) {
    cnt -= __builtin_popcountll(B[i]);
  }
  int ans = C(n + cnt, n);
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tt = 1;
  cin >> tt;
  pre();
  for (int i = 1; i <= tt; ++i) {
    solve();
  }
  return 0;
}
