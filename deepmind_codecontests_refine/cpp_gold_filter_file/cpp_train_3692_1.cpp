#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, tot, pre[N], a[N], siz[N], sum[N], f[N], ch[N][2];
long long ans[N], all[N], ad[N], de[N];
long double Ans;
bool isroot(int x) { return ch[f[x]][0] != x && ch[f[x]][1] != x; }
int which(int x) { return ch[f[x]][1] == x; }
void push_up(int x) {
  sum[x] = siz[x] + sum[ch[x][0]] + sum[ch[x][1]];
  all[x] = all[ch[x][0]] + all[ch[x][1]] + 1ll * a[x] * siz[x];
  ans[x] = ans[ch[x][0]] + ans[ch[x][1]] + ad[x] +
           a[x] * (1ll * siz[x] * siz[x] - de[x]) +
           2ll * a[x] * siz[x] * sum[ch[x][1]] +
           2ll * all[ch[x][0]] * (sum[x] - sum[ch[x][0]]);
  return;
}
void rotate(int x) {
  int fa = f[x], ffa = f[fa], d = which(x);
  if (!isroot(fa)) ch[ffa][which(fa)] = x;
  f[x] = ffa;
  ch[fa][d] = ch[x][d ^ 1];
  f[ch[x][d ^ 1]] = fa;
  ch[x][d ^ 1] = fa;
  f[fa] = x;
  push_up(fa);
  push_up(x);
  return;
}
void splay(int x) {
  for (int fa; !isroot(x); rotate(x))
    if (!isroot(fa = f[x])) rotate(which(x) == which(fa) ? fa : x);
  return;
}
void access(int x) {
  for (int y = 0; x; y = x, x = f[x]) {
    splay(x);
    siz[x] += sum[ch[x][1]];
    de[x] += 1ll * sum[ch[x][1]] * sum[ch[x][1]];
    ad[x] += ans[ch[x][1]];
    ch[x][1] = y;
    siz[x] -= sum[y];
    de[x] -= 1ll * sum[y] * sum[y];
    ad[x] -= ans[y];
    push_up(x);
  }
  return;
}
void link(int x, int y) {
  access(y);
  splay(y);
  access(x);
  splay(x);
  f[y] = x;
  siz[x] += sum[y];
  ad[x] += ans[y];
  de[x] += 1ll * sum[y] * sum[y];
  push_up(x);
  return;
}
void cut(int x, int y) {
  access(x);
  splay(x);
  splay(y);
  siz[x] -= sum[y];
  ad[x] -= ans[y];
  de[x] -= 1ll * sum[y] * sum[y];
  f[y] = 0;
  push_up(x);
  return;
}
bool check(int x, int y) {
  access(y);
  splay(y);
  splay(x);
  return !isroot(y);
}
int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) scanf("%d", pre + i);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    ans[i] = all[i] = a[i];
    siz[i] = sum[i] = 1;
  }
  for (int i = 2; i <= n; i++) link(pre[i], i);
  access(1);
  splay(1);
  Ans = ans[1];
  printf("%.10Lf\n", Ans / n / n);
  scanf("%d", &m);
  while (m--) {
    char op[2];
    int x, y;
    scanf("%s%d%d", op, &x, &y);
    if (op[0] == 'P') {
      if (pre[y] == x || pre[x] == y) goto to;
      if (check(x, y)) swap(x, y);
      cut(pre[x], x);
      pre[x] = y;
      link(y, x);
      access(1);
      splay(1);
      Ans = ans[1];
    } else {
      access(x);
      splay(x);
      a[x] = y;
      push_up(x);
      Ans = ans[x];
    }
  to:
    printf("%.10Lf\n", Ans / n / n);
  }
  return 0;
}
