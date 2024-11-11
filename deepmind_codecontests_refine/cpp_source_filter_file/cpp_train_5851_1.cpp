#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7, M = 30;
long long ans, sum[N], f3[M][N], f4[M][N];
char s[N];
int n, k, z, lt[N], rt[N], vt[N], z1[M], z2[M], pre[N][M], nxt[N][M], c1[N][M],
    c2[N][M], f1[M][N], f2[M][N], p1[N][M], p2[N][M];
bool op[M], fa[N][M], fb[N][M];
inline bool cmp1(int a, int b) {
  if (!fa[k][a] || !fa[k][b]) return fa[k][a] > fa[k][b];
  return pre[k + 1][a] > pre[k + 1][b];
}
inline bool cmp2(int a, int b) {
  if (!fb[k][a] || !fb[k][b]) return fb[k][a] > fb[k][b];
  return nxt[k - 1][a] < nxt[k - 1][b];
}
inline bool check(int l, int r, int t) {
  if (t == 27) return 1;
  return (!fa[r][c1[r][t]] || pre[r + 1][c1[r][t]] < l);
}
int main() {
  scanf("%s", s + 1), n = strlen(s + 1);
  s[0] = s[n + 1] = 'a';
  for (int i = 1; i <= n; i++) op[s[i] - 'a'] = 1;
  for (int x = 0; x <= 25; x++) pre[1][x] = 1, nxt[n][x] = n;
  fa[1][s[1] - 'a'] = 1, fb[n][s[n] - 'a'] = 1;
  for (int i = 2; i <= n + 1; i++) {
    memcpy(fa[i], fa[i - 1], sizeof(fa[i]));
    memcpy(pre[i], pre[i - 1], sizeof(pre[i]));
    pre[i][s[i - 1] - 'a'] = i - 1, fa[i][s[i] - 'a'] = 1;
  }
  for (int i = n - 1; i >= 0; i--) {
    memcpy(fb[i], fb[i + 1], sizeof(fb[i]));
    memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
    nxt[i][s[i + 1] - 'a'] = i + 1, fb[i][s[i] - 'a'] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int x = 0; x <= 25; x++) z1[x] = z2[x] = x;
    k = i;
    sort(z1, z1 + 26, cmp1), sort(z2, z2 + 26, cmp2);
    for (int x = 0; x <= 25; x++) c1[i][x] = z1[x], c2[i][x] = z2[x];
  }
  for (int i = 0; i <= 25; i++)
    if (op[i]) z++;
  for (int i = 1; i <= n; i++) lt[i] = rt[i] = i;
  for (int t = 1; t <= z + 1; t++) {
    for (int x = 1; x <= n; x++) {
      if (t == 1) {
        f1[0][x] = pre[x][c2[x][t - 1]];
        f2[0][x] = nxt[x][c1[x][t - 1]];
      } else {
        f1[0][x] = min(f1[0][x], pre[x][c2[x][t - 1]]);
        f2[0][x] = max(f2[0][x], nxt[x][c1[x][t - 1]]);
      }
      f3[0][x] = f1[0][x], f4[0][x] = f2[0][x], p1[0][x] = x, p2[0][x] = x;
    }
    for (int i = 1; i <= 18; i++)
      for (int x = 1; x <= n; x++) {
        f1[i][x] = f1[i - 1][f1[i - 1][x]],
        f3[i][x] = f3[i - 1][x] + f3[i - 1][f1[i - 1][x]];
        f2[i][x] = f2[i - 1][f2[i - 1][x]],
        f4[i][x] = f4[i - 1][x] + f4[i - 1][f2[i - 1][x]];
        p1[i][x] = f1[i - 1][p1[i - 1][x]], p2[i][x] = f2[i - 1][p2[i - 1][x]];
      }
    for (int x = 1; x <= n; x++) {
      if (!check(lt[x], rt[x], t)) continue;
      for (int i = 18; i >= 0; i--) {
        if (vt[x] + (1 << i) <= n && check(p1[i][lt[x]], p2[i][rt[x]], t)) {
          sum[x] = sum[x] + f4[i][rt[x]] - f3[i][lt[x]];
          lt[x] = f1[i][lt[x]], rt[x] = f2[i][rt[x]], vt[x] = vt[x] + (1 << i);
        }
      }
    }
  }
  ans = 1ll * (n - 1) * n * (n + 1);
  for (int i = 1; i <= n; i++) ans -= sum[i];
  cout << ans << endl;
  return 0;
}
