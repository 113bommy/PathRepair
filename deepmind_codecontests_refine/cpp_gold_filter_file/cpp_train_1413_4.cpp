#include <bits/stdc++.h>
using namespace std;
const int maxn = 500010, inf = 1e9;
struct poi {
  int too, dis, pre;
} e[maxn];
int n, x, y, tot, skip, sum;
int st[maxn], col[maxn], size[maxn], dep[maxn], son[maxn], mx[1 << 23],
    last[maxn], ans[maxn];
char ch[1];
inline void read(int &k) {
  int f = 1;
  k = 0;
  char c = getchar();
  while (c < '0' || c > '9') c == '-' && (f = -1), c = getchar();
  while (c <= '9' && c >= '0') k = k * 10 + c - '0', c = getchar();
  k *= f;
}
inline void add(int x, int y, int z) {
  e[++tot].too = y;
  e[tot].dis = z;
  e[tot].pre = last[x];
  last[x] = tot;
}
void dfs1(int x, int fa) {
  size[x] = 1;
  for (int i = last[x], too; i; i = e[i].pre)
    if ((too = e[i].too) != fa) {
      dep[too] = dep[x] + 1;
      st[too] = st[x] ^ (1 << e[i].dis);
      dfs1(too, x);
      size[x] += size[too];
      if (size[too] > size[son[x]]) son[x] = too;
    }
}
void Count(int x, int fa, int f) {
  sum = max(sum, mx[st[x]] + dep[x] - 2 * dep[f]);
  for (int i = 0; i < 22; i++)
    sum = max(sum, mx[st[x] ^ (1 << i)] + dep[x] - 2 * dep[f]);
  if (x == f) return;
  for (int i = last[x], too; i; i = e[i].pre)
    if ((too = e[i].too) != fa && too != skip) Count(too, x, f);
}
void update(int x, int fa, int delta) {
  if (delta > 0)
    mx[st[x]] = max(mx[st[x]], dep[x]);
  else
    mx[st[x]] = -inf;
  for (int i = last[x], too; i; i = e[i].pre)
    if ((too = e[i].too) != fa && too != skip) update(too, x, delta);
}
void dfs2(int x, int fa, bool heavy) {
  for (int i = last[x], too; i; i = e[i].pre)
    if ((too = e[i].too) != fa && too != son[x])
      dfs2(too, x, 0), ans[x] = max(ans[x], ans[too]);
  if (son[x])
    dfs2(son[x], x, 1), skip = son[x], ans[x] = max(ans[x], ans[son[x]]);
  sum = 0;
  Count(x, fa, x);
  mx[st[x]] = max(mx[st[x]], dep[x]);
  for (int i = last[x], too; i; i = e[i].pre)
    if ((too = e[i].too) != fa && too != skip)
      Count(too, x, x), update(too, x, 1);
  ans[x] = max(ans[x], sum);
  skip = 0;
  if (!heavy) update(x, fa, -1);
}
int main() {
  read(n);
  for (int i = 0; i < (1 << 23); i++) mx[i] = -inf;
  for (int i = 2; i <= n; i++)
    read(x), scanf("%s", ch), y = ch[0] - 'a', add(x, i, y);
  dfs1(1, 0);
  dfs2(1, 0, 1);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
