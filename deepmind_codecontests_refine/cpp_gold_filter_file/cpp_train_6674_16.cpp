#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000010], pre[1000010], suf[1000010], nxt[1000010], lst[500010],
    pos = 1;
int get() {
  while (lst[pos]) pos++;
  if (pos > n) puts("no"), exit(0);
  return lst[pos] = -1, pos;
}
void del(int l, int r) {
  pre[suf[r]] = pre[l];
  suf[pre[l]] = suf[r];
}
void work(int l, int r) {
  if (l > r || ((r - l) & 1)) puts("no"), exit(0);
  for (int i = l; i <= r; i = suf[i]) {
    while (nxt[i]) {
      if (nxt[i] > r) puts("no"), exit(0);
      work(suf[i], pre[nxt[i]]);
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  }
  int len = 0, ty = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) len++, ty += !!a[i];
  len = (len + 1) / 2;
  if (ty > len) puts("no"), exit(0);
  for (int i = suf[l]; i <= r; i = suf[i])
    if (!a[i] && ty < len) a[i] = get(), ty++;
  if (len == 1 && ty == 0) a[l] = get();
  for (int i = l; suf[i] <= r; i = suf[i]) {
    while (i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]])
      a[pre[i]] = a[suf[i]], del(i, suf[i]), i = pre[pre[i]];
    while (i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]])
      a[suf[suf[i]]] = a[i], del(suf[i], suf[suf[i]]), i = pre[i];
  }
  for (int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  scanf("%d", &n), m = 2 * n - 1;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  if (a[1] && a[m] && a[1] != a[m]) puts("no"), exit(0);
  a[1] = a[m] = a[1] | a[m];
  for (int i = 0; i <= m; i++) pre[i] = i - 1, suf[i] = i + 1;
  for (int i = m; i >= 1; i--)
    if (a[i]) nxt[i] = lst[a[i]], lst[a[i]] = i;
  work(1, m);
  puts("yes");
  for (int i = 1; i <= m; i++) printf("%d ", a[i]);
  puts("");
}
