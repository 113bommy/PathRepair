#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = int(1e9);
const int MAX = 1000007;
int fact[MAX], invFact[MAX];
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}
inline int mul(int a, int b) { return (long long)a * b % MOD; }
inline int exp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int a) { return exp(a, MOD - 2); }
int main() {
  ios_base::sync_with_stdio(false);
  fact[0] = invFact[0] = 1;
  int n;
  cin >> n;
  for (int i = 1; i <= n + 1; i++) {
    fact[i] = mul(fact[i - 1], i);
    invFact[i] = mul(invFact[i - 1], inv(i));
  }
  int res = 0;
  for (int k = 1; k <= n + 1; k++) {
    int t = mul(fact[n], mul(invFact[k], invFact[n - k]));
    add(res, mul(t, t));
  }
  cout << res;
  return 0;
}
