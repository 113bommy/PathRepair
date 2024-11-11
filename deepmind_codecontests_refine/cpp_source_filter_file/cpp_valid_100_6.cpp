#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const int mod = 998244353;
int add(int a, int b) {
  if (a + b >= mod) return a + b - mod;
  return a + b;
}
int mul(int a, int b) { return (a * 1ll * b) % mod; }
int sub(int a, int b) {
  if (a - b >= 0)
    return a - b;
  else
    return a - b + mod;
}
int bin_pow(int a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    int b = bin_pow(a, n / 2);
    return mul(b, b);
  } else
    return mul(a, bin_pow(a, n - 1));
}
const int N = 2e2 + 1;
int f[N], rf[N];
int C(int k, int n) { return mul(f[n], mul(rf[k], rf[n - k])); }
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  f[0] = f[1] = rf[0] = rf[1] = 1;
  for (int i = 2; i < N; i++) {
    f[i] = mul(f[i - 1], i);
    rf[i] = mul(rf[i - 1], bin_pow(i, mod - 2));
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      cnt[a]++;
    }
    if (cnt.rbegin()->second >= 2) {
      cout << f[n] << '\n';
    } else {
      auto it = (--(--(cnt.end())));
      if (it->first + 1 != cnt.rbegin()->first) {
        cout << 0 << '\n';
      } else {
        int c = it->second;
        int ans = mul(n - 1, f[n - 1]);
        for (int i = c; i < n - 1; i++) {
          ans = sub(ans, mul(C(c, i), mul(f[c], f[n - 1 - c])));
        }
        cout << ans << '\n';
      }
    }
  }
  return 0;
}
