#include <bits/stdc++.h>
using namespace std;
void dead() {
  puts("No solution");
  exit(0);
}
int n, m, cnt[5], stdnxt[1000000 + 5], stdtp[1000000 + 5], delta, mi, rev,
    nxt[1000000 + 5], tp[1000000 + 5], p[1000000 + 5], ans[1000000 + 5], l,
    fail[1000000 + 5], tmp[1000000 + 5], sola;
bool vis[1000000 + 5];
int getnum(char c) {
  int flag;
  if (c == 'T') flag = 0;
  if (c == 'L') flag = 1;
  if (c == 'B') flag = 2;
  if (c == 'R') flag = 3;
  flag ^= rev;
  return flag;
}
int getpos(int x, int flag) {
  if (flag == 0) return x;
  if (flag == 1) return x + m;
  if (flag == 2) return x + n + m;
  if (flag == 3) return x + 2 * m + n;
}
int getflag(int x) {
  if (x > 2 * m + n) return 3;
  if (x > n + m) return 2;
  if (x > m) return 1;
  return 0;
}
int getnode(int x) {
  int flag = getflag(x);
  if (flag == 0) return x;
  if (flag == 1) return x - m;
  if (flag == 2) return x - n - m;
  if (flag == 3) return x - 2 * m - n;
}
int getype(int x, int y) {
  if (x == 3 && y == 0) return 3;
  if (x > y || x == 0 && y == 3) return getype(y, x);
  if (x + 1 == y) return x;
  if (x == 0 && y == 2) return 4;
  dead();
}
void add(int a, int b, char ca, char cb) {
  int fa = getnum(ca), fb = getnum(cb);
  cnt[getype(fa, fb)]++, nxt[getpos(a, fa)] = getpos(b, fb),
                                       nxt[getpos(b, fb)] = getpos(a, fa);
}
int getcircle(int beg, bool ifstd, int *tp, int *p) {
  int len = 0, now = beg, to;
  while (1) {
    if (ifstd)
      to = stdnxt[now];
    else
      to = nxt[now], vis[to] = 1;
    tp[++len] = getype(getflag(now), getflag(to));
    p[len] = getnode(now) + ((getflag(now) & 1) ? m : 0);
    now = to;
    int x = getnode(now), flag = getflag(now);
    if (flag == 0) now = getpos(x, 2);
    if (flag == 1) now = getpos(x, 3);
    if (flag == 2) now = getpos(x, 0);
    if (flag == 3) now = getpos(x, 1);
    if (!ifstd) vis[now] = 1;
    if (now == beg) return len;
  }
}
void insert(int len) {
  if (len != 4 && len != l) dead();
  if (len == 4 && tp[1] == 0 && tp[2] == 1 && tp[3] == 2 && tp[4] == 3) {
    if (!mi) dead();
    ans[m - mi + 1] = p[1], ans[mi + m] = p[2], ans[mi] = p[3],
                 ans[n - mi + 1 + m] = p[4];
    mi--;
    return;
  }
  if (len == 4 && tp[1] == 0 && tp[2] == 3 && tp[3] == 2 && tp[4] == 1) {
    if (!mi) dead();
    ans[mi] = p[1], ans[mi + m] = p[2], ans[m - mi + 1] = p[3],
    ans[n - mi + 1 + m] = p[4];
    mi--;
    return;
  }
  if (len != l) dead();
  for (int i = 1; i <= l; i++) tp[i + l] = tp[i], p[i + l] = p[i];
  int pos = 0;
  for (int i = 1, j = 0; i <= 2 * l; i++) {
    while (j && stdtp[j + 1] != tp[i]) j = fail[j];
    if (stdtp[j + 1] == tp[i]) j++;
    if (j == l) {
      pos = i;
      break;
    }
  }
  if (!pos) dead();
  getcircle(++sola, 1, tmp, tmp);
  for (int i = pos - l + 1; i <= pos; i++) {
    ans[tmp[i - pos + l]] = p[i];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  if (n > m) rev = 1, swap(n, m);
  for (int i = 0; i < n + m; i++) {
    char s[3];
    scanf("%s%s", s, s + 1);
    int a, b;
    scanf("%d%d", &a, &b);
    add(a, b, s[0], s[1]);
  }
  if (cnt[0] != cnt[2]) dead();
  if (cnt[1] != cnt[3]) dead();
  if (cnt[0] + cnt[1] != n) dead();
  if (cnt[0] + cnt[3] + cnt[4] != m) dead();
  sola = mi = min(cnt[0], cnt[1]);
  delta = cnt[1] - cnt[0];
  for (int i = cnt[0] + 1; i <= m - cnt[1]; i++)
    stdnxt[i] = getpos(i + delta, 2), stdnxt[getpos(i + delta, 2)] = i;
  for (int i = 1; i <= cnt[0]; i++)
    stdnxt[i] = getpos(i, 1), stdnxt[getpos(i, 1)] = i,
    stdnxt[getpos(n - i + 1, 3)] = getpos(m - i + 1, 2),
    stdnxt[getpos(m - i + 1, 2)] = getpos(n - i + 1, 3);
  for (int i = 1; i <= cnt[1]; i++)
    stdnxt[getpos(i, 3)] = m - i + 1, stdnxt[m - i + 1] = getpos(i, 3),
                     stdnxt[getpos(i, 2)] = getpos(n - i + 1, 1),
                     stdnxt[getpos(n - i + 1, 1)] = getpos(i, 2);
  int len = getcircle(sola + 1, 1, stdtp, tmp);
  l = len;
  for (int i = 2, j = 0; i <= len; i++) {
    while (j && stdtp[j + 1] != stdtp[i]) j = fail[j];
    if (stdtp[j + 1] == stdtp[i]) fail[i] = ++j;
  }
  for (int i = 1; i <= 2 * (n + m); i++)
    if (!vis[i]) len = getcircle(i, 0, tp, p), insert(len);
  if (mi) dead();
  if (rev) {
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
    puts("");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i + m] - m);
    puts("");
  } else {
    for (int i = 1; i <= n; i++) printf("%d ", ans[i + m] - m);
    puts("");
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
