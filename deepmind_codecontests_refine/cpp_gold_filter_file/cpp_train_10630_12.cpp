#include <bits/stdc++.h>
using namespace std;
int mul(int a, int b) { return (1ll * a * b) % 998244353; }
int modexp(int a, int b) {
  int res = 1;
  int val = a;
  while (b != 0) {
    if (b & 1) res = mul(res, val);
    val = mul(val, val);
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, a;
  cin >> n >> m >> a;
  int arr[m];
  for (int i = 0; i < m; ++i) cin >> arr[i];
  int ans = 1;
  ans = mul(ans, modexp(a, n - 2 * arr[m - 1]));
  for (int i = m - 1; i >= 1; i--) arr[i] = arr[i] - arr[i - 1];
  for (int i = 0; i < m; ++i) {
    int val = modexp(a, arr[i]);
    int res = ((1ll * val * (val - 1)) / 2) % 998244353;
    res = (res + val) % 998244353;
    ans = mul(ans, res);
  }
  cout << ans << "\n";
  return 0;
}
