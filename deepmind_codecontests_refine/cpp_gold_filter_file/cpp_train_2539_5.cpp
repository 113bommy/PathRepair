#include <bits/stdc++.h>
const int MAXN = 1100005, MOD = 4000037;
struct TriInt {
  char a;
  unsigned short b;
  TriInt() {}
  TriInt(int x) : a(x >> 16), b(x) {}
  operator int() { return (int)(a << 16) | b; }
};
struct Hash {
  TriInt val;
  int key;
} hash[MOD];
struct node {
  unsigned short cnt[11];
  TriInt fail, l;
} t[MAXN];
int len, N, cnt = 1, last = 1, ans, l[11], r[11];
TriInt q[MAXN], deg[MAXN];
int Son(int p) {
  int x = p % MOD;
  for (; hash[x].key && hash[x].key != p; x = (x + 1 < MOD ? x + 1 : 0))
    ;
  return x;
}
void Extend(int bel, int w) {
  int p = last, np = ++cnt;
  t[np].l = t[p].l + 1, ++t[np].cnt[bel];
  for (; p; p = t[p].fail) {
    int x = Son(p * 27 + w);
    if (hash[x].val)
      break;
    else
      hash[x].val = np, hash[x].key = p * 27 + w;
  }
  if (!p)
    t[np].fail = 1;
  else {
    int q = hash[Son(p * 27 + w)].val;
    if (t[p].l + 1 == t[q].l)
      t[np].fail = q;
    else {
      int nq = ++cnt;
      for (int i = 0; i <= 26; ++i) {
        int x = Son(q * 27 + i);
        if (hash[x].val) {
          int y = Son(nq * 27 + i);
          hash[y].val = hash[x].val, hash[y].key = nq * 27 + i;
        }
      }
      t[nq].l = t[p].l + 1, t[nq].fail = t[q].fail, t[q].fail = t[np].fail = nq;
      for (; p; p = t[p].fail) {
        int x = Son(p * 27 + w);
        if (hash[x].val == q)
          hash[x].val = nq;
        else
          break;
      }
    }
  }
  last = np;
}
void GetS(int bel) {
  char c;
  while (c = getchar(), c < 'a' || c > 'z')
    ;
  while (Extend(bel, c - 'a' + 1), c = getchar(), c >= 'a' && c <= 'z')
    ;
}
void init() {
  GetS(0);
  scanf("%d", &N), l[0] = 1, r[0] = MAXN;
  for (int i = 1; i <= N; ++i)
    Extend(i, 0), GetS(i), scanf("%d%d", l + i, r + i);
}
int Check(int x) {
  for (int i = 0; i <= N; ++i)
    if (l[i] > t[x].cnt[i] || r[i] < t[x].cnt[i]) return 0;
  return 1;
}
void work() {
  for (int i = 1; i <= cnt; ++i) deg[t[i].fail] = deg[t[i].fail] + 1;
  int tail = 0;
  for (int i = 1; i <= cnt; ++i)
    if (!deg[i]) q[++tail] = i;
  for (int head = 1; head <= tail; ++head) {
    int x = q[head], y = t[x].fail, tmp;
    ans += Check(x) * (t[x].l - t[y].l);
    for (int i = 0; i <= N; ++i) {
      tmp = (int)t[x].cnt[i] + t[y].cnt[i];
      t[y].cnt[i] = (tmp > 50000 ? 50001 : tmp);
    }
    deg[y] = deg[y] - 1;
    if (!deg[y]) q[++tail] = y;
  }
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
