#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, k;
char st[maxn];
int op[maxn], ed[maxn], Is[maxn];
int vi[maxn];
pair<int, int> has[maxn];
int bot, tot;
int mn[maxn][18], Log[maxn];
long long Ans[maxn], ans[maxn];
struct SA {
  int c[maxn], s[maxn], t1[maxn], t2[maxn], sa[maxn], rk[maxn], height[maxn], n;
  void add(int c) { s[++n] = c; }
  void build(int m) {
    int *x = t1, *y = t2;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[x[i]]--] = i;
    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for (int i = n - k + 1; i <= n; i++) y[++p] = i;
      for (int i = 1; i <= n; i++)
        if (sa[i] > k) y[++p] = sa[i] - k;
      for (int i = 0; i < m; i++) c[i] = 0;
      for (int i = 1; i <= n; i++) c[x[y[i]]]++;
      for (int i = 1; i < m; i++) c[i] += c[i - 1];
      for (int i = n; i; i--) sa[c[x[y[i]]]--] = y[i];
      swap(x, y);
      x[sa[1]] = 1;
      p = 1;
      for (int i = 2; i <= n; i++)
        x[sa[i]] = (y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k]
                        ? p
                        : ++p);
      if (p >= n) break;
      m = p + 1;
    }
    for (int i = 1; i <= n; i++) rk[sa[i]] = i;
    int k = 0;
    for (int i = 1; i <= n; i++) {
      int j = sa[rk[i] - 1];
      if (k) k--;
      while (s[i + k] == s[j + k]) k++;
      height[rk[i]] = k;
    }
    for (int i = 1; i <= n; i++) mn[i][0] = height[i];
    for (int j = 1; j < 18; j++)
      for (int i = 1; i + (1 << j) - 1 <= n; i++)
        mn[i][j] = min(mn[i][j - 1], mn[i + (1 << j - 1)][j - 1]);
    for (int j = 0; j < 18; j++)
      for (int i = 1 << j; (i < (1 << j + 1)) && i <= n; i++) Log[i] = j;
  }
} sa;
int query(int l, int r) {
  if (l > r) return sa.n + 1;
  int len = r - l + 1;
  return min(mn[l][Log[len]], mn[r - (1 << Log[len]) + 1][Log[len]]);
}
void add(int x) {
  if (!x) return;
  if (!vi[x]) tot++;
  vi[x]++;
}
void del(int x) {
  if (!x) return;
  vi[x]--;
  if (!vi[x]) tot--;
}
void Work() {
  bot = 1;
  add(Is[1]);
  int l = 1, r = 0;
  for (int top = 1; top <= sa.n; top++) {
    while (bot < sa.n && tot < k) add(Is[++bot]);
    if (tot >= k) {
      int t = query(top + 1, bot);
      while (l <= r && t >= has[r].first) r--;
      has[++r] = make_pair(t, bot);
      ans[top] = max(
          ans[top], (long long)min(has[l].first, ed[Is[top]] - sa.sa[top] + 1));
    }
    while (has[l].second == top) l++;
    del(Is[top]);
  }
  bot = sa.n;
  add(Is[sa.n]);
  l = 1;
  r = 0;
  for (int top = sa.n; top; top--) {
    while (bot > 1 && tot < k) add(Is[--bot]);
    if (tot >= k) {
      int t = query(bot + 1, top);
      while (l <= r && t >= has[r].first) r--;
      has[++r] = make_pair(t, bot);
      ans[top] = max(
          ans[top], (long long)min(has[l].first, ed[Is[top]] - sa.sa[top] + 1));
    }
    while (has[l].second == top) l++;
    del(Is[top]);
  }
  for (int i = 1; i <= sa.n; i++) Ans[Is[i]] += ans[i];
  for (int i = 1; i <= n; i++) printf("%I64d ", Ans[i]);
}
void Init() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", st + 1);
    int len = strlen(st + 1);
    op[i] = sa.n + 1;
    for (int j = 1; j <= len; j++) sa.add(st[j] - 'a' + 1);
    ed[i] = sa.n;
    sa.add(27);
  }
  sa.build(28);
  for (int i = 1; i <= n; i++)
    for (int j = op[i]; j <= ed[i]; j++) Is[sa.rk[j]] = i;
}
int main() {
  Init();
  Work();
  return 0;
}
