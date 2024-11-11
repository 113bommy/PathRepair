#include <bits/stdc++.h>
using namespace std;
int dp[1 << 24], A[25][25];
int n, m, k, i, j, arr[(int)(1e5 + 10)];
int L[1 << 24];
int f(int mask, int t) {
  int &r = dp[mask >> 1];
  if (r != -1) return r;
  int p = 0, k = mask;
  r = n + 1;
  if (t == n) return r = __builtin_popcount(mask);
  for (int i = 1; i <= n; i++)
    if (((mask >> i) & 1) and ((mask >> A[i][t + 1]) & 1)) {
      p = 1;
      break;
    }
  if (!p) return r;
  for (int i = 1; i <= n; i++)
    if (((mask >> i) & 1)) r = min(r, f(mask ^ (1 << i) ^ (1 << t + 1), t + 1));
  r = min(r, f(mask ^ (1 << t + 1), t + 1));
  return r = max(r, __builtin_popcount(mask));
}
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) scanf("%d", arr + i);
  int tt = 1;
  for (i = 1; i <= n; i++) {
    tt *= 2;
    L[tt] = i;
  }
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
      for (k = 1; k <= n; k++)
        if (arr[i] + arr[k] == arr[j]) A[i][j] = k;
  int t = arr[1];
  if (arr[1] != t or arr[1] * 2 != arr[2]) {
    if (n != 1) putchar('-');
    puts("1");
    return 0;
  }
  memset(dp, -1, sizeof dp);
  if (f(2, 1) <= n)
    cout << dp[1] << '\n';
  else
    cout << -1 << '\n';
}
