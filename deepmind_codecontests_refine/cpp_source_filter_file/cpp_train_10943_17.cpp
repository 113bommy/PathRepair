#include <bits/stdc++.h>
using namespace std;
struct FENWICK {
  int n, tree[2 * 100010];
  void ini(int _n) {
    int i;
    n = _n;
    for (i = 1; i <= n; i++) {
      tree[i] = 0;
    }
  }
  void update(int p, int v) {
    while (p <= n) {
      tree[p] += v, p += (p & (-p));
    }
  }
  int query(int p) {
    int ret = 0;
    while (p) {
      ret += tree[p], p ^= (p & (-p));
    }
    return ret;
  }
  int query(int l, int r) {
    if (l > r) {
      return 0;
    }
    return (query(r) - query(--l));
  }
} yMatch, nMacth;
inline int add(int _a, int _b) {
  _a = (_a + 998244353) % 998244353;
  _b = (_b + 998244353) % 998244353;
  return (_a + _b) % 998244353;
}
inline int mul(int _a, int _b) {
  _a = (_a + 998244353) % 998244353;
  _b = (_b + 998244353) % 998244353;
  return ((long long int)((long long int)_a * (long long int)_b)) % 998244353;
}
inline int bigMod(int v, int p) {
  if (p == 0) {
    return 1;
  }
  int ret = bigMod(v, p / 2) % 998244353;
  if (p % 2 == 0) {
    return mul(ret, ret);
  } else {
    return mul(ret, mul(ret, v));
  }
}
int n, ara[2010][2010], fac[2 * 100010], inv[2 * 100010], invFac[2 * 100010],
    dp[2010][2010], dp1[2010], P[2010];
bool vis[2010][2010];
void factorial() {
  int i, j;
  for (i = 1, fac[0] = invFac[0] = 1; i <= 2 * 100010 - 2; i++) {
    fac[i] = mul(fac[i - 1], i);
    inv[i] = bigMod(i, 998244353 - 2);
    invFac[i] = mul(invFac[i - 1], inv[i]);
  }
}
void input() {
  int i, j;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &ara[i][j]);
    }
  }
}
int F(int m, int k) {
  if (m < 0 || k < 0) {
    return 0;
  }
  if (m == 0) {
    return fac[k];
  }
  if (vis[m][k]) {
    return dp[m][k];
  }
  vis[m][k] = true;
  int ret = 0;
  if (m - 2 >= 0) {
    ret = add(ret, mul(m - 1, F(m - 2, k)));
  }
  if (m - 1 >= 0) {
    ret = add(ret, mul(m - 1, F(m - 1, k)));
  }
  if (m - 1 >= 0) {
    ret = add(ret, mul(k, F(m - 1, k)));
  }
  return dp[m][k] = ret;
}
int D(int m) {
  int ret = 0;
  if (m == 0) {
    return 1;
  }
  if (dp1[m] != -1) {
    return dp1[m];
  }
  if (m - 1 >= 0) {
    ret = add(ret, mul(m - 1, D(m - 1)));
  }
  if (m - 2 >= 0) {
    ret = add(ret, mul(m - 1, D(m - 2)));
  }
  return dp1[m] = ret;
}
int G(int r, int c) {
  int m1 = yMatch.query(1, ara[r][c] - 1), k1 = nMacth.query(1, ara[r][c] - 1),
      ret = 0, i;
  int m2 = yMatch.query(1, n), k2 = nMacth.query(1, n);
  int yes = yMatch.query(ara[r - 1][c], ara[r - 1][c]);
  if (yes) {
    if (ara[r - 1][c] < ara[r][c]) {
      m1--;
    }
    ret = add(ret, mul(max(m1, 0), F(m2 - 2, k2 + 1)));
    ret = add(ret, mul(k1, F(m2 - 1, k2)));
    yes = yMatch.query(ara[r][c], ara[r][c]);
    if (yes) {
      yMatch.update(ara[r][c], -1);
      yMatch.update(ara[r - 1][c], -1);
      nMacth.update(ara[r - 1][c], +1);
    } else {
      nMacth.update(ara[r][c], -1);
      yMatch.update(ara[r - 1][c], -1);
      nMacth.update(ara[r - 1][c], +1);
    }
  } else {
    ret = add(ret, mul(m1, F(m2 - 1, k2)));
    ret = add(ret, mul(k1, F(m2, k2 - 1)));
    yes = yMatch.query(ara[r][c], ara[r][c]);
    if (yes) {
      yMatch.update(ara[r][c], -1);
    } else {
      nMacth.update(ara[r][c], -1);
    }
  }
  return ret;
}
void solve() {
  int i, j, sol = 0, v, u, x;
  for (i = 1, P[0] = 1; i <= n; i++) {
    P[i] = mul(P[i - 1], D(n));
  }
  for (i = 0; i < n; i++) {
    yMatch.ini(n), nMacth.ini(n);
    for (j = 1; j <= n; j++) {
      yMatch.update(j, 1);
    }
    for (j = 0; j < n; j++) {
      if (i == 0) {
        v = mul(yMatch.query(1, ara[i][j] - 1), fac[n - i - 1]);
        v = mul(v, P[n - i - 1]);
        yMatch.update(ara[i][j], -1);
        sol = add(sol, v);
        continue;
      }
      u = G(i, j);
      v = mul(u, P[n - i - 1]);
      sol = add(sol, v);
    }
  }
  printf("%d", sol);
  puts("");
}
int main() {
  memset(dp1, -1, sizeof(dp1));
  factorial();
  input();
  solve();
}
