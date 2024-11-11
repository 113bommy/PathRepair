#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
int a[200010], b[200010];
int head[200010], nxt[200010 * 2], to[200010 * 2], tot;
void add(int u, int v) {
  tot++;
  nxt[tot] = head[u];
  head[u] = tot;
  to[tot] = v;
}
int fa[200010], rt, on_path[200010], dep[200010], st;
void dfs(int x, int las) {
  for (int i = head[x]; i; i = nxt[i]) {
    if (to[i] == las) continue;
    fa[to[i]] = x;
    dep[to[i]] = dep[x] + 1;
    dfs(to[i], x);
  }
}
bool cmp(int x, int y) { return dep[x] > dep[y]; }
int cir[200010], top, type, Top, book[200010], bot[200010];
void check() {
  Top = -1;
  for (int i = 1; i <= top; i++) {
    if (book[cir[i]]) continue;
    type++;
    int x = cir[i];
    bot[type] = x;
    while (!book[x] && a[x] != b[x]) {
      book[x] = 1;
      x = fa[x];
    }
    if (Top == -1)
      Top = x;
    else if (Top != x) {
      type = 1000000007;
      break;
    }
  }
}
int s[200010], topx, cnt1, cnt2;
void get(int x, int id) {
  topx = 0;
  while (x != Top) {
    if (on_path[x]) {
      if (id)
        cnt1++;
      else
        cnt2++;
    }
    s[++topx] = x;
    x = fa[x];
  }
  if (id) reverse(s + 1, s + topx + 1);
}
long long calc() {
  int d;
  for (int i = 0; i < top; i++)
    if (b[cir[i]] == a[cir[0]]) d = i;
  for (int i = 0; i < top; i++) {
    if (a[cir[i]] != b[cir[(i + d) % top]]) return -1;
  }
  return min(1ll * d * (top + 1) - cnt1 * 2,
             1ll * (top - d) * (top + 1) - cnt2 * 2);
}
long long ans;
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) b[i] = read();
  for (int i = 1; i < n; i++) {
    int q = read(), w = read();
    add(q, w);
    add(w, q);
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i]) st = i;
    if (!b[i]) rt = i;
  }
  dfs(rt, 0);
  int tmp = st;
  on_path[st] = 1;
  while (tmp != rt) swap(a[tmp], a[fa[tmp]]), tmp = fa[tmp], on_path[tmp] = 1;
  for (int i = 1; i <= n; i++)
    if (a[i] != b[i]) cir[++top] = i;
  sort(cir + 1, cir + top + 1, cmp);
  check();
  if (type > 2) {
    puts("-1");
    return 0;
  }
  if (!type) {
    printf("0 %d\n", dep[st]);
    return 0;
  }
  top = 0;
  get(bot[1], 1);
  for (int i = 1; i <= topx; i++) cir[top++] = s[i];
  if (type == 2) {
    get(bot[2], 0);
    for (int i = 1; i <= topx; i++) cir[top++] = s[i];
  }
  ans = calc();
  if (ans == -1) {
    puts("-1");
    return 0;
  }
  tmp = Top;
  while (!on_path[tmp]) ans += 2, tmp = fa[tmp];
  ans += dep[st];
  int ansx, ansy;
  if (type == 1)
    ansx = Top, ansy = bot[1];
  else
    ansx = bot[1], ansy = bot[2];
  if (ansx > ansy) swap(ansx, ansy);
  cout << ansx << " " << ansy << " " << ans << endl;
  return 0;
}
