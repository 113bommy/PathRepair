#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int N = 2e6 + 5;
const int mod = 1e9 + 7;
int n, k, mu[N], pw[N], ans[N];
bool prime[N];
void build() {
  for (int i = 1; i <= k; i++) prime[i] = true, mu[i] = 1;
  for (int i = 2; i <= k; i++) {
    if (prime[i]) {
      for (int j = i; j <= k; j += i) {
        prime[j] = false;
        if (j % (1ll * i * i) == 0) mu[j] = 0;
        mu[j] *= -1;
      }
    }
  }
}
int fp(int x, int y) {
  if (y == 0) return 1;
  int res = fp(x, y >> 1);
  res = (1ll * res * res) % mod;
  if (y & 1) res = (1ll * res * x) % mod;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  build();
  for (int i = 1; i <= k; i++) pw[i] = fp(i, n);
  for (int i = 1; i <= k; i++) {
    for (int j = i; j <= k; j += i) {
      int x = pw[j / i] * mu[i];
      ans[j] = (ans[j] + x) % mod;
      if (i + j <= k) ans[i + j] = ((ans[i + j] - x) % mod + mod) % mod;
    }
  }
  int sum = 0;
  for (int i = 1; i <= k; i++) {
    ans[i] = ((ans[i] + ans[i - 1]) % mod + 2ll * mod) % mod;
    sum = (sum + (i ^ ans[i])) % mod;
  }
  cout << sum;
  return 0;
}
