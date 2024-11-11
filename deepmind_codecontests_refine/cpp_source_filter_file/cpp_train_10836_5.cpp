#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long mod = 998244353;
const int N = 1e6 + 10;
int n;
int a[N];
int c[N];
int main() {
  scanf("%d", &n);
  for (int i = n; i >= 1; i--) scanf("%d", &a[i]);
  c[1] = 1;
  long long z = 1;
  for (int i = 2; i <= n; i++) {
    c[i] = c[i - 1] * 2 + z;
    c[i] %= mod;
    z *= 2;
    z %= mod;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + 1ll * c[i] * a[i]) % mod;
  }
  cout << ans << endl;
  return 0;
}
