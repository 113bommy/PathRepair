#include <bits/stdc++.h>
using namespace std;
int n, q, l, r, x;
struct node {
  int pos, val;
  int ty;
  node() {}
  node(int _pos, int _val, int _ty) : pos(_pos), val(_val), ty(_ty) {}
} ev[20005];
int f[3][10005];
bool flag[10005];
const int p[3] = {29, 402653189, 201326611};
bool cmp(const node& u, const node& v) { return u.pos < v.pos; }
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d%d", &l, &r, &x);
    ev[i * 2 - 1] = node(l, x, 1);
    ev[i * 2] = node(r + 1, x, -1);
  }
  sort(ev + 1, ev + q * 2 + 1, cmp);
  l = 0;
  memset(f, 0, sizeof f);
  memset(flag, false, sizeof flag);
  f[0][0] = f[1][0] = f[2][0] = 1;
  for (int i = 1; i <= n; i++) {
    while (l < q * 2 && ev[l + 1].pos <= i) {
      l++;
      if (ev[l].ty == 1)
        for (int j = n - ev[l].val; j >= 0; j--)
          for (int pr = 0; pr < 3; pr++)
            (f[pr][j + ev[l].val] += f[pr][j]) %= p[pr];
      else
        for (int j = 0, _end = n - ev[l].val; j <= _end; j++)
          for (int pr = 0; pr < 3; pr++)
            (f[pr][j + ev[l].val] += p[pr] - f[pr][j]) %= p[pr];
    }
    for (int i = 1; i <= n; i++)
      if (f[0][i] || f[1][i] || f[2][i]) flag[i] = true;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += flag[i] ? 1 : 0;
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    if (flag[i]) printf("%d ", i);
  puts("");
  return 0;
}
