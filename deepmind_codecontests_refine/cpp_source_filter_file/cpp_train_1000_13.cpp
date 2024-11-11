#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::min;
using std::sort;
const int N = 100010;
int n, col[N], m, K, each, tot;
long long ans, cnt[N];
int main() {
  scanf("%d%d%d", &n, &K, &m);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    if (!tot || x != col[tot]) {
      col[++tot] = x;
      cnt[tot] = 1;
    } else
      ++cnt[tot];
    if (cnt[tot] >= K) {
      ++each;
      cnt[tot] -= K;
      if (!cnt[tot]) --tot;
    }
  }
  each *= K;
  if (tot == 1) {
    ans = m * cnt[tot];
    cout << ans % K << endl;
    return 0;
  }
  if (m == 1) {
    cout << n - each << endl;
    return 0;
  }
  int j = 0;
  while (j + j <= tot - 4 && col[tot - j] == col[1 + j] &&
         (cnt[tot - j] + cnt[1 + j]) % K == 0) {
    ++j;
  }
  if (1 + j == tot - j) {
    ans = cnt[1 + j] * m % K;
    if (ans) {
      for (int i = 1; i <= j; ++i) ans += cnt[i];
      for (int i = tot - j + 1; i <= tot; ++i) ans += cnt[i];
    }
    cout << ans << endl;
    return 0;
  }
  long long tmp = 0;
  for (int i = 1 + j; i <= tot - j; ++i) tmp += cnt[i];
  ans = tmp * (m - 1) + n - each;
  if (col[1 + j] == col[tot - j]) {
    tmp = (cnt[1 + j] + cnt[tot - j]) / K;
    ans -= tmp * (m - 1);
  }
  cout << ans << endl;
  return 0;
}
