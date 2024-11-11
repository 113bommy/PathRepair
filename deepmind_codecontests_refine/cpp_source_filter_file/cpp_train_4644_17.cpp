#include <bits/stdc++.h>
using namespace std;
int n, nxt[3200010][2], siz[3200010], cnt;
inline void insert(int x, int v) {
  int y = 0;
  for (int z = 2; ~z; z--) {
    if (!nxt[y][(x >> z) & 1]) nxt[y][(x >> z) & 1] = ++cnt;
    y = nxt[y][(x >> z) & 1], siz[y] += v;
  }
}
inline int query(int x, int y) {
  int p = 0, ret = 0;
  for (int z = 2, w; z >= 0; z--) {
    w = (y >> z) & 1;
    if (!w)
      p = nxt[p][(x >> z) & 1];
    else
      ret += siz[nxt[p][(x >> z) & 1]], p = nxt[p][((x >> z) & 1) ^ 1];
    if (!p) break;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  while (n--) {
    int op, x, y;
    scanf("%d%d", &op, &x);
    if (op == 1)
      insert(x, 1);
    else if (op == 2)
      insert(x, -1);
    else
      scanf("%d", &y), printf("%d\n", query(x, y));
  }
  return 0;
}
