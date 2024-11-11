#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, w = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') ch = getchar(), w = -1;
  while (ch >= '0' && ch <= '9')
    x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return x * w;
}
int n, ks;
const int N = 505;
struct Rey {
  char s[N];
  int m;
  int len;
} a[N];
long long ans = 0;
int T[N][15];
int ed[N];
int cnt = 1;
inline void insert(Rey x) {
  int now = 1;
  for (int i = 0; i < x.len; i++) {
    int ch = x.s[i] - '0';
    if (!T[now][ch]) T[now][ch] = ++cnt;
    now = T[now][ch];
  }
  ed[now] += x.m;
}
int siz[N], fa[N][N];
int f[N][N][15];
int tmp[N][N];
int dep[N], val[N];
inline void dfs(int x) {
  fa[x][0] = x;
  siz[x] = 1;
  for (int i = 0; i <= val[x]; i++) {
    f[x][i][!i] = dep[fa[x][i]] * ed[x];
  }
  for (int i = 0; i <= 9; i++) {
    if (T[x][i]) {
      int p = T[x][i];
      dep[p] = dep[x] + 1;
      for (int j = 0; j <= val[x]; j++) fa[p][++val[p]] = fa[x][j];
      dfs(p);
      for (int j = 0; j <= val[x]; j++) {
        for (int k = 0; k <= siz[x] && k <= ks; k++) {
          tmp[j][k] = f[x][j][k];
          f[x][j][k] = -(1 << 30);
        }
      }
      for (int j = 0; j <= val[x]; j++) {
        for (int k = 0; k <= siz[x] && k <= ks; k++) {
          for (int l = 0; l <= siz[p] && k + l <= ks; l++) {
            f[x][j][k + l] =
                std::max(f[x][j][k + l],
                         tmp[j][k] + std::max(f[p][j + 1][l], f[p][0][l]));
          }
        }
      }
      siz[x] += siz[p];
    }
  }
}
int main() {
  n = read(), ks = read() + 1;
  memset(f, 0xc0, sizeof(f));
  for (int i = 1; i <= n; i++) {
    cin >> a[i].s;
    a[i].len = strlen(a[i].s);
    a[i].m = read();
    ans += 1ll * a[i].m * a[i].len;
    insert(a[i]);
  }
  dfs(1);
  int mxn = 0;
  for (int i = 1; i <= ks; i++) mxn = std::max(mxn, f[1][0][i]);
  ans -= mxn;
  printf("%lld\n", ans);
  return 0;
}
