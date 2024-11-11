#include <bits/stdc++.h>
const int N = 1000005;
using namespace std;
int cnt, e, ter[N], nxt[N], lnk[N], cov[N], a[N][26], mx[N], fail[N];
char s[N];
long long ans;
int extend(int p, int c) {
  if (a[p][c] && mx[a[p][c]] == mx[p] + 1) return a[p][c];
  int np = ++cnt;
  mx[np] = mx[p] + 1;
  for (; p && !a[p][c]; p = fail[p]) a[p][c] = np;
  if (!p)
    fail[np] = 1;
  else {
    int q = a[p][c];
    if (mx[q] == mx[p] + 1)
      fail[np] = q;
    else {
      int nq = ++cnt;
      mx[nq] = mx[p] + 1;
      memcpy(a[nq], a[q], sizeof(a[q]));
      fail[nq] = fail[q];
      fail[q] = fail[np] = nq;
      for (; a[p][c] == q; p = fail[p]) a[p][c] = nq;
    }
  }
  return np;
}
void add(int x, int y) { ter[++e] = y, nxt[e] = lnk[x], lnk[x] = e; }
void dfs(int p) {
  for (int i = lnk[p]; i; i = nxt[i]) {
    dfs(ter[i]);
    cov[p] += cov[ter[i]];
    ans +=
        (long long)(mx[ter[i]] - mx[p]) * (long long)cov[ter[i]] * cov[ter[i]];
  }
}
int main() {
  int T;
  scanf("%d", &T);
  for (int cas = 1; cas <= T; ++cas) {
    memset(cov, 0, sizeof(cov));
    memset(a, 0, sizeof(a));
    memset(mx, 0, sizeof(mx));
    memset(fail, 0, sizeof(fail));
    scanf("%s", s + 1);
    int n = strlen(s + 1), las;
    ans = 0;
    cnt = las = 1;
    for (int i = 1; i <= n; ++i) las = extend(las, s[i] - 'a'), ++cov[las];
    memset(lnk, 0, sizeof(lnk));
    memset(nxt, 0, sizeof(nxt));
    e = 0;
    for (int i = 2; i <= cnt; ++i) add(fail[i], i);
    dfs(1);
    printf("%lld\n", ans);
  }
  return 0;
}
