#include <bits/stdc++.h>
using namespace std;
priority_queue<int> QwQ;
int n, q, np, nq, p, last, tot;
int num[10005], sa[10005], wx[10005], t[10005][30], fa[10005], Right[10005],
    cnt[10005], ans[10005];
char s[10005];
int read() {
  int k = 0, f = 1;
  char ch;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    k = (k << 1) + (k << 3) + ch - '0', ch = getchar();
  return k * f;
}
void build_SAM(int x) {
  int i, j, k;
  p = last, last = np = ++tot, num[np] = num[p] + 1, Right[np] = 1;
  while (!t[p][x]) t[p][x] = np, p = fa[p];
  if (!p)
    fa[np] = 1;
  else {
    q = t[p][x];
    if (num[q] == num[p] + 1)
      fa[np] = q;
    else {
      nq = ++tot, num[nq] = num[p] + 1;
      memcpy(t[nq], t[q], sizeof(t[q]));
      fa[nq] = fa[q], fa[q] = fa[np] = nq;
      while (t[p][x] == q) t[p][x] = nq, p = fa[p];
    }
  }
}
void solve() {
  int i, j, k, l, tmp, x, mn;
  for (i = 1; i <= tot; i++) wx[num[i]]++;
  for (i = 1; i <= n; i++) wx[i] += wx[i - 1];
  for (i = tot; i >= 1; i--) sa[wx[num[i]]--] = i;
  for (i = tot; i >= 1; i--) {
    k = sa[i];
    Right[fa[k]] += Right[k];
  }
  k = 1, tmp = 0;
  scanf("%s", s);
  l = strlen(s);
  for (i = 0; i <= l - 1; i++) {
    x = s[i] - 'a' + 1;
    while (!t[k][x]) k = fa[k], tmp = num[k];
    tmp++;
    k = t[k][x];
    cnt[k]++;
  }
  for (i = tot; i >= 1; i--) {
    k = sa[i];
    ans[k] = num[fa[k]] + 1;
    cnt[fa[k]] += cnt[k];
  }
  mn = 1000000009;
  for (i = 1; i <= tot; i++)
    if (cnt[i] == 1 && Right[i] == 1) mn = min(ans[i], mn);
  if (mn != 1000000009)
    printf("%d\n", mn);
  else
    printf("-1\n");
}
void init() {
  int i, j, k, l;
  last = tot = 1, num[0] = -1;
  for (i = 1; i <= 26; i++) t[0][i] = 1;
  scanf("%s", s);
  l = strlen(s), n = l;
  for (i = 0; i <= l - 1; i++) build_SAM(s[i] - 'a' + 1);
  solve();
}
void work() { int i, j, k; }
int main() {
  init();
  work();
  return 0;
}
