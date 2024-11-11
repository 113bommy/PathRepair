#include <bits/stdc++.h>
const int mxN(1000233), p(1000000007), sta(0), debug(0);
int n, str[mxN];
inline void init() {
  if (sta == 1 || sta == 2) freopen("a.in", "r", stdin);
  static char s[mxN];
  scanf("%s", s);
  n = strlen(s);
  if (n & 1) {
    puts("0");
    exit(0);
  }
  for (int i = 0, j = n - 1; i < j; ++i, --j)
    str[i << 1 | 1] = s[i] - 'a', str[(i + 1) << 1] = s[j] - 'a';
  str[0] = -1;
}
namespace PT {
struct D {
  int l, d, v[2];
  D *f, *a, *e[26];
} ar[mxN], *ed = ar;
int m;
inline void init() {
  m = 2;
  ar->f = ar + 1;
  ar[1].l = -1;
}
inline void insert(int n) {
  int c = str[n];
  D *u = ed;
  for (; c != str[n - u->l - 1]; u = u->f)
    ;
  if (u->e[c]) {
    ed = u->e[c];
    return;
  }
  D *v = u->e[c] = ed = ar + m++;
  v->l = u->l + 2;
  if (u == ar + 1) {
    v->f = v->a = ar;
    v->d = 1;
    return;
  }
  for (u = u->f; c != str[n - u->l - 1]; u = u->f)
    ;
  v->f = u->e[c];
  v->a = (v->d = v->l - v->f->l) == v->f->d ? v->f->a : v->f;
}
}  // namespace PT
int main() {
  init();
  PT::init();
  static int f[mxN];
  f[0] = 1;
  for (int i = 1; i <= n; ++i) {
    PT::insert(i);
    if (debug) {
      using namespace PT;
      printf("%d\n", str[i]);
      printf("%ld %ld %ld\n", ed - ar, ed->f - ar, ed->a - ar);
    }
    for (PT::D *u = PT::ed; u != PT::ar; u = u->a) {
      u->v[(u->a->l + u->d) & 1] = f[i - u->a->l - u->d];
      u->v[~(u->a->l + u->d) & 1] = 0;
      if (u->f != u->a) {
        u->v[0] = (u->v[0] + u->f->v[u->d & 1]) % p;
        u->v[1] = (u->v[1] + u->f->v[~u->d & 1]) % p;
      }
      f[i] = (f[i] + u->v[0]) % p;
    }
  }
  printf("%d\n", (f[n] + p) % p);
  return 0;
}
