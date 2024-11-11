#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long s = 0, w = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    s = s * 10 + ch - '0';
    ch = getchar();
  }
  return s * w;
}
const int mod = 998244353;
int n, ans, inv2;
int f[500010];
vector<int> e[500010];
inline int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % mod;
    b >>= 1;
    a = 1LL * a * a % mod;
  }
  return ans;
}
void dfs(int x, int father) {
  int p = 1;
  for (int y : e[x])
    if (y != father)
      dfs(y, x), p = 1LL * p * inv2 *
                     (1 + f[y] >= mod ? 1 + f[y] - mod : 1 + f[y]) % mod;
  f[x] = (1 + mod - p >= mod ? 1 + mod - p - mod : 1 + mod - p);
  ans = (ans + f[x] >= mod ? ans + f[x] - mod : ans + f[x]);
}
int main() {
  n = read();
  inv2 = ksm(2, mod - 2);
  for (register int i = 1; i <= n - 1; i++) {
    int x = read(), y = read();
    e[x].push_back(y), e[y].push_back(x);
  }
  dfs(1, 0);
  printf("%lld\n", 1LL * ans * ksm(2, n) % mod);
  return 0;
}
