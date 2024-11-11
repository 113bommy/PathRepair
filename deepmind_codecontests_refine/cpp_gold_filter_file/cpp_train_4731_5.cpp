#include <bits/stdc++.h>
using namespace std;
const int MaxN = 25;
int a[MaxN], sum[1 << 15];
int dp[MaxN][MaxN][1 << 15];
int n, leaf, x;
bool f(int u, int leaf, int mask) {
  if (leaf < 0) return false;
  if (u == 0 && !leaf) return true;
  if (u == 0) return false;
  int &r = dp[u][leaf][mask];
  if (r != -1) return r;
  r = false;
  for (int i = 0; i < (1 << (u - 1)); i++)
    if (!(i & mask) && sum[i] <= a[u] - 1 &&
        __builtin_popcount(i) + a[u] - (sum[i] + 1) >= 2)
      r = max(r, (int)f(u - 1, leaf - (a[u] - (sum[i] + 1)), mask | i));
  return r;
}
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int s = 0;
  memset(dp, -1, sizeof dp);
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x == 1)
      ++leaf;
    else
      a[++s] = x;
  }
  if (n == 1 && leaf == 1) {
    cout << "YES" << endl;
    return 0;
  }
  if (leaf < n / 2) {
    cout << "NO" << endl;
    return 0;
  }
  n = s;
  sort(a + 1, a + 1 + n);
  for (int i = 0; i < (1 << n); i++)
    for (int j = 1; j <= n; j++)
      if ((1 << (j - 1) & i)) sum[i] += a[j];
  cout << (f(n, leaf, 0) ? "YES" : "NO") << endl;
  return 0;
}
