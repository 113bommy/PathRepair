#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000500;
vector<int> vec;
int n, m;
int suf[maxn], a[maxn], pre[maxn], nxt[maxn], last[maxn];
void gg() {
  puts("no");
  exit(0);
}
void del(int x, int y) {
  suf[pre[x]] = suf[y];
  pre[suf[y]] = pre[x];
}
int get() {
  int x = vec.back();
  vec.pop_back();
  return x;
}
void dfs(int l, int r) {
  if ((r - l) & 1) gg();
  for (int i = l; i <= r; i = suf[i]) {
    while (nxt[i]) {
      if (nxt[i] > r) gg();
      dfs(suf[i], pre[nxt[i]]);
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  }
  int cnt = 0, sum = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) {
    sum++;
    if (a[i]) cnt++;
  }
  sum = (sum + 1) / 2;
  if (cnt > sum) gg();
  for (int i = suf[l]; i <= r; i = suf[i])
    if (cnt < sum && !a[i]) a[i] = get(), cnt++;
  if (sum == 1 && cnt == 0) a[l] = get();
  for (int i = l; i <= r; i = suf[i]) {
    while (i >= l && suf[i] <= r && !a[pre[i]] && a[i] && a[suf[i]]) {
      a[pre[i]] = a[suf[i]];
      del(i, suf[i]);
      i = pre[pre[i]];
    }
    while (i >= l && suf[suf[i]] <= r && a[i] && a[suf[i]] && !a[suf[suf[i]]]) {
      a[suf[suf[i]]] = a[i];
      del(suf[i], suf[suf[i]]);
      i = pre[i];
    }
  }
  for (int i = l; i <= r; i = suf[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  scanf("%d", &n);
  m = 2 * n - 1;
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  if (a[1] && a[m] && a[1] != a[m]) gg();
  a[1] = a[m] = a[1] | a[m];
  for (int i = 0; i <= m; i++) pre[i] = i - 1, suf[i] = i + 1;
  for (int i = m; i >= 1; i--)
    if (a[i]) {
      nxt[i] = last[a[i]], last[a[i]] = i;
    }
  for (int i = 1; i <= n; i++)
    if (!last[i]) vec.push_back(i);
  dfs(1, m);
  puts("yes");
  for (int i = 1; i <= m; i++) printf("%d ", a[i]);
  return 0;
}
