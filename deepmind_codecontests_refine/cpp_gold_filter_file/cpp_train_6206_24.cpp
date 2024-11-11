#include <bits/stdc++.h>
using namespace std;
bitset<64> e[64], clique;
int ans, n;
void maxClique(bitset<64> used, bitset<64> avail) {
  if (avail.none()) {
    int size = used.count();
    if (size > ans) {
      ans = size;
      clique = used;
    }
    return;
  }
  if ((used | avail).count() <= ans) return;
  int i = 0;
  while (!avail.test(i)) i++;
  bitset<64> cur = avail & ~e[i];
  for (int j = 0; j < n; j++) {
    if (cur.test(j)) {
      used.set(j);
      maxClique(used, avail & e[j]);
      used.reset(j);
      avail.reset(j);
    }
  }
}
int main() {
  int k, x;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &x);
      if (x == 1) {
        e[i].set(j);
        e[j].set(i);
      }
    }
  }
  maxClique(bitset<64>(), ~bitset<64>());
  printf("%.9lf", (double)k * k * (ans - 1) / 2 / ans);
}
