#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int SUM = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    SUM = (SUM << 3) + (SUM << 1) + (ch ^ 48);
    ch = getchar();
  }
  return SUM * ff;
}
const int N = 100010;
const int M = 25;
const long long inf = 1ll << 50;
int a[N];
int n, k;
long long dp[M][N];
int cnt[N], L, R;
long long ans = 0;
inline void add(int pos) {
  ans += cnt[pos];
  cnt[pos]++;
}
inline void del(int pos) {
  cnt[pos]--;
  ans -= cnt[pos];
}
inline void modify(int l, int r) {
  while (L < l) del(a[L++]);
  while (L > l) add(a[--L]);
  while (R < r) add(a[++R]);
  while (R > r) del(a[R--]);
}
inline void solve(int pos, int l, int r, int nL, int nR) {
  if (l > r) return;
  int mid = (l + r) >> 1, m = 0;
  long long res = inf;
  for (int i = nL; i <= nR && i <= mid; i++) {
    modify(i, mid);
    if (dp[pos - 1][i - 1] + ans < res) {
      res = dp[pos - 1][i - 1] + ans;
      m = i;
    }
  }
  dp[pos][mid] = res;
  solve(pos, l, mid - 1, nL, m);
  solve(pos, mid + 1, r, m, nR);
}
int main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  cnt[a[1]]++;
  L = 1, R = 1;
  memset(dp, 0x3f, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 1; i <= k; i++) solve(i, 1, n, 1, n);
  printf("%d\n", dp[k][n]);
  return 0;
}
