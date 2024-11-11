#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7, maxn = 4e5 + 5, maxm = 20, inf = 1e18 + 5;
int a[maxn], cnt[maxm];
long long t[maxm][maxm];
long long f[maxm][1 << maxm], dp[1 << maxm];
int main() {
  long long n;
  cin >> n;
  map<int, int> d;
  for (int i = (0); i < n; i++) {
    cin >> a[i];
    if (d.find(a[i]) == d.end()) d[a[i]] = (int)(d).size();
  }
  long long r = (int)(d).size();
  for (int i = (0); i < n; i++) a[i] = d[a[i]], a[i]--;
  for (int i = (n - 1); i >= 0; i--) {
    for (int j = (0); j < r; j++) t[a[i]][j] += cnt[j];
    cnt[a[i]]++;
  }
  for (int s = (1); s < 1 << r; s++) {
    if (__builtin_popcount(s) == 1) continue;
    long long l1 = 0;
    while ((s & (1 << l1)) == 0) l1++;
    long long l2 = l1 + 1;
    while ((s & (1 << l2)) == 0) l2++;
    for (int i = (0); i < r; i++) {
      if ((s & (1 << i)) == 0) continue;
      if (i != l1)
        f[i][s] = f[i][s ^ (1 << l1)] + t[l1][i];
      else
        f[i][s] = f[i][s ^ (1 << l2)] + t[l2][i];
    }
  }
  for (int s = (1); s < 1 << r; s++) {
    dp[s] = inf;
    long long t = s ^ ((1 << r) - 1);
    for (int i = (0); i < r; i++) {
      if (s & (1 << i)) {
        dp[s] = min(dp[s], dp[s ^ (1 << i)] + f[i][t ^ (1 << i)]);
      }
    }
  }
  cout << dp[(1 << r) - 1];
  return 0;
}
