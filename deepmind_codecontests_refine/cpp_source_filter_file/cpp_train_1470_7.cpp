#include <bits/stdc++.h>
using namespace std;
const int M = 2e6 + 10, MOD = 1e9 + 7;
int n, cnt[M], vis[M], oo, lim, mark[M];
vector<int> pri;
int main(void) {
  scanf("%d", &n);
  lim = 0;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    lim = max(lim, x);
    cnt[x]++;
  }
  int oo = 0;
  for (int i = lim; i >= 2; i--) {
    if (!cnt[i]) continue;
    bool flg = 1;
    for (int j = i + i; j <= lim && flg; j += i) flg &= !vis[j];
    if (flg) vis[i] = i, cnt[i]--;
    if (cnt[i]) vis[i - 1] = i - 1, cnt[i]--;
    if (cnt[i]) oo = 1;
  }
  int Ans = 1;
  for (int i = 2; i <= lim; i++) {
    if (mark[i]) continue;
    int mx = 1, ii = 0;
    for (int j = i; j <= lim; j += i) {
      if (vis[j]) {
        int now = 1, x = vis[j];
        while (x % i == 0) x /= i, now *= i;
        if (now > mx)
          mx = now, ii = 0;
        else if (now == mx)
          ii = 1;
      }
      mark[j] = 1;
    }
    for (int j = i; j <= mx; j += i)
      if (vis[j] && (vis[j] % mx || ii))
        while (vis[j] % i == 0) vis[j] /= i;
    Ans = 1LL * Ans * mx % MOD;
  }
  for (int i = 2; i <= lim; i++)
    if (vis[i] == 1) oo = 1;
  cout << (Ans + oo) % MOD << endl;
  return 0;
}
