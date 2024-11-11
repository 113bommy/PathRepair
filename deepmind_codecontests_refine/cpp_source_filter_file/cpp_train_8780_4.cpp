#include <bits/stdc++.h>
using namespace std;
const int inf = 1999999999;
const double pi = acos(-1.0);
const double eps = 1e-10;
const unsigned HPOW = 10000007;
const int MAXL = 200100;
struct bit {
  unsigned* a;
  bit(unsigned* data) { a = data; }
  void add(int i, unsigned v) {
    i += 5;
    while (i < MAXL) {
      a[i] += v;
      i += (i & -i);
    }
  }
  unsigned get(int i) {
    i += 5;
    unsigned v = 0;
    while (i) {
      v += a[i];
      i -= (i & -i);
    }
    return v;
  }
};
struct mii {
  int a, b;
  mii() {}
  bool operator<(const mii& o) const { return a < o.a; }
};
int n, m;
unsigned bit1[MAXL], bit2[MAXL];
bit ord(bit1), geth(bit2);
int perm[MAXL];
int h[MAXL];
unsigned hashv[MAXL];
unsigned chash = 0, thash = 0;
int ansn;
void insert(int i) {
  int ch = h[i];
  chash += ord.get(ch - 1) * hashv[i % n];
  ord.add(ch, 1);
  chash += geth.get(200050 - ch - 1);
  geth.add(200050 - ch, hashv[i % n]);
}
void erase(int i) {
  int ch = h[i];
  chash -= ord.get(ch - 1) * hashv[i % n];
  ord.add(ch, -1);
  chash -= geth.get(200050 - ch - 1);
  geth.add(200050 - ch, -hashv[i % n]);
}
int main() {
  int t;
  scanf("%d%d", &n, &m);
  hashv[0] = 1;
  for (int i = 1; i <= n; i++) hashv[i] = hashv[i - 1] * HPOW;
  for (int i = 0; i < n; i++) {
    scanf("%d", &t);
    t--;
    perm[i] = t;
  }
  for (int i = 0; i < n; i++) thash += perm[i] * hashv[i];
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    t--;
    h[t] = i;
  }
  for (int i = 0; i < m; i++) {
    thash *= HPOW;
    thash += perm[n - 1 - (i % n)] * (1 - hashv[n]);
    insert(i);
    if (i >= n) erase(i - n);
    if (chash == thash && i + 1 >= n) {
      ansn++;
    }
  }
  printf("%d\n", ansn);
  return 0;
}
