#include <bits/stdc++.h>
using namespace std;
const int Mod = 998244353;
int fpow(int a, int b) {
  int ans = 1, t = a;
  while (b) {
    if (b & 1) ans = 1ll * ans * t % Mod;
    t = 1ll * t * t % Mod;
    b >>= 1;
  }
  return ans;
}
int n;
struct BIT {
  int c[2010];
  int lowbit(int x) { return x & (-x); }
  void add(int x, int y) {
    for (; x <= n; x += lowbit(x)) c[x] += y;
    return;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += c[x];
    return ans;
  }
  void clear() {
    memset(c, 0, sizeof(c));
    return;
  }
} A, B, C;
int f[2010][2010];
void init() {
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i][0] = 1ll * f[i - 1][0] * i % Mod;
    for (int j = 1; j <= i; j++)
      f[i][j] = (f[i][j - 1] - f[i - 1][j - 1] + Mod) % Mod;
  }
  return;
}
int vis[2010];
int pos[2010];
int solve(int* p, int* q) {
  int ans = 0;
  A.clear();
  B.clear();
  C.clear();
  for (int i = 1; i <= n; i++) {
    pos[p[i]] = i;
    A.add(i, 1);
    B.add(i, 1);
    C.add(i, 1);
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++) {
    vis[q[i]] = 1;
    B.add(q[i], -1);
    if (!vis[p[i]]) C.add(p[i], -1);
    int cnt = A.query(n) - A.query(i);
    int cnt1 = B.query(q[i] - 1);
    if (!vis[p[i]] && p[i] < q[i]) cnt1--;
    int cnt2 = C.query(q[i] - 1);
    cnt1 -= cnt2;
    if (cnt1) ans = (ans + 1ll * cnt1 * f[n - i][cnt]) % Mod;
    if (cnt2) ans = (ans + 1ll * cnt2 * f[n - i][cnt - 1]) % Mod;
    A.add(pos[q[i]], -1);
    if (pos[q[i]] > i) C.add(q[i], -1);
    vis[q[i]] = true;
  }
  return ans;
}
int a[2010][2010];
int main() {
  scanf("%d", &n);
  init();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) scanf("%d", &a[i][j]);
  A.clear();
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    A.add(a[1][i], 1);
    int cnt = i - A.query(a[1][i]);
    ans = (ans + 1ll * cnt * f[n - i][0]) % Mod;
  }
  ans = 1ll * ans * fpow(f[n][n], n - 1) % Mod;
  for (int i = 2; i <= n; i++)
    ans = (ans + 1ll * solve(a[i - 1], a[i]) * fpow(f[n][n], n - i)) % Mod;
  printf("%d\n", ans);
  return 0;
}
