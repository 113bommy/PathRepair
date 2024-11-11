#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ll = long long;
using pii = pair<int, int>;
const int dr[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dc[] = {0, -1, 0, 1, -1, 1, -1, 1};
const int N = 212345;
const int MOD = 998244353;
LL p[N], s[N], invs[N], ss[N], ans;
int n, q;
set<int> mirror;
LL inv(LL x) {
  int pw = MOD - 2;
  LL ans = 1;
  while (pw) {
    if (pw & 1) ans = ans * x % MOD;
    x = x * x % MOD;
    pw >>= 1;
  }
  return ans;
}
inline LL cal(int u, int v) {
  LL ret = ss[v - 1];
  if (u > 1) ret = (ret - ss[u - 2] + MOD) % MOD;
  ret = ret * invs[v] % MOD;
  return ret;
}
void init() {
  LL dem = inv(100);
  for (int i = 1; i <= n; ++i) p[i] = p[i] * dem % MOD;
  s[0] = 1;
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] * p[i] % MOD;
  for (int i = 1; i <= n; ++i) invs[i] = inv(s[i]);
  ss[0] = s[0];
  for (int i = 1; i <= n; ++i) ss[i] = (ss[i - 1] + s[i]) % MOD;
  mirror.insert(1);
  mirror.insert(n + 1);
  ans = cal(1, n);
}
void solve(int x) {
  if (!mirror.count(x)) {
    auto it = mirror.upper_bound(x);
    ans = (ans - cal(*prev(it), *it - 1) + MOD) % MOD;
    ans = (ans + cal(x, *it - 1)) % MOD;
    ans = (ans + cal(*prev(it), x - 1)) % MOD;
    mirror.insert(x);
  } else {
    mirror.erase(x);
    auto it = mirror.upper_bound(x);
    ans = (ans - cal(x, *it - 1) + MOD) % MOD;
    ans = (ans - cal(*prev(it), x - 1) + MOD) % MOD;
    ans = (ans + cal(*prev(it), *it - 1)) % MOD;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  init();
  while (q--) {
    int x;
    cin >> x;
    solve(x);
    cout << ans << '\n';
  }
  return 0;
}
