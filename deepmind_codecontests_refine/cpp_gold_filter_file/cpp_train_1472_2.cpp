#include <bits/stdc++.h>
using namespace std;
int i, j, m, n, k, p[1000005], vis[1000005], cnt, ans, tree[2][1000005], cur;
int power(int x, int y) {
  int sum = 1;
  for (; y; y >>= 1) {
    if (y & 1) sum = 1ll * sum * x % 998244353;
    x = 1ll * x * x % 998244353;
  }
  return sum;
}
int lowbit(int x) { return x & -x; }
void insert(int x, int y) {
  for (; x <= n; x += lowbit(x)) tree[y][x]++;
}
int ask(int x, int y) {
  int s = 0;
  for (; x; x -= lowbit(x)) s += tree[y][x];
  return s;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    if (p[i] == -1)
      ++cnt;
    else
      vis[p[i]] = 1;
  }
  for (i = 1; i <= n; ++i)
    if (!vis[i]) insert(i, 0);
  ans = 1ll * cnt * (cnt - 1) % 998244353 * power(2, 998244353 - 2) %
        998244353 * power(2, 998244353 - 2) % 998244353;
  for (i = 1; i <= n; ++i)
    if (p[i] == -1)
      cur++;
    else {
      int a = ask(p[i], 0), b = ask(n, 1) - ask(p[i], 1), c = cnt - a;
      (ans += b) %= 998244353;
      ans = (ans + 1ll * cur * c % 998244353 * power(cnt, 998244353 - 2) %
                       998244353) %
            998244353;
      ans = (ans + 1ll * (cnt - cur) * a % 998244353 *
                       power(cnt, 998244353 - 2) % 998244353) %
            998244353;
      insert(p[i], 1);
    }
  printf("%d\n", ans);
}
