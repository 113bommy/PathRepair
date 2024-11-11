#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, m, k, mod;
int cnt[N], val[N];
int two[N], ans;
void init() {
  scanf("%d%d%d", &n, &m, &k);
  bool flag = 0;
  if (n < m) {
    swap(n, m);
    flag = 1;
  }
  for (int i = 1; i <= n; i++) val[i] = 1;
  for (int i = 1, x, y, v; i <= k; i++) {
    scanf("%d%d%d", &x, &y, &v);
    if (flag) swap(x, y);
    ++cnt[x];
    val[x] *= v;
  }
  scanf("%d", &mod);
}
void solve() {
  if ((n + m) & 1) {
    printf("0\n");
    return;
  }
  for (int i = 1; i <= n; i++)
    if (cnt[i] == m && val[i] == 1) {
      printf("0\n");
      return;
    }
  for (int i = 1; i <= n; i++)
    if (!cnt[i]) {
      swap(cnt[i], cnt[n]);
      swap(val[i], val[n]);
    }
  two[0] = 1;
  for (int i = 1; i <= m; i++) two[i] = two[i - 1] * 2 % mod;
  ans = 1;
  for (int i = 1; i < n; i++)
    if (cnt[i] < m) ans = (long long)(ans)*two[m - cnt[i] - 1] % mod;
  printf("%d\n", ans);
}
int main() {
  init();
  solve();
  return 0;
}
