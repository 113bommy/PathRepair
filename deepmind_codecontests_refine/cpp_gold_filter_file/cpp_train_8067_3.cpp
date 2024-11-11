#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, T;
int a[maxn * maxn];
int dp[maxn * maxn];
int s[maxn * maxn];
int p, v;
int maxv[(300 << 2) + 5];
void update(int o, int L, int R) {
  if (L == R) {
    maxv[o] = max(maxv[o], v);
    return;
  }
  int M = L + (R - L) / 2;
  int lc = o * 2, rc = o * 2 + 1;
  if (p <= M)
    update(lc, L, M);
  else
    update(rc, M + 1, R);
  maxv[o] = max(maxv[lc], maxv[rc]);
}
int ql, qr;
int query(int o, int L, int R) {
  if (ql <= L && R <= qr) return maxv[o];
  int ans = 0;
  int M = L + (R - L) / 2;
  int lc = o * 2, rc = o * 2 + 1;
  if (ql <= M) ans = max(ans, query(lc, L, M));
  if (M < qr) ans = max(ans, query(rc, M + 1, R));
  return ans;
}
int cnt[305];
int main() {
  while (cin >> n >> T) {
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    for (int i = n + 1; i <= min(T, n) * n; i++) a[i] = a[i - n];
    int top = 0;
    memset(s, 0, sizeof(s));
    memset(maxv, 0, sizeof(maxv));
    int ans = 0, anspos;
    for (int i = 1; i <= min(T, n) * n; i++) {
      ql = 1, qr = a[i];
      int L = query(1, 1, 300);
      dp[i] = L + 1;
      if (dp[i] > ans) {
        ans = dp[i];
        anspos = i;
      }
      p = a[i];
      v = dp[i];
      update(1, 1, 300);
    }
    int Max = 0;
    for (int i = 1; i <= 300; i++) Max = max(Max, cnt[i]);
    ans += Max * max(T - n, 0);
    cout << ans << endl;
  }
  return 0;
}
