#include <bits/stdc++.h>
using namespace std;
struct Node {
  int l, r, mid, val;
} tre[2000005];
int a[500005], b[500005];
int maxx(int x1, int x2) {
  if (b[x2] > b[x1])
    return x2;
  else
    return x1;
}
void build(int x, int l, int r) {
  tre[x].l = l;
  tre[x].r = r;
  tre[x].mid = (l + r) / 2;
  if (l != r) {
    build(x * 2, tre[x].l, tre[x].mid);
    build(x * 2 + 1, tre[x].mid + 1, tre[x].r);
    tre[x].val = maxx(tre[x * 2].val, tre[x * 2 + 1].val);
  } else
    tre[x].val = l;
}
void del(int x, int now) {
  if (tre[x].l == tre[x].r)
    tre[x].val = 0;
  else {
    if (now <= tre[x].mid)
      del(x * 2, now);
    else
      del(x * 2 + 1, now);
    tre[x].val = maxx(tre[x * 2].val, tre[x * 2 + 1].val);
  }
}
int ask(int x, int r) {
  if (!r) return 0;
  if (tre[x].r == r)
    return tre[x].val;
  else {
    if (r > tre[x].mid)
      return maxx(tre[x * 2].val, ask(x * 2 + 1, r));
    else
      return ask(x * 2, r);
  }
}
bool life[500005];
int n, cnt = 0;
int p[500005];
void dfs(int x) {
  int temp;
  if (life[x]) return;
  life[x] = 1;
  del(1, x);
  if (b[x] <= n) dfs(b[x]);
  while (temp = ask(1, a[x]), temp && b[temp] > x) dfs(temp);
  p[x] = ++cnt;
}
int main() {
  scanf("%d", &n);
  life[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == -1)
      a[i] = n + 1;
    else
      b[a[i]] = i;
    a[i]--;
  }
  for (int i = 1; i <= n; i++)
    if (!b[i]) b[i] = n + 1;
  build(1, 1, n);
  for (int i = 1; i <= n; i++) dfs(i);
  for (int i = 1; i <= n; i++) {
    if (i > 1) printf(" ");
    printf("%d", p[i]);
  }
  printf("\n");
  return 0;
}
