#include <bits/stdc++.h>
using namespace std;
inline int read(int x = 0, bool f = 0, char ch = getchar()) {
  for (; !isdigit(ch); ch = getchar()) f = ch == '-';
  for (; isdigit(ch); ch = getchar()) x = (x << 3) + (x << 1) + (ch ^ 48);
  return f ? -x : x;
}
const int N = 100100;
int n, m, tot;
int fa[N], son[N], siz[N], top[N], dfn[N];
int L[N], R[N], bl[N], tag[N], val[N], ans[N];
vector<int> g[N];
bool v[N];
short c[330][200020], *cnt[330];
void dfs(int x) {
  siz[x] = 1;
  for (int i : g[x])
    dfs(i), siz[x] += siz[i], son[x] = siz[i] > siz[son[x]] ? i : son[x];
}
void Dfs(int x, int Top) {
  top[x] = Top;
  dfn[x] = ++tot;
  if (son[x]) Dfs(son[x], Top);
  for (int y : g[x])
    if (y ^ son[x]) Dfs(y, y);
}
inline void rebuild(int x) {
  for (int i = L[x]; i <= R[x]; ++i)
    cnt[x][val[i]] = cnt[x][val[i] - 1] = cnt[x][val[i] + 1] = 0;
  for (int i = L[x]; i <= R[x]; ++i) val[i] += tag[x];
  tag[x] = ans[x] = 0;
  for (int i = L[x]; i <= R[x]; ++i)
    if (val[i] >= 0 && !v[i]) ++ans[x];
  for (int i = L[x]; i <= R[x]; ++i)
    if (!v[i]) cnt[x][val[i]]++;
}
inline void modify(int l, int r, int v) {
  if (bl[l] == bl[r]) {
    for (int i = l; i <= r; ++i) val[i] += v;
    return rebuild(bl[l]);
  }
  for (int i = l; i <= R[bl[l]]; ++i) val[i] += v;
  for (int i = r; i >= L[bl[r]]; --i) val[i] += v;
  for (int i = bl[l] + 1; i < bl[r]; ++i) {
    if (v > 0) tag[i]++, ans[i] += cnt[i][-tag[i]];
    if (v < 0) ans[i] -= cnt[i][-tag[i]], tag[i]--;
  }
  rebuild(bl[l]);
  rebuild(bl[r]);
}
void Modify(int x, int v) {
  while (x) modify(dfn[top[x]], dfn[x], v), x = fa[top[x]];
}
int main() {
  n = read(), m = read();
  int len = sqrt(n) + 1;
  for (int i = 2; i <= n; ++i) fa[i] = read(), g[fa[i]].push_back(i);
  dfs(1);
  Dfs(1, 1);
  for (int i = 1; i <= n; ++i)
    bl[i] = (i - 1) / len + 1, L[bl[i]] = L[bl[i]] ? L[bl[i]] : i, R[bl[i]] = i;
  for (int i = 1; i <= n; ++i) val[dfn[i]] = -read() - 1;
  for (int i = 1; R[i]; ++i) cnt[i] = c[i] + n + 5, rebuild(i);
  while (m--) {
    int x = read(), sum = 0;
    if (x > 0)
      v[dfn[x]] = 1, Modify(x, 1);
    else
      v[dfn[x]] = 0, Modify(-x, -1);
    for (int i = 1; R[i]; ++i) sum += ans[i];
    printf("%d ", sum);
  }
  return 0;
}
