#include <bits/stdc++.h>
using namespace std;
inline int add(int a) { return a >= 998244353 ? a - 998244353 : a; }
inline int dec(int a) { return a < 0 ? a + 998244353 : a; }
inline void Add(int &a, int b) { ((a += b) >= 998244353) && (a -= 998244353); }
inline void Dec(int &a, int b) { ((a -= b) < 0) && (a += 998244353); }
int ksm(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1ll * ans * a % 998244353;
    a = 1ll * a * a % 998244353;
    b >>= 1;
  }
  return ans;
}
int n, c, a[3005];
struct Wlj1 {
  int ans[3005], zt;
  void dfs(int p, int num, int nw) {
    if (nw == zt) nw = 0, ++num;
    if (p > n) {
      ++ans[num];
      return;
    }
    dfs(p + 1, num, nw);
    dfs(p + 1, num, nw | (1 << a[p] - 1));
  }
  void work() {
    zt = (1 << c) - 1;
    ans[0] = -1;
    dfs(1, 0, 0);
    for (int i = 0; i <= n; ++i) printf("%d ", ans[i]);
  }
} wlj1;
struct Wlj2 {
  int f[3005][1100], zt, lst[3005][1100], ans[3005];
  void work() {
    zt = (1 << c) - 1;
    lst[0][0] = 1;
    for (int up, i = 1; i <= n; ++i) {
      memset(f, 0, sizeof f);
      up = (i - 1) / c;
      for (int j = 0; j <= up; ++j) {
        for (int k = 0; k < zt; ++k) {
          Add(f[j][k | (1 << a[i] - 1)], lst[j][k]);
        }
        f[j + 1][0] = f[j][zt];
      }
      up = i / c;
      for (int j = 0; j <= up; ++j) {
        for (int k = 0; k < zt; ++k) Add(lst[j][k], f[j][k]);
      }
    }
    ans[0] = -1;
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j < zt; ++j) Add(ans[i], lst[i][j]);
      printf("%d ", ans[i]);
    }
  }
} wlj2;
struct Wlj3 {
  int f[3005][3005], val[3005][3005], cnt[3005], js, ans, pw[3005], invpw[3005],
      Ans[3005];
  int rv[3005];
  void work() {
    for (int i = 1; i <= n; ++i)
      pw[i] = ksm(2, i) - 1, invpw[i] = ksm(pw[i], 998244353 - 2);
    for (int i = 1; i <= n; ++i) {
      js = c;
      memset(cnt, 0, sizeof cnt);
      for (int j = i; j <= n; ++j) {
        ++cnt[a[j]];
        if (cnt[a[j]] == 1) {
          --js;
          if (!js) {
            ans = 1;
            for (int k = 1; k <= c; ++k)
              ans = 1ll * ans * pw[cnt[k]] % 998244353;
          }
        } else
          ans = 1ll * ans * pw[cnt[a[j]]] % 998244353 * invpw[cnt[a[j]] - 1] %
                998244353;
        if (!js) {
          val[i][j] = 1ll * ans * invpw[cnt[a[j]]] % 998244353;
        }
      }
      rv[i] = 1;
      for (int k = 1; k <= c; ++k) rv[i] = 1ll * rv[i] * pw[cnt[k]] % 998244353;
      rv[i] = dec(ksm(2, n - i + 1) - rv[i]);
    }
    rv[n + 1] = 1;
    f[0][0] = 1;
    for (int up, i = c; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (!val[j + 1][i]) break;
        up = j / c;
        for (int k = 0; k <= up; ++k) {
          if (!f[j][k]) continue;
          f[i][k + 1] =
              (f[i][k + 1] + 1ll * f[j][k] * val[j + 1][i]) % 998244353;
        }
      }
    }
    for (int up, i = 1; i <= n; ++i) {
      up = i / c;
      for (int j = 1; j <= up; ++j)
        Add(Ans[j], 1ll * f[i][j] * rv[i + 1] % 998244353);
    }
    int ttans = 0;
    for (int i = 1; i <= n; ++i) Add(ttans, Ans[i]);
    Ans[0] = dec(pw[n] - ttans);
    for (int i = 0; i <= n; ++i) printf("%d ", Ans[i]);
  }
} wlj3;
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  if (n <= 20)
    wlj1.work();
  else if (c <= 9)
    wlj2.work();
  else
    wlj3.work();
  return 0;
}
