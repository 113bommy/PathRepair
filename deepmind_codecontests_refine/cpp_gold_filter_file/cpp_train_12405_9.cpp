#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, N = 200005;
int in[N], jie[N];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int l, r;
  for (int i = 1; i < n; i++) {
    cin >> l >> r;
    in[l]++, in[r]++;
  }
  jie[0] = 1;
  for (int i = 1; i <= n; i++) jie[i] = 1ll * jie[i - 1] * i % mod;
  long long ans = n;
  for (int i = 1; i <= n; i++) {
    ans = ans * jie[in[i]] % mod;
  }
  cout << ans << endl;
  return 0;
}
