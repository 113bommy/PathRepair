#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;
const int MAXN = 6003;
int n, c;
int a[MAXN], dp[MAXN][MAXN / 10], pre[MAXN], pre2[MAXN], cnt[MAXN], inv[MAXN],
    dp2[2][3003][1 << 10], vis[2][3003][1 << 10], preval[6003][6003];
int quick(int A, int B) {
  if (B == 0) return 1;
  int tmp = quick(A, B >> 1);
  tmp = 1ll * tmp * tmp % MOD;
  if (B & 1) tmp = 1ll * tmp * A % MOD;
  return tmp;
}
void add(int& A, int B) {
  A += B;
  if (A >= MOD) A -= MOD;
}
void solve1() {
  for (int i = 1; i <= n; ++i) a[i]--;
  dp2[1][0][0] = 1;
  vis[1][0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= i / c; ++j) {
      for (int mask = 0; mask < 1 << c; ++mask) {
        if (vis[i & 1][j][mask] == i) {
          bool nex = (i & 1) ^ 1;
          if (vis[nex][j][mask] != i + 1) {
            vis[nex][j][mask] = i + 1;
            dp2[nex][j][mask] = 0;
          }
          int nxmask = mask | (1 << a[i]);
          int nj = 0;
          if (nxmask == (1 << c) - 1) nxmask = 0, nj = 1;
          if (vis[nex][j + nj][nxmask] != i + 1) {
            vis[nex][j + nj][nxmask] = i + 1;
            dp2[nex][j + nj][nxmask] = 0;
          }
          add(dp2[nex][j][mask], dp2[i & 1][j][mask]);
          add(dp2[nex][j + nj][nxmask], dp2[i & 1][j][mask]);
        }
      }
    }
  }
  for (int i = 0; i <= n; ++i) {
    int rest = 0;
    for (int mask = 0; mask < 1 << c; ++mask) {
      add(rest, dp2[(n & 1) ^ 1][i][mask]);
    }
    if (i == 0) add(rest, MOD - 1);
    printf("%d ", rest);
  }
}
int main() {
  scanf("%d%d", &n, &c);
  for (int i = 0; i <= n + c; ++i)
    pre[i] = quick(2, i) - 1, pre2[i] = quick(2, i),
    inv[i] = quick(pre[i], MOD - 2);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= c; ++i) a[i + n] = i;
  if (c <= 10) {
    solve1();
    return 0;
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n + c; ++i) {
    for (int j = 1; j <= c; ++j) {
      cnt[j] = 0;
    }
    int val = 0;
    int cnt_zero = c;
    for (int j = i; j >= 1; --j) {
      cnt[a[j]]++;
      if (cnt[a[j]] == 1) {
        cnt_zero--;
      }
      if (val) {
        if (a[j] != a[i]) {
          if (i >= n + a[j]) {
            if (cnt[a[j]] != 1) val = val << 1;
            if (val >= MOD) val -= MOD;
          } else {
            if (cnt[a[j]] != 1) val = 1ll * val * inv[cnt[a[j]] - 1] % MOD;
            val = 1ll * pre[cnt[a[j]]] * val % MOD;
          }
        }
      } else {
        if (cnt_zero == 0) {
          cnt_zero = INF;
          val = 1;
          for (int l = 1; l <= c; ++l) {
            if (l == a[i])
              ;
            else {
              if (i >= n + l) {
                val = 1ll * val * pre2[cnt[l] - 1] % MOD;
              } else {
                val = 1ll * val * pre[cnt[l]] % MOD;
              }
            }
          }
        }
      }
      preval[j][i] = val;
    }
  }
  for (int j = 0; j <= n + c - 1; ++j) {
    for (int k = 0; k <= j / c; ++k) {
      if (dp[j][k])
        for (int i = j + 1; i <= n + c; ++i) {
          add(dp[i][k + 1], 1ll * preval[j + 1][i] * dp[j][k] % MOD);
        }
    }
  }
  for (int i = 0; i <= n; ++i) {
    int rest = 0;
    for (int j = n + 1; j <= n + c; ++j) {
      add(rest, dp[j][i + 1]);
    }
    if (i == 0) add(rest, MOD - 1);
    printf("%d ", rest);
  }
  return 0;
}
