#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 5050;
int fac[N], inv[N], ifac[N], dp[N][N];
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int mul(int a, int b) { return (long long)a * b % mod; }
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) {
      res = res * a % mod;
    }
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
void init(int n) {
  fac[0] = inv[0] = ifac[0] = 1;
  for (int i = (1); i < (n + 1); i++) fac[i] = mul(fac[i - 1], i);
  ifac[n] = qpow(fac[n], mod - 2);
  for (int i = (n)-1; i >= (1); i--) ifac[i] = mul(ifac[i + 1], i + 1);
  for (int i = (1); i < (n + 1); i++) inv[i] = mul(ifac[i], fac[i - 1]);
}
int get_C(int a, int b) { return mul(mul(fac[a], ifac[a - b]), ifac[b]); }
void get_Eulernumber(int n) {
  dp[0][0] = 1;
  for (int i = (1); i < (n + 1); i++) {
    dp[i][0] = 1;
    for (int j = (1); j < (n + 1); j++) {
      dp[i][j] = add(mul(j + 1, dp[i - 1][j]), mul((i - j), dp[i - 1][j - 1]));
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  init(n + 10);
  get_Eulernumber(n + 10);
  for (int i = (1); i < (n + 1); i++) {
    int ans = 0;
    for (int j = (1); j < (n + 1); j++) {
      ans = add(ans, mul(mul(dp[j][i - 1], fac[n - j]), get_C(n, j)));
    }
    cout << ans << " ";
  }
  return 0;
}
