#include <bits/stdc++.h>
using namespace std;
void fastStream() {
  cin.tie(0);
  std::ios_base::sync_with_stdio(0);
}
const int mod = 1000000000 + 7;
long long extgcd(long long a, long long b, long long &x, long long &y) {
  long long d = a;
  if (b != 0) {
    d = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1;
    y = 0;
  }
  return d;
}
long long mod_inverse(long long a, int m) {
  long long x, y;
  extgcd(a, m, x, y);
  return (m + x % m) % m;
}
const int MAX_FACT = 2000000;
long long fact[MAX_FACT];
long long inv_fact[MAX_FACT];
long long pow_mod(long long a, long long n) {
  long long cur = 1;
  long long mul = a;
  while (n) {
    if (n % 2) cur = (cur * mul) % mod;
    mul = (mul * mul) % mod;
    n /= 2;
  }
  return cur;
}
long long div_mod(int a) { return pow_mod(a, mod - 2); }
void calcFact() {
  fact[0] = 1;
  inv_fact[0] = mod_inverse(0, mod);
  for (int i = 1; i < MAX_FACT; i++) {
    fact[i] = (fact[i - 1] * i) % mod;
    inv_fact[i] = mod_inverse(fact[i], mod);
  }
}
long long comb(long long a, long long b) {
  if (a < 0 || b < 0)
    return 0;
  else if (a < b)
    return 0;
  else if (b == 0)
    return 1;
  long long res = fact[a];
  res = (res * inv_fact[b]) % mod;
  res = (res * inv_fact[a - b]) % mod;
  return res;
}
long long dp[2010];
int H, W, N;
int Y[2010];
int X[2010];
int main() {
  calcFact();
  memset(dp, -1, sizeof(dp));
  vector<pair<pair<int, int>, int> > v;
  fastStream();
  cin >> H >> W >> N;
  for (int i = 0; i < N; i++) {
    cin >> Y[i] >> X[i];
    Y[i]--;
    X[i]--;
  }
  Y[N] = H - 1;
  X[N] = W - 1;
  N++;
  for (int i = 0; i < N; i++) {
    v.push_back(make_pair(pair<int, int>(Y[i], X[i]), i));
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < (int)v.size(); i++) {
    const int tar_idx = v[i].second;
    int tar_x = X[tar_idx];
    int tar_y = Y[tar_idx];
    long long tot = comb(tar_y + tar_x, tar_x) % mod;
    for (int j = 0; j < N; j++) {
      if (j == tar_idx) continue;
      int x = X[j];
      int y = Y[j];
      if (y <= tar_y && x <= tar_x) {
        const int diff_y = (tar_y - y);
        const int diff_x = (tar_x - x);
        long long pat = (dp[j] * comb(diff_y + diff_x, diff_y)) % mod;
        tot -= pat;
        while (tot < 0) tot += mod;
      }
    }
    dp[tar_idx] = tot;
  }
  cout << dp[N - 1] << endl;
  return 0;
}
