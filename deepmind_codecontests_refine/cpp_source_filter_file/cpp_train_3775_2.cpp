#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7, M = 998244353;
int inv(int i) {
  if (i == 1) return 1;
  return M - (long long)M / i * inv(M % i) % M;
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) cin >> v[i];
  sort(v.begin() + 1, v.end(), greater<int>());
  for (int i = 1; i <= n; i++) v[i] = (v[i] + v[i - 1]) % M;
  int in = inv(n);
  for (int k = 1; k <= n; k++) {
    int ans = 0, cur = 0;
    for (int i = 1; i <= n; i += k) {
      int r = min(n, i + k - 1);
      ans = ans + (((long long)v[r] - v[i - 1] + M) % M * cur++ % M) % M;
    }
    ans = (long long)ans * in % M;
    cout << ans << " ";
  }
}
