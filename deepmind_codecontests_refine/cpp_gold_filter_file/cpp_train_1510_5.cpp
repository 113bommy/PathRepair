#include <bits/stdc++.h>
using namespace std;
long long Bigmod(long long base, long long power, long long MOD) {
  long long ret = 1;
  while (power) {
    if (power & 1) ret = (ret * base) % MOD;
    base = (base * base) % MOD;
    power >>= 1;
  }
  return ret;
}
long long ModInverse(long long number, long long MOD) {
  return Bigmod(number, MOD - 2, MOD);
}
vector<pair<long long, long long> > v;
int isValid(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first <= b.first && a.second <= b.second) return 1;
  return 0;
}
long long F[2000002];
long long Iv[2000002];
void LOL() {
  F[0] = 1;
  Iv[0] = ModInverse(F[0], 1000000007);
  for (int i = 1; i <= 2e6; i++) {
    F[i] = (F[i - 1] * i) % 1000000007;
    Iv[i] = ModInverse(F[i], 1000000007);
  }
}
long long Way(int p, int q, int x, int y) {
  int n = x - p + y - q, m = x - p;
  long long ans = F[n];
  ans = (ans * Iv[m]) % 1000000007;
  ans = (ans * Iv[n - m]) % 1000000007;
  return ans;
}
long long n, m, k;
long long dp[2009];
long long Koto(int p) {
  long long ans = Way(1, 1, v[p].first, v[p].second);
  for (int i = 0; i < p; i++) {
    if (isValid(v[i], v[p])) {
      ans -= (dp[i] * Way(v[i].first, v[i].second, v[p].first, v[p].second)) %
             1000000007;
      ans = (ans + 1000000007) % 1000000007;
    }
  }
  return ans;
}
int main() {
  LOL();
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  v.push_back(make_pair(n, m));
  sort(v.begin(), v.end());
  for (int i = 0; i <= k; i++) {
    dp[i] = Koto(i);
  }
  cout << dp[k] << endl;
  return 0;
}
