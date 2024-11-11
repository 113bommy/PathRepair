#include <bits/stdc++.h>
using namespace std;
int h[100010], nxt[100010], ec, v[100010], n, a, b, sz[100010], f[100010], rt,
    fa[100010], s[100010], ct, sv[100010], w[100010];
void add(int x, int y) {
  v[++ec] = y;
  nxt[ec] = h[x];
  h[x] = ec;
}
void adj(int x, int y) {
  add(x, y);
  add(y, x);
}
void gt(int x, int fa) {
  sz[x] = 1;
  for (int i = h[x]; i; i = nxt[i])
    if (v[i] != fa) {
      gt(v[i], x);
      f[x] = max(f[x], sz[v[i]]);
      sz[x] += sz[v[i]];
    }
  f[x] = max(f[x], n - sz[x]);
  if (f[rt] > f[x]) rt = x;
}
int fd(int x) { return fa[x] == x ? x : fa[x] = fd(fa[x]); }
struct no {
  int x, y;
};
int operator<(no x, no y) { return x.x > y.x; }
priority_queue<no> q;
void dfs(int x, int fa) {
  sz[x] = 1;
  for (int i = h[x]; i; i = nxt[i])
    if (v[i] != fa) {
      dfs(v[i], x);
      sz[x] += sz[v[i]];
    }
}
void ga(int x, int va, int fa) {
  int vv = 1;
  for (int i = h[x]; i; i = nxt[i])
    if (v[i] != fa && v[i] != rt) {
      w[i] = w[i ^ 1] = va * vv;
      ga(v[i], va, x);
      vv += sz[v[i]];
    }
}
int main() {
  ec = 1;
  scanf("%d", &n);
  if (n == 1) return 0;
  if (n == 2) {
    printf("1 2 1");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    adj(a, b);
  }
  f[0] = 1e9;
  gt(1, 0);
  dfs(rt, 0);
  for (int i = h[rt]; i; i = nxt[i]) {
    s[++ct] = v[i];
    fa[ct] = ct;
    sv[ct] = sz[v[i]];
    q.push({sv[ct], ct});
  }
  while (q.size() > 1) {
    int x = q.top().y;
    q.pop();
    int y = q.top().y;
    q.pop();
    if (sv[x] + sv[y] <= n / 2) {
      fa[x] = y;
      sv[y] += sv[x];
      q.push((no){sv[y], y});
    } else {
      q.push((no){sv[x], x});
      q.push((no){sv[y], y});
      break;
    }
  }
  if (q.size() > 2) {
    int x = q.top().y;
    q.pop();
    int y = q.top().y;
    q.pop();
    fa[x] = y;
    sv[y] += sv[x];
    q.push((no){sv[y], y});
  }
  int x = fd(q.top().y);
  q.pop();
  int ra = n + 1, rb = n + 2;
  for (int i = 1; i <= ct; i++) adj(fd(i) == x ? ra : rb, s[i]);
  ga(ra, 1, 0);
  ga(rb, sv[x] + 1, 0);
  for (int i = 2; i <= ec; i += 2) {
    int a = v[i], b = v[i ^ 1], c = w[i];
    if (a == rt || b == rt) continue;
    if (a == ra || a == rb) a = rt;
    if (b == ra || b == rb) b = rt;
    printf("%d %d %d\n", a, b, c);
  }
}
