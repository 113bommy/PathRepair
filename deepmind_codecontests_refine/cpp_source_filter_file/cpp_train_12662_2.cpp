#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005, mod = 1000000007;
vector<int> pri;
bool vis[80];
int pos[80], a[maxn], n;
long long w[80];
long long dp[1 << 21], dp2[1 << 21], f[maxn];
void prework() {
  for (int i = 2; i < (71); ++i) {
    if (!vis[i]) {
      pri.push_back(i);
      pos[i] = (int)pri.size() - 1;
      for (int j = i; j <= 70; j += i) vis[j] = 1;
    }
  }
  f[0] = 1;
  for (int i = 1; i < (maxn); ++i) f[i] = 2 * f[i - 1] % mod;
}
void init() {
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d", &a[i]);
    w[a[i]]++;
  }
}
int gao(int n) {
  int tmp[30] = {0};
  for (int i = 2; i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      tmp[pos[i]] ^= 1;
    }
  }
  if (n > 1) tmp[pos[n]] ^= 1;
  int res = 0;
  for (int i = 0; i < (21); ++i)
    if (tmp[i]) res |= (1 << i);
  return res;
}
inline int get_nx(int st1, int st2) { return st1 ^ st2; }
void solve() {
  dp[0] = 1;
  for (int i = 2; i < (71); ++i) {
    if (!w[i]) continue;
    int st = gao(i);
    for (int pre = 0; pre < (1 << 19); ++pre) {
      int nx_st = get_nx(st, pre);
      dp2[nx_st] += dp[pre] * f[w[i] - 1] % mod;
      dp2[pre] += dp[pre] * f[w[i] - 1] % mod;
      dp2[nx_st] %= mod;
      dp2[pre] %= mod;
    }
    for (int k = 0; k < (1 << 19); ++k) dp[k] = dp2[k], dp2[k] = 0;
  }
  long long ans = dp[0] - 1;
  if (w[1]) ans = (1 + f[w[1]]) * ans % mod + f[w[1]] - 1;
  cout << ans % mod << endl;
}
int main() {
  prework();
  init();
  solve();
}
