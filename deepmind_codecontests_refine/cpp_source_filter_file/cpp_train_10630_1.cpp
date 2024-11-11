#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, a, b[200010];
int qpow(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = (long long)ret * a % mod;
    a = (long long)a * a % mod;
    b >>= 1;
  }
  return ret;
}
int main() {
  scanf("%d%d%d", &n, &m, &a);
  long long ans = 1;
  for (int i = 1; i <= m; i++) {
    scanf("%d", &b[i]);
    int v1 = qpow(a, b[i] - b[i - 1]);
    v1 = (long long)(v1 + 1) * v1 / 2;
    ans = (long long)ans * v1 % mod;
  }
  ans = (long long)ans * qpow(a, n - 2 * b[m]) % mod;
  cout << ans << endl;
  return 0;
}
