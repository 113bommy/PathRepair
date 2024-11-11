#include <bits/stdc++.h>
using namespace std;
int dp[2][15][15];
int val[15];
int n;
int pos[20];
int ta[20];
int count(int l, int ind) {
  if (ind == 6) return 1;
  int ret = 0;
  for (int i = 0; i <= min(l, n); i++) {
    if (ta[i] == pos[i]) continue;
    ta[i]++;
    ret += (int)((long long)(pos[i] - ta[i] + 1) * count(l - i, ind + 1) %
                 1000000007);
    ret %= 1000000007;
    ta[i]--;
  }
  return ret;
}
int sol(bool c, int l, int ind) {
  if (ind == n) {
    if (!l) return 1;
    return 0;
  }
  if (l < 0) return 0;
  if (dp[c][l][ind] != -1) return dp[c][l][ind];
  int ret = 0;
  int i;
  for (i = 0; i <= (c ? 9 : val[ind]); i++) {
    bool b = 1;
    if (i == val[ind] && !c) b = 0;
    int nr = 0;
    if (i == 4 || i == 7) nr = 1;
    ret = (ret + sol(b, l - nr, ind + 1));
  }
  return dp[c][l][ind] = ret;
}
int main() {
  int k, i, m;
  scanf("%d", &k);
  m = k;
  int tk = k;
  while (k) {
    k /= 10;
    n++;
  }
  for (i = n - 1; i >= 0; i--) {
    val[i] = tk % 10;
    tk /= 10;
  }
  memset(dp, -1, sizeof(dp));
  memset(pos, 0, sizeof(pos));
  memset(ta, 0, sizeof(ta));
  for (i = 1; i <= n; i++) pos[i] = sol(0, i, 0);
  pos[0] = m;
  for (i = 1; i <= n; i++) pos[0] -= pos[i];
  int cur = 0, ret = 0;
  for (i = n; i >= 1; i--) {
    cur = pos[i];
    int rr = count(i - 1, 0);
    ret += (int)((long long)cur * (long long)(rr) % 1000000007);
    ret %= 1000000007;
  }
  printf("%d\n", ret);
  return 0;
}
