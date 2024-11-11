#include <bits/stdc++.h>
using namespace std;
stringstream ss;
long long mod = 1000000007LL;
int n;
int a[32], b[32], m[64];
int dp[110][1 << 17];
int par[110][1 << 17];
int p[32], k = 0;
int f(int pos, int mask) {
  if (pos == n) return 0;
  if (dp[pos][mask] != -1) return dp[pos][mask];
  int ret = 100000000;
  par[pos][mask] = 1;
  for (int i = 1; i <= a[pos] + a[pos]; i++)
    if (!(mask & m[i])) {
      int r = abs(a[pos] - i) + f(pos + 1, mask | m[i]);
      if (r < ret) ret = r, par[pos][mask] = i;
    }
  return dp[pos][mask] = ret;
}
void path(int pos, int mask) {
  if (pos == n) return;
  b[pos] = par[pos][mask];
  path(pos + 1, mask | m[par[pos][mask]]);
}
int main() {
  for (int i = 2; k < 17; i++) {
    int bad = 0;
    for (int j = 2; j < i; j++)
      if (i % j == 0) bad = 1;
    if (bad) continue;
    p[k++] = i;
    for (int j = 0; j <= 60; j++)
      if (j % i == 0) m[j] |= (1LL << k - 1);
  }
  m[0] = 0;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, -1, sizeof dp);
  f(0, 0);
  path(0, 0);
  for (int i = 0; i < n; i++) cout << b[i] << " ";
  cout << endl;
  return 0;
}
