#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, head[200005], nxt[200005 << 1], to[200005 << 1], cnt = 0, fa[200005];
long long a[200005];
void add(int x, int y) {
  cnt++;
  to[cnt] = y;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
struct point {
  int num;
  long long c[105];
  signed d[105];
  void clear() {
    num = 0;
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
  }
};
long long gcd(long long x, long long y) {
  if (y == 0) return x;
  return gcd(y, x % y);
}
long long ans = 0;
point t, xx;
void dfs(int x, point u) {
  for (int i = 1; i <= u.num; i++) {
    ans += (u.c[i] % mod * u.d[i] % mod) % mod;
    ans %= mod;
  }
  for (int p = head[x]; p; p = nxt[p]) {
    int v = to[p];
    if (v != fa[x]) {
      fa[v] = x;
      t.clear();
      for (int i = 1; i <= u.num; i++) {
        long long tmp = gcd(u.c[i], a[v]);
        if (t.num && t.c[t.num] == tmp)
          t.d[t.num] += u.d[i];
        else {
          t.num++;
          t.c[t.num] = tmp;
          t.d[t.num] = u.d[i];
        }
      }
      if (t.num && t.c[t.num] == a[v])
        t.d[t.num]++;
      else {
        t.num++;
        t.c[t.num] = a[v];
        t.d[t.num] = 1;
      }
      dfs(v, t);
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  xx.clear();
  xx.num = 1;
  xx.c[1] = a[1], xx.d[1] = 1;
  dfs(1, xx);
  cout << ans << endl;
  return 0;
}
