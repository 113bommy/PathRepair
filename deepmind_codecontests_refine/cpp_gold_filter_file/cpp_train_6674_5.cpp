#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e6 + 10;
int a[MAXN], pre[MAXN], suf[MAXN], vis[MAXN], nxt[MAXN];
void fail() {
  puts("no");
  exit(0);
}
void del(int l, int r) {
  suf[pre[l]] = suf[r];
  pre[suf[r]] = pre[l];
}
int nw = 1;
int n, m;
int get() {
  while (vis[nw]) nw++;
  if (nw > n) fail();
  vis[nw] = -1;
  return nw;
}
void solve(int l, int r) {
  if ((r - l) & 1) fail();
  for (int i = l; i <= r; i = suf[i])
    while (nxt[i]) {
      if (nxt[i] > r) fail();
      solve(suf[i], pre[nxt[i]]);
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  int sum = 0, cnt = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) ++sum, cnt += a[i] > 0;
  sum = (sum + 1) / 2;
  if (cnt > sum) fail();
  for (int i = suf[l]; i <= r; i = suf[i])
    if (!a[i] && cnt < sum) a[i] = get(), ++cnt;
  if (sum == 1 && cnt == 0) a[l] = get();
  for (int i = l; suf[i] <= r; i = suf[i]) {
    while (i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]]) {
      a[pre[i]] = a[suf[i]];
      del(i, suf[i]), i = pre[pre[i]];
    }
    while (i >= l && suf[i] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]]) {
      a[suf[suf[i]]] = a[i];
      del(suf[i], suf[suf[i]]), i = pre[i];
    }
  }
  for (int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  scanf("%d", &n);
  m = n * 2 - 1;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  if (a[1] && a[m] && a[1] != a[m]) fail();
  a[1] = a[m] = a[1] | a[m];
  for (int i = 0; i <= m; i++) pre[i] = i - 1, suf[i] = i + 1;
  for (int i = m; i >= 1; i--)
    if (a[i]) nxt[i] = vis[a[i]], vis[a[i]] = i;
  solve(1, m);
  puts("yes");
  for (int i = 1; i <= m; i++) printf("%d ", a[i]);
  puts("");
  return 0;
}
