#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int inf = 0x3f3f3f3f;
char m[maxn];
struct node {
  int l, r, maxx, minn, num;
};
node tr[maxn << 2];
void pushup(int e) {
  tr[e].num = tr[e << 1].num + tr[e << 1 | 1].num;
  tr[e].maxx = max(tr[e << 1].maxx, tr[e << 1].num + tr[e << 1 | 1].maxx);
  tr[e].minn = min(tr[e << 1].minn, tr[e << 1].num + tr[e << 1 | 1].minn);
}
void build(int e, int l, int r) {
  tr[e].l = l, tr[e].r = r, tr[e].maxx = 0, tr[e].minn = 0, tr[e].num = 0;
  if (l == r) return;
  int mid = (l + r) >> 1;
  build(e << 1, l, mid);
  build(e << 1 | 1, mid + 1, r);
}
void update(int e, int a, int b) {
  if (tr[e].l == tr[e].r) {
    tr[e].num = b;
    return;
  }
  int mid = (tr[e].l + tr[e].r) >> 1;
  if (a <= mid) update(e << 1, a, b);
  if (a > mid) update(e << 1 | 1, a, b);
  pushup(e);
}
int main() {
  int n, now = 1, all = 0;
  scanf("%d", &n);
  scanf("%s", m + 1);
  build(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    if (m[i] == 'L')
      now = max(1, now - 1);
    else if (m[i] == 'R')
      ++now;
    else {
      if (m[i] == ')')
        update(1, now, -1);
      else if (m[i] == '(')
        update(1, now, 1);
      else
        update(1, now, 0);
    }
    if (i != 1) putchar(' ');
    if (tr[1].num == 0 && tr[1].minn >= 0)
      printf("%d", tr[1].maxx);
    else
      printf("-1");
  }
  return 0;
}
