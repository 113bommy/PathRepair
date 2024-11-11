#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int uf[N];
int xor_val[N];
int idx = 0;
map<int, int> mp;
int get(int x) {
  if (mp.find(x) != mp.end()) return mp[x];
  mp[x] = idx;
  xor_val[idx] = 0;
  uf[idx] = idx;
  idx++;
  return idx - 1;
}
int FIND(int u) {
  if (u != uf[u]) {
    int par = FIND(uf[u]);
    xor_val[u] ^= xor_val[uf[u]];
    return uf[u] = par;
  }
  return uf[u];
}
int main() {
  int q;
  scanf("%d", &q);
  int last = 0;
  while (q--) {
    int typ;
    scanf("%d", &typ);
    if (typ == 1) {
      int l, r, x;
      scanf("%d %d %d", &l, &r, &x);
      l ^= last;
      r ^= last;
      x ^= last;
      if (l > r) swap(l, r);
      r += 2;
      l = get(l);
      r = get(r);
      int root1 = FIND(l);
      int root2 = FIND(r);
      if (root1 != root2) {
        uf[root1] = root2;
        xor_val[root1] = xor_val[l] ^ xor_val[r] ^ x;
      }
    } else {
      int l, r;
      scanf("%d %d", &l, &r);
      l ^= last;
      r ^= last;
      if (l > r) swap(l, r);
      r += 2;
      l = get(l);
      r = get(r);
      int root1 = FIND(l);
      int root2 = FIND(r);
      if (root1 != root2) {
        cout << -1 << endl;
        last = 1;
      } else {
        cout << (xor_val[l] ^ xor_val[r]) << endl;
        last = xor_val[l] ^ xor_val[r];
      }
    }
  }
}
