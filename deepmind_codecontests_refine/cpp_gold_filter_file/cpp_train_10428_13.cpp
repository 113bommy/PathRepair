#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[1002];
int d[1002][1003];
int mod = 998244353;
int f(int x) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) d[i][j] = 0;
  for (int i = 1; i <= n; i++) d[i][1] = 1;
  for (int j = 2; j <= k; j++) {
    int s = 0;
    for (int i = j, l = 1; i <= n; i++) {
      for (; l <= n && a[l] <= a[i] - x; l++) s = (s + d[l][j - 1]) % mod;
      d[i][j] = s;
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + d[i][k]) % mod;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  int ans = 0;
  for (int i = 1;; i++) {
    int res = f(i);
    if (!res) break;
    ans = (ans + res) % mod;
  }
  printf("%d\n", ans);
  return 0;
}
