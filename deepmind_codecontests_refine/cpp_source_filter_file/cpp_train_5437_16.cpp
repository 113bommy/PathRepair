#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = (int)1e9 + 7;
int fact[N];
int inver[N];
int n, m;
inline void add(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
inline int mul(int a, int b) { return (int)((long long)a * b % mod); }
inline int fp(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}
inline int inv(int x) { return fp(x, mod - 2); }
int comb(int n, int k) {
  if (n <= 0 || k > n) return 1;
  int ans = mul(fact[n], inver[k]);
  ans = mul(ans, inver[n - k]);
  return ans;
}
int main() {
  fact[0] = 1;
  inver[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = mul(fact[i - 1], i);
    inver[i] = inv(fact[i]);
  }
  cin >> n >> m;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      int a = i, b = n - j + 1;
      add(ans, mul(comb(m + a - 2, a - 1), comb(m + b - 2, b - 1)));
    }
  }
  cout << ans << endl;
  return 0;
}
