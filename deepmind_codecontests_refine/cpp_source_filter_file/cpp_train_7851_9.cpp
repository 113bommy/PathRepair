#include <bits/stdc++.h>
using namespace std;
template <class T>
using vv = vector<vector<T>>;
template <class T>
inline bool MX(T &l, const T &r) {
  return l < r ? l = r, 1 : 0;
}
template <class T>
inline bool MN(T &l, const T &r) {
  return l > r ? l = r, 1 : 0;
}
const long long MOD = 1e9 + 7;
int N;
int M;
long long a[114514];
long long imos[114][114514];
long long memo[114514][114];
long long comb(long long n, long long k) {
  if (k == 0) return 1;
  if (n == k) return 1;
  if (k == 1) return n;
  if (memo[n][k] != -1) return memo[n][k];
  return memo[n][k] = (comb(n - 1, k) + comb(n - 1, k - 1)) % MOD;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int(i) = 0; (i) < (N); ++(i)) {
    scanf("%lld", &a[i]);
  }
  fill(memo[0], memo[N + 1], -1);
  for (int(i) = 0; (i) < (M); ++(i)) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    --l;
    int n = r - l;
    k = 100 - k;
    (imos[k][l] += 1) %= MOD;
    for (int(t) = 0; (t) < (101 - k); ++(t)) {
      (imos[k + t][r] += (MOD - comb(n - 1 + t, t) % MOD) % MOD) %= MOD;
    }
  }
  for (int(k) = 0; (k) < (101); ++(k)) {
    imos[k + 1][0] += imos[k][0];
    imos[k + 1][0] %= MOD;
    for (int(i) = 1; (i) < (N); ++(i)) {
      imos[k][i] += imos[k][i - 1];
      imos[k][i] %= MOD;
      imos[k + 1][i] += imos[k][i];
      imos[k + 1][i] %= MOD;
    }
  }
  for (int(i) = 0; (i) < (N); ++(i)) {
    long long t = (a[i] + imos[100][i]) % MOD;
    printf("%lld ", t);
  }
  puts("");
}
