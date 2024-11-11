#include <bits/stdc++.h>
using namespace std;
const int maxn = 555555;
int n, m, a[maxn], pre[maxn], suf[maxn], nxt[maxn], last[maxn];
void del(int l, int r) {
  suf[pre[l]] = suf[r];
  pre[suf[r]] = pre[l];
}
int pos = 1;
int get() {
  while (last[pos] && pos <= n) pos++;
  if (pos > n) return -1;
  last[pos] = -1;
  return pos;
}
bool deal(int l, int r) {
  if ((r - l) & 1) return false;
  for (int i = l; i <= r; i = suf[i])
    while (nxt[i] != -1) {
      if (nxt[i] > r) return false;
      if (!deal(suf[i], pre[nxt[i]])) return false;
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  int sum = 0, cnt = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) sum++, cnt += a[i] > 0;
  sum = (sum + 1) / 2;
  if (cnt > sum) return false;
  for (int i = suf[l]; i <= r; i = suf[i])
    if (!a[i] && cnt < sum) {
      a[i] = get(), cnt++;
      if (a[i] == -1) return false;
    }
  if (sum == 1 && cnt == 0) {
    a[l] = get();
    if (a[l] == -1) return false;
  }
  for (int i = l; suf[i] <= r; i = suf[i]) {
    while (i > l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]])
      a[pre[i]] = a[suf[i]], del(i, suf[i]), i = pre[pre[i]];
    while (i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]])
      a[suf[suf[i]]] = a[i], del(suf[i], suf[suf[i]]), i = pre[i];
  }
  for (int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
  return true;
}
void solve() {
  scanf("%d", &n);
  m = 2 * n - 1;
  for (int i = 1; i <= m; ++i) scanf("%d", &a[i]);
  if (a[1] && a[m] && a[1] != a[m]) do {
      puts("no");
      return;
    } while (0);
  a[1] = a[m] = a[1] | a[m];
  for (int i = 1; i <= m; ++i) {
    pre[i] = i - 1;
    suf[i] = i + 1;
    if (a[i]) {
      if (last[a[i]]) nxt[last[a[i]]] = i;
      last[a[i]] = i;
    }
    nxt[i] = -1;
  }
  pre[0] = -1, suf[0] = 1;
  pre[m + 1] = m, suf[m + 1] = m + 2;
  if (!deal(1, m)) do {
      puts("no");
      return;
    } while (0);
  puts("yes");
  for (int i = 1; i <= m; ++i) printf("%d%c", a[i], " \n"[i == m]);
}
int main() {
  int T = 1;
  while (T--) solve();
  return 0;
}
