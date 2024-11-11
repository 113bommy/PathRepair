#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 20;
struct node {
  long long a[5];
  int siz;
};
node f[N * 8];
int ls[N], qu[N], query[N], n;
char s[12];
void pushup(int u) {
  int ls = u * 2, rs = u * 2 + 1;
  for (int i = 0; i < 5; i++) f[u].a[i] = f[ls].a[i];
  f[u].siz = f[ls].siz + f[rs].siz;
  for (int i = 0; i < 5; i++) f[u].a[(f[ls].siz + i) % 5] += f[rs].a[i];
}
void update(int u, int l, int r, int x, int p) {
  if (r < x || l > x) return;
  if (l == r && l == x) {
    f[u].a[1] += p;
    if (f[u].a[1] == 0)
      f[u].siz = 0;
    else
      f[u].siz = 1;
    return;
  }
  int mid = l + r >> 1;
  update(u * 2, l, mid, x, p);
  update(u * 2 + 1, mid + 1, r, x, p);
  pushup(u);
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    if (s[0] == 'a')
      query[i] = 0;
    else if (s[0] == 'd')
      query[i] = 1;
    else
      query[i] = 2;
    if (query[i] < 2) {
      int x;
      scanf("%d", &x);
      qu[i] = x;
      ls[++cnt] = x;
    }
  }
  sort(ls + 1, ls + cnt + 1);
  cnt = unique(ls + 1, ls + cnt + 1) - ls - 1;
  for (int i = 1; i <= n; i++) {
    if (query[i] == 0) {
      int x = lower_bound(ls + 1, ls + cnt + 1, qu[i]) - ls;
      update(1, 1, cnt, x, qu[i]);
    } else if (query[i] == 1) {
      int x = lower_bound(ls + 1, ls + cnt + 1, qu[i]) - ls;
      update(1, 1, cnt, x, -qu[i]);
    } else
      printf("%d\n", f[1].a[3]);
  }
  return 0;
}
