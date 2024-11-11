#include <bits/stdc++.h>
using namespace std;
const long long N = 2e3 + 2;
const long long M = 1e5 + 5;
const long long Mod = 1e9 + 7;
int n, m, k;
pair<int, int> p[N];
int dp[N][2];
int Fact[2 * M], invFact[2 * M];
long long fp(long long x, long long y, long long m = Mod) {
  long long res = 1;
  for (int i = 0; (1LL << i) <= y; i++, x = x * x % m)
    if (y & 1LL << i) res = res * x % m;
  return res;
}
int C(int n, int k) {
  if (n < 0 || k < 0 || n - k < 0) return 0;
  return (long long)Fact[n] * invFact[k] % Mod * invFact[n - k] % Mod;
}
long long f(pair<int, int>& a, pair<int, int>& b) {
  auto [i1, j1] = a;
  auto [i2, j2] = b;
  if (i1 > i2 || j1 > j2) return 0;
  return C(i2 - i1 + j2 - j1, i2 - i1);
}
int main() {
  Fact[0] = invFact[0] = 1;
  for (int i = 1; i < M; i++)
    Fact[i] = (long long)Fact[i - 1] * i % Mod,
    invFact[i] = fp(Fact[i], Mod - 2);
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; i++) cin >> p[i].first >> p[i].second;
  p[k++] = {1, 1};
  p[k++] = {n, m};
  sort(p, p + k);
  dp[k - 1][1] = 1;
  for (int i = k - 2; i >= 0; i--)
    for (int b = 0; b <= 1; b++) {
      for (int j = i + 1; j < k; j++)
        dp[i][b] = (dp[i][b] + f(p[i], p[j]) * dp[j][!b] % Mod) % Mod;
    }
  cout << ((long long)dp[0][0] - dp[0][1] + Mod) % Mod << endl;
  return 0;
}
