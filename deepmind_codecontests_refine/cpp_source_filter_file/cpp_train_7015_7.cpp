#include <bits/stdc++.h>
using namespace std;
const int PMOD = 95542721;
const int LEN = 48;
const int MAX = int(1e5) + 10;
int N;
int a[MAX];
int T[MAX << 2][LEN], lup[MAX << 2];
int tmp[LEN];
int mod(int x, int md) {
  while (x >= md) x -= md;
  return x;
}
void move(int nod, int p) {
  memcpy(tmp, T[nod], sizeof tmp);
  for (int i = 0; i < LEN; i++) T[nod][i] = tmp[mod(i + p, LEN)];
}
void update(int nod, int I, int D) {
  for (int i = 0; i < LEN; i++) T[nod][i] = mod(T[I][i] + T[D][i], PMOD);
}
void lazy(int nod, int I, int D) {
  if (!lup[nod]) return;
  move(I, lup[nod]);
  move(D, lup[nod]);
  lup[I] = mod(lup[I] + lup[nod], LEN);
  lup[D] = mod(lup[D] + lup[nod], LEN);
  lup[nod] = 0;
}
void build(int nod, int lo, int hi) {
  if (lo == hi) {
    for (int i = 0; i < LEN; i++) {
      a[lo] %= PMOD;
      T[nod][i] = a[lo];
      a[lo] = a[lo] * a[lo] % PMOD * a[lo] % PMOD;
    }
    return;
  }
  int mit = (lo + hi) >> 1, I = nod << 1, D = I + 1;
  build(I, lo, mit);
  build(D, mit + 1, hi);
  update(nod, I, D);
}
void modify(int nod, int lo, int hi, int a, int b) {
  if (b < lo || hi < a) return;
  if (a <= lo && hi <= b) {
    lup[nod] = mod(lup[nod] + 1, LEN);
    move(nod, 1);
    return;
  }
  int mit = (lo + hi) >> 1, I = nod << 1, D = I + 1;
  lazy(nod, I, D);
  modify(I, lo, mit, a, b);
  modify(D, mit + 1, hi, a, b);
  update(nod, I, D);
}
int query(int nod, int lo, int hi, int a, int b) {
  if (b < lo || hi < a) return 0;
  if (a <= lo && hi <= b) return T[nod][0];
  int mit = (lo + hi) >> 1, I = nod << 1, D = I + 1;
  lazy(nod, I, D);
  int ret = 0;
  ret += query(I, lo, mit, a, b);
  ret += query(D, mit + 1, hi, a, b);
  return mod(ret, PMOD);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) scanf("%d", a + i);
  build(1, 1, N);
  int q;
  scanf("%d", &q);
  while (q--) {
    int typ, l, r;
    scanf("%d%d%d", &typ, &l, &r);
    if (typ == 1)
      printf("%d\n", query(1, 1, N, l, r));
    else
      modify(1, 1, N, l, r);
  }
  return 0;
}
