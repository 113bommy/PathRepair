#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int MOD;
int dp[4000005];
int criba[4000005 + 1];
void crearCriba() {
  int w[] = {4, 2, 4, 2, 4, 6, 2, 6};
  for (int p = 25; p <= 4000005; p += 10) criba[p] = 5;
  for (int p = 9; p <= 4000005; p += 6) criba[p] = 3;
  for (int p = 4; p <= 4000005; p += 2) criba[p] = 2;
  for (int p = 7, cur = 0; p * p <= 4000005; p += w[cur++ & 7])
    if (!criba[p])
      for (int j = p * p; j <= 4000005; j += (p << 1))
        if (!criba[j]) criba[j] = p;
}
vector<int> primos;
void buscarPrimos() {
  crearCriba();
  for (int i = (2); i < (4000005 + 1); i++)
    if (!criba[i]) primos.push_back(i);
}
void fact(long long n, map<long long, long long> &f) {
  while (criba[n]) {
    f[criba[n]]++;
    n /= criba[n];
  }
  if (n > 1) f[n]++;
}
void divisores(map<long long, long long> &f, vector<int> &divs,
               map<long long, long long>::iterator it, long long n = 1) {
  if (it == f.begin()) divs.clear();
  if (it == f.end()) {
    divs.push_back(n);
    return;
  }
  long long p = it->first, k = it->second;
  ++it;
  for (int _ = (0); _ < (k + 1); _++) divisores(f, divs, it, n), n *= p;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  cin >> MOD;
  int acum = 0;
  dp[1] = 1;
  const int mod = MOD;
  buscarPrimos();
  for (int i = (2); i < (n + 1); i++) {
    map<long long, long long> factores;
    vector<int> divs;
    fact(i, factores);
    divisores(factores, divs, factores.begin());
    divs.pop_back();
    for (auto it = divs.begin(); it != divs.end(); it++) {
      if (*it == 1)
        acum = (acum + dp[*it]) % mod;
      else
        acum = (acum + mod - dp[*it - 1] + dp[*it]) % mod;
    }
    acum += dp[i - 1];
    acum %= mod;
    dp[i] += acum;
    dp[i] %= mod;
  }
  cout << dp[n] << '\n';
  return 0;
}
