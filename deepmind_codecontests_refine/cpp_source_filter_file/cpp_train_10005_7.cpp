#include <bits/stdc++.h>
using namespace std;
int n, tot, ls, f[400010], s[400010];
map<int, int> t;
void nw(int x) {
  if (!t.count(x)) t[x] = ++tot;
  f[tot] = tot;
}
void gf(int x) {
  if (f[x] == x) return;
  gf(f[x]);
  s[x] ^= s[f[x]];
  f[x] = f[f[x]];
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); ++i) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    x ^= ls;
    y ^= ls;
    if (x > y) swap(x, y);
    y++;
    if (op == 1) {
      int z;
      scanf("%d", &z);
      z ^= ls;
      nw(x);
      nw(y);
      x = t[x];
      y = t[y];
      gf(x);
      gf(y);
      if (f[x] != f[y]) {
        s[f[x]] = z ^ s[y] ^ s[x];
        f[f[x]] = f[y];
      }
    } else {
      if (!t.count(x) || !t.count(y)) {
        printf("-1\n");
        ls = 1;
        continue;
      }
      x = t[x];
      y = t[y];
      gf(x);
      gf(y);
      if (f[x] != f[y]) {
        printf("-1\n");
        ls = 1;
      } else {
        ls = s[x] ^ s[y];
        printf("%d\n", ls);
      }
    }
  }
}
