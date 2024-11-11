#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000010;
const int inf = 0x3f3f3f3f;
int l, p, r;
int prim[32], cntp;
int a[maxn], n;
int can[maxn], dp[maxn];
void dfs(int num, int i) {
  a[n++] = num;
  for (; i < cntp; i++) {
    if ((long long)num * prim[i] > r) break;
    dfs(num * prim[i], i);
  }
}
void init() {
  for (int i = 2; i <= p; i++) {
    bool f = 1;
    for (int j = 2; j * j <= i; j++)
      if (i % j == 0) {
        f = false;
        break;
      }
    if (f) prim[cntp++] = i;
  }
  dfs(1, 0);
}
void solve() {
  memset(dp, inf, sizeof(dp));
  dp[0] = 0;
  sort(a, a + n);
  for (int i = 1; i <= p; i++)
    for (int j = 0, k = 0; j < n; j++) {
      while (k < n && a[k] * i < a[j]) k++;
      if (k == n) break;
      if (a[k] * i == a[j]) {
        dp[j] = min(dp[j], dp[k] + 1);
        if (dp[j] + i <= p) can[j] = 1;
      }
    }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (a[i] >= l && can[i]) ans++;
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> l >> p >> r;
  init();
  solve();
}
