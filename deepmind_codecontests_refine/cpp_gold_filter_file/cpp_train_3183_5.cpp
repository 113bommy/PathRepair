#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
const int inf = (1 << 30);
const double pi = acos(-1);
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int maxn = 1e3 + 10;
void amax(int &aa, int bb) { aa > bb ? aa : aa = bb; }
int n;
int dp[maxn][(1 << 9)], cur[10], a[maxn];
vector<int> in[10];
int can(int len) {
  for (int i = 0; i < 8; i++) cur[i] = 0;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < (1 << 8); j++) dp[i][j] = -inf;
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << 8); j++) {
      if (dp[i][j] == -inf) continue;
      for (int k = 0; k < 8; k++) {
        if (j & (1 << k)) continue;
        int it = cur[k] + len - 1;
        if (it >= in[k].size()) continue;
        amax(dp[in[k][it]][j | (1 << k)], dp[i][j]);
        it++;
        if (it >= in[k].size()) continue;
        amax(dp[in[k][it]][j | (1 << k)], dp[i][j] + 1);
      }
    }
    cur[a[i]]++;
  }
  int ans = -inf;
  for (int i = 0; i < n; i++) ans = max(ans, dp[i][(1 << 8) - 1]);
  if (ans == -inf) return -1;
  return ans * (len + 1) + (8 - ans) * len;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    in[--a[i]].push_back(i);
  }
  int l = 1, r = n / 8;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (can(m) != -1)
      l = m;
    else
      r = m;
  }
  int ans = max(can(l), can(r));
  if (ans == -1) {
    ans = 0;
    for (int i = 0; i < 8; i++)
      if (!in[i].empty()) ans++;
  }
  cout << ans;
  return 0;
}
