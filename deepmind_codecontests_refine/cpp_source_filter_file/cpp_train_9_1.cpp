#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, mod, cnt[MAXN], inv[MAXN] = {0, 1}, sum[MAXN];
int a, b, ans;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
inline void Add(int &x, int y) { x += y, x >= mod && (x -= mod); }
inline void prepare() {
  for (int i = 2; i <= n * 2; i++)
    inv[i] = mod - 1ll * mod / i * inv[mod % i] % mod;
  for (int i = 1; i <= n * 2; i++) sum[i] = (sum[i - 1] + inv[i]) % mod;
}
void dfs_pre(int l, int r, int dep, int &len) {
  if (dep == k || l == r) return cnt[len = r - l + 1]++, void();
  int mid = (l + r) >> 1;
  dfs_pre(l, mid, dep + 1, len);
  dfs_pre(mid + 1, r, dep + 1, len);
}
inline int calc(int x, int y) {
  int ans = 0;
  for (int i = 1; i <= x; i++) Add(ans, mod + sum[i + y] - sum[i]);
  return ans;
}
int main() {
  n = read(), k = read(), mod = read();
  if (k >= 19) {
    puts("0");
    return 0;
  }
  dfs_pre(1, n, 1, a), prepare();
  if (cnt[a - 1])
    b = a - 1;
  else if (cnt[a + 1])
    b = a + 1;
  assert((cnt[a - 1] & cnt[a + 1]) == 0);
  Add(ans, 1ll * calc(a, a) * cnt[a] % mod * (cnt[a] - 1) % mod * inv[2] % mod);
  Add(ans, 1ll * calc(b, b) * cnt[b] % mod * (cnt[b] - 1) % mod * inv[2] % mod);
  Add(ans, 1ll * calc(a, b) * cnt[a] % mod * cnt[b] % mod);
  printf("%lld\n", (1ll * n * (n - 1) % mod * inv[4] % mod - ans + mod) % mod);
  return 0;
}
