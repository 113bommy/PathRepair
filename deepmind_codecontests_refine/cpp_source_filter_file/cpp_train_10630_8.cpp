#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
int const M = 2e5 + 20, mod = 998244353;
int n, m, A, b[M];
int ans = 1;
inline int pw(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = 1ll * res * a % mod;
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> A;
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    int last = (i ? b[i - 1] : 0);
    int k = pw(A, b[i] - last);
    int val = 1ll * k * (k + 1) / 2;
    ans = 1ll * ans * val % mod;
  }
  int k = pw(A, n - 2 * b[m - 1]);
  ans = 1ll * ans * k % mod;
  cout << ans << '\n';
}
