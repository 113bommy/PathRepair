#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const int mod = 998244353;
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int sub(int a, int b) { return a < b ? a - b + mod : a - b; }
int jc[N], rjc[N];
int qpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = mul(ret, a);
    a = mul(a, a);
  }
  return ret;
}
void init() {
  jc[0] = 1;
  for (int i = 1; i < N; i++) jc[i] = mul(jc[i - 1], i);
  rjc[N - 1] = qpow(jc[N - 1], mod - 2);
  for (int i = N - 2; i >= 0; --i) rjc[i] = mul(rjc[i + 1], i + 1);
}
int C(int n, int m) { return mul(jc[n], mul(rjc[m], rjc[n - m])); }
int main() {
  init();
  int n;
  long long k;
  cin >> n >> k;
  if (k >= n) {
    puts("0");
  } else {
    int m = n - k, ans = 0;
    for (int i = 0; i <= m; i++) {
      if (i & 1)
        ans = sub(ans, mul(C(m, i), qpow(m - i, n)));
      else
        ans = add(ans, mul(C(m, i), qpow(m - i, n)));
    }
    ans = mul(ans, C(n, m));
    if (k == 0)
      cout << ans << endl;
    else
      cout << mul(ans, 2) << endl;
  }
}
