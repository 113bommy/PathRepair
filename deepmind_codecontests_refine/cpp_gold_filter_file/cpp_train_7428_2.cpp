#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 17;
const int MOD = 1e9 + 7;
long long cs[MAXN], a[MAXN], ans[MAXN];
long long qm(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a % MOD;
    b >>= 1;
    a = a * a % MOD;
  }
  return ret;
}
long long inv(long long a) { return qm(a, MOD - 2); }
long long comb(long long n, long long m) {
  long long up = 1, down = 1;
  for (int i = n - m + 1; i <= n; ++i) {
    up = up * i % MOD;
  }
  for (int i = 1; i <= m; ++i) {
    down = down * i % MOD;
  }
  return up * inv(down) % MOD;
}
int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    cs[i] = comb(k + i - 1, i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      ans[j] = (ans[j] + a[i] * cs[j - i] % MOD) % MOD;
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << endl;
  }
  return 0;
}
