#include <bits/stdc++.h>
const int MAXN = 100000;
const int LARGESTN = 1000000;
const int mod = 1000000007;
int num[LARGESTN];
int tree[LARGESTN + 1];
int a[MAXN + 1], val[MAXN + 1], pre[MAXN + 1];
void update(int x, int v) {
  for (++x; x <= LARGESTN; x += x & -x) {
    tree[x - 1] += v;
    if (tree[x - 1] >= mod) tree[x - 1] -= mod;
  }
}
int query(int x) {
  int ret = 0;
  for (++x; x; x -= x & -x) {
    ret += tree[x - 1];
    if (ret >= mod) ret -= mod;
  }
  return ret;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    pre[i] = num[a[i] - 1];
    num[a[i] - 1] = i;
  }
  a[0] = 0;
  val[0] = 0;
  update(0, 1);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int now = (long long)query(a[i]) * a[i] % mod;
    now -= (long long)val[pre[i]] * a[i] % mod;
    if (now < 0) now += mod;
    val[i] = query(a[i]);
    update(a[i], now);
    ans += now;
    if (ans >= mod) ans -= mod;
  }
  printf("%d\n", ans);
  return 0;
}
