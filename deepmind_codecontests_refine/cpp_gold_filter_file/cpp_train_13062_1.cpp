#include <bits/stdc++.h>
using namespace std;
int SZ;
unsigned int ONE = 1, ALL = -1;
struct bits {
  unsigned int c[22];
  bits() { memset(c, 0, sizeof c); }
  void inter(const bits &a, bits &res) const {
    for (int i = 0; i < (SZ); ++i) res.c[i] = c[i] & a.c[i];
  }
  void set(int n) { c[n >> 5] |= (ONE << (n & 31)); }
  void unset(int n) { c[n >> 5] &= (ALL ^ (ONE << (n & 31))); }
  int cnt() const {
    int res = 0;
    for (int i = 0; i < (SZ); ++i) {
      if (c[i] != 0) res += __builtin_popcount(c[i]);
    }
    return res;
  }
  int cnt_inter(const bits &a) const {
    int res = 0;
    for (int i = 0; i < (SZ); ++i) {
      if ((c[i] & a.c[i]) != 0) res += __builtin_popcount(c[i] & a.c[i]);
    }
    return res;
  }
  int test(int n) {
    if (c[n >> 5] & (ONE << (n & 31))) return 1;
    return 0;
  }
};
bits adj[710], wsp[710][710];
int ile[710][710];
int main(void) {
  int n, m;
  long long res = 0LL;
  scanf("%d%d", &n, &m);
  SZ = n / 32 + (n % 32 ? 1 : 0);
  for (int i = 0; i < (m); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    adj[a].set(b);
    adj[b].set(a);
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = (i + 1); j < (n); ++j) {
      adj[i].inter(adj[j], wsp[i][j]);
      for (int k = 0; k < (i); ++k) wsp[i][j].unset(k);
      ile[i][j] = wsp[i][j].cnt();
    }
  }
  for (int i = 0; i < (n); ++i) {
    for (int j = (i + 1); j < (n); ++j) {
      for (int k = (j + 1); k < (n); ++k) {
        if (!adj[j].test(k)) continue;
        res +=
            (ile[i][j] - wsp[i][j].test(k)) * (ile[i][k] - wsp[i][k].test(j));
        res -= wsp[i][j].cnt_inter(wsp[i][k]);
      }
    }
  }
  printf("%I64d\n", res);
  return 0;
}
