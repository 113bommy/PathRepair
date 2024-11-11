#include <bits/stdc++.h>
using namespace std;
const int N = 300030;
const int D = N * 4;
const int mod = 1e9 + 7;
int n, p[N];
int seed[N];
int Unis;
int h0[D], h1[D];
void inc(int& a, int b) {
  if (a += b, a >= mod) a -= mod;
}
void ask0(int d, int lt, int rt, int lq, int rq) {
  if (lq <= lt && rt <= rq) {
    inc(Unis, (long long)h0[d] * seed[lt - lq] % mod);
  } else {
    int md = (lt + rt) >> 1;
    if (lq <= md) ask0(d << 1 | 0, lt, md, lq, rq);
    if (md < rq) ask0(d << 1 | 1, md + 1, rt, lq, rq);
  }
}
void ask1(int d, int lt, int rt, int lq, int rq) {
  if (lq <= lt && rt <= rq) {
    inc(Unis, (long long)h1[d] * seed[rq - rt] % mod);
  } else {
    int md = (lt + rt) >> 1;
    if (lq <= md) ask1(d << 1 | 0, lt, md, lq, rq);
    if (md < rq) ask1(d << 1 | 1, md + 1, rt, lq, rq);
  }
}
void modify(int d, int lt, int rt, int w) {
  if (lt == rt) {
    h0[d] = h1[d] = 1;
  } else {
    int md = (lt + rt) >> 1;
    if (w <= md) modify(d << 1 | 0, lt, md, w);
    if (md < w) modify(d << 1 | 1, md + 1, rt, w);
    h0[d] = h0[d << 1 | 0],
    inc(h0[d], (long long)h0[d << 1 | 1] * seed[md - lt + 1] % mod);
    h1[d] = h1[d << 1 | 1],
    inc(h1[d], (long long)h1[d << 1 | 0] * seed[rt - md] % mod);
  }
}
int query(int lq, int rq, int ty) {
  Unis = 0;
  if (ty == 0) ask0(1, 1, n, lq, rq);
  if (ty == 1) ask1(1, 1, n, lq, rq);
  return Unis;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", p + i);
  }
  for (int i = 0; i <= n; ++i) {
    seed[i] = !i ? 1 : (long long)seed[i - 1] * 233 % mod;
  }
  for (int i = 1; i <= n; ++i) {
    int L = min(p[i] - 1, n - p[i]);
    if (L && query(p[i] - L, p[i] - 1, 0) != query(p[i] + 1, p[i] + L, 1)) {
      printf("YES\n");
      return 0;
    }
    modify(1, 1, n, p[i]);
  }
  printf("NO\n");
}
