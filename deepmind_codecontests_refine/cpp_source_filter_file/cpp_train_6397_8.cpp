#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
const int mod = 1e9 + 7;
int n, m = 0x3f3f3f3f, id[maxn], ans[maxn], f[maxn], sum[maxn][3], pos[maxn];
int sa[maxn], tax[maxn], rnk[maxn], tp[maxn], h[maxn];
char s[maxn], t[maxn];
inline void SA() {
  register int i, k, p, f = 0, m = 128;
  for (i = 1; i <= n; i++) rnk[i] = s[i];
  for (i = 1; i <= n; i++) tax[rnk[i]]++;
  for (i = 1; i <= m; i++) tax[i] += tax[i - 1];
  for (i = n; i >= 1; i--) sa[tax[rnk[i]]--] = i;
  for (k = 1, p = 0; k < n; k <<= 1, m = p) {
    p = 0;
    for (i = n - k + 1; i <= n; i++) tp[++p] = i;
    for (i = 1; i <= n; i++)
      if (sa[i] > k) tp[++p] = sa[i] - k;
    for (i = 1; i <= m; i++) tax[i] = 0;
    for (i = 1; i <= n; i++) tax[rnk[i]]++;
    for (i = 1; i <= m; i++) tax[i] += tax[i - 1];
    for (i = n; i >= 1; i--) sa[tax[rnk[tp[i]]]--] = tp[i];
    swap(rnk, tp);
    rnk[sa[1]] = p = 1;
    for (i = 2; i <= n; i++)
      rnk[sa[i]] =
          (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + k] == tp[sa[i] + k])
              ? p
              : ++p;
  }
  for (i = 1; i <= n; i++) rnk[sa[i]] = i;
  for (i = 1; i <= n; i++) {
    p = sa[rnk[i] - 1];
    if (f) f--;
    while (s[p + f] == s[i + f]) f++;
    h[rnk[i]] = f;
  }
}
inline int find(int x) { return (x == f[x]) ? x : f[x] = find(f[x]); }
inline int F(int x) {
  return 1ll * sum[x][0] * sum[x][1] % mod * sum[x][2] % mod;
}
inline bool cmp(const int &x, const int &y) { return h[x] > h[y]; }
inline void add(int &x, int y) { ((x += y) >= mod) ? x -= mod : 0; }
int main() {
  for (int i = 1; i <= 3; i++) {
    scanf("%s", t + 1);
    int len = strlen(t + 1);
    for (int j = 1; j <= len; j++) s[n + j] = t[j], pos[n + j] = i;
    n += len;
    s[++n] = '$' + i;
    m = min(m, len);
  }
  SA();
  for (int i = 1; i <= n; i++)
    if (pos[i]) sum[rnk[i]][pos[i]]++;
  for (int i = 1; i <= n; i++) id[i] = f[i] = i;
  sort(id + 1, id + n + 1, cmp);
  int now = 0;
  for (int i = m, j = 1; i >= 1; i--) {
    for (; j <= n && h[id[j]] >= i; j++) {
      int x = find(id[j] - 1), y = find(id[j]);
      add(now, mod - F(x));
      add(now, mod - F(y));
      for (int k = 0; k < 3; k++) sum[x][k] += sum[y][k];
      add(now, F(x));
      f[y] = x;
    }
    ans[i] = now;
  }
  for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  return 0;
}
