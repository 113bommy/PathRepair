#include <bits/stdc++.h>
using namespace std;
const int N = 100005, MX = 10;
int n, q, t, x, y, z, v;
bool chk[N];
bitset<MX> cur, f[MX], g[MX], bi[N];
void init() {
  for (int i = 1; i < MX; i++)
    for (int j = 1; j <= i; j++)
      if (i % j == 0) f[i].set(j);
  chk[1] = true;
  for (int i = 2; i < MX; i++) {
    cur.reset();
    cur.set(i);
    for (int j = MX - 1; j > 1; j--)
      if (cur.test(j)) cur ^= f[j];
    chk[i] = cur.test(1);
  }
  for (int i = 1; i < MX; i++)
    for (int j = i; j < MX; j += i)
      if (chk[j / i]) g[i].set(j);
}
int main() {
  init();
  scanf("%d%d", &n, &q);
  while (q--) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &x, &v);
      bi[x] = f[v];
    } else if (t == 2) {
      scanf("%d%d%d", &x, &y, &z);
      bi[x] = bi[y] ^ bi[z];
    } else if (t == 3) {
      scanf("%d%d%d", &x, &y, &z);
      bi[x] = bi[y] & bi[z];
    } else {
      scanf("%d%d", &x, &v);
      cur = bi[x] & g[v];
      printf("%d", cur.count() & 1);
    }
  }
}
