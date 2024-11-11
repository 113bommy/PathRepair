#include <bits/stdc++.h>
using namespace std;
const int mod1 = 998244353, mod2 = 1e9 + 7;
const int N = 2e6, MX = 1e6;
long long n, c;
int tot, ans, lim, pw[N], sum[N];
vector<int> ve[N];
inline int dec(int x, int y, int mod) {
  return (x - y < 0) ? x - y + mod : x - y;
}
inline int add(int x, int y, int mod) {
  return (x + y >= mod) ? x + y - mod : x + y;
}
inline void dfs(int pos, int now) {
  if (now <= n) {
    ++tot;
    int x = dec(tot, now, mod1);
    ve[pos - 1].push_back(x);
    sum[pos - 1] = add(sum[pos - 1], x, mod2);
  }
  if (pos > 6) return;
  for (int i = 0; i <= 9; ++i) dfs(pos + 1, now * 10 + i);
}
inline void solve(int pos, int now) {
  if (now > n) return;
  if (pos > 1) {
    if (10ll * now * MX >= n && 1ll * (now + 1) * MX - 1 <= n) {
      for (int i = 0; i < 7; ++i) {
        int x = ((c - 1ll * now * pw[i]) % mod1 + mod1) % mod1;
        int p =
            lower_bound(ve[i].begin(), ve[i].end(), mod1 - x) - ve[i].begin();
        ans = add(ans, add(1ll * x * ve[i].size() % mod2, sum[i], mod2), mod2);
        ans = dec(ans, 1ll * mod1 * (ve[i].size() - p) % mod2, mod2);
      }
      c += tot;
      return;
    }
    ++c, ans = add(ans, ((c - now) % mod1 + mod1) % mod1, mod2);
  }
  for (int i = (pos == 1 ? 1 : 0); i <= 9; ++i) solve(pos + 1, now * 10 + i);
}
int main() {
  scanf("%lld", &n);
  pw[0] = 1;
  for (int i = 1; i < 9; ++i) pw[i] = 10 * pw[i - 1];
  dfs(1, 0);
  for (int i = 0; i < 7; ++i) sort(ve[i].begin(), ve[i].end());
  solve(1, 0);
  printf("%d\n", ans);
  return 0;
}
