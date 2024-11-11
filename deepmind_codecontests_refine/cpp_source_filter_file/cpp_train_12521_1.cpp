#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
struct Bitset {
  unsigned long long v[16];
  Bitset() { memset(v, 0, sizeof v); }
  inline Bitset operator^(const Bitset &x) const {
    Bitset z;
    for (int i = 0; i < 16; i++) z.v[i] = v[i] ^ x.v[i];
    return z;
  }
  inline void set(int x) { v[x >> 6] |= 1ull << (x & 63); }
  inline unsigned long long hash() {
    unsigned long long z = 0, fac = 1;
    for (int i = 0; i < 16; i++, fac *= 57285791275032) z += v[i] * fac;
    return z;
  }
};
int n, s, q, cnt, x, val[1 << 12 | 1];
Bitset v[1 << 12 | 1], a[35];
map<unsigned long long, int> Map;
int main() {
  scanf("%d%d%d", &n, &s, &q);
  for (int i = 0; i < s; i++) {
    scanf("%d", &cnt);
    while (cnt--) scanf("%d", &x), a[i].set(x);
  }
  int Cnt = min(12, s);
  for (int i = 0; i < 1 << Cnt; i++)
    for (int j = 0; j < Cnt; j++)
      if ((1 << j) & i) v[i] = v[i] ^ a[j], val[i]++;
  for (int i = 0; i < 1 << (s - Cnt); i++) {
    Bitset now;
    int cnt = 0;
    for (int j = Cnt; j < s; j++)
      if ((1 << (j - Cnt)) & i) now = now ^ a[j], cnt++;
    unsigned long long z = now.hash();
    if (!Map.count(z) || Map[z] > cnt) Map[z] = cnt;
  }
  while (q--) {
    Bitset now;
    scanf("%d", &cnt);
    while (cnt--) scanf("%d", &x), now.set(x);
    int ans = 1e9;
    for (int i = 0; i < 1 << Cnt; i++) {
      unsigned long long z = (now ^ v[i]).hash();
      if (Map.count(z)) ans = min(ans, Map[z] + val[i]);
    }
    if (ans == 1e9)
      puts("-1");
    else
      printf("%d\n", ans);
  }
}
