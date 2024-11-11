#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const long long inf = 1e18;
template <typename T>
void chkmin(T &x, T y) {
  if (y < x) x = y;
}
template <typename T>
void chkmax(T &x, T y) {
  if (y > x) x = y;
}
template <typename T>
void upd(T &x, T y) {
  if ((x += y) >= mod) x -= mod;
}
int n, K, sl, fh, tot, num[1 << 14], trs[15][1010];
long long ans, w[15][1010], f[1 << 14][1010];
char s[1000010];
struct ACAM {
  int fil, sn[14];
  long long val;
  int &operator[](const int &x) { return sn[x]; }
} tr[1000010];
queue<int> q;
int rd() {
  sl = 0;
  fh = 1;
  char ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') fh = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') sl = sl * 10 + ch - '0', ch = getchar();
  return sl * fh;
}
void ins(char *c, int x) {
  int d, u = 0, L = strlen(c + 1);
  for (int i = 1; i <= L; ++i) {
    d = c[i] - 'a';
    if (!tr[u][d]) tr[u][d] = ++tot;
    u = tr[u][d];
  }
  tr[u].val += x;
}
void build() {
  for (int i = 0; i < 14; ++i)
    if (tr[0][i]) q.push(tr[0][i]);
  int u, v;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    tr[u].val += tr[tr[u].fil].val;
    for (int i = 0; i < 14; ++i)
      if ((v = tr[u][i]))
        tr[v].fil = tr[tr[u].fil][i], q.push(v);
      else
        tr[u][i] = tr[tr[u].fil][i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  K = rd();
  for (int x, i = 1; i <= K; ++i) {
    scanf("%s%d", s + 1, &x);
    ins(s, x);
  }
  build();
  scanf("%s", s + 1);
  K = 0;
  n = strlen(s + 1);
  for (int j, i = 0; i <= n; ++K, i = j) {
    for (j = i + 1; j <= n && s[j] != '?'; ++j)
      ;
    for (int u, p = 0; p <= tot; ++p) {
      u = p;
      for (int k = i + 1; k < j; ++k) {
        u = tr[u][s[k] - 'a'];
        w[K][p] += tr[u].val;
      }
      trs[K][p] = u;
    }
  }
  memset(f, -127, sizeof(f));
  f[0][trs[0][0]] = w[0][0];
  --K;
  ans = -inf;
  for (int j, i = 0; i < 1 << 14; ++i) {
    num[i] = j = num[i >> 1] + (i & 1);
    if (j >= K)
      for (int p = 0; p <= tot; ++p) chkmax(ans, f[i][p]);
    else if (j < K)
      for (int p = 0; p <= tot; ++p)
        for (int c = 0; c < 14; ++c)
          if (!((i >> c) & 1))
            chkmax(f[i | (1 << c)][trs[j][tr[p][c]]],
                   f[i][p] + tr[tr[p][c]].val + w[j + 1][tr[p][c]]);
  }
  printf("%lld\n", ans);
  return 0;
}
