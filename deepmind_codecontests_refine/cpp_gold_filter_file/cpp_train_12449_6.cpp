#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
uint64_t rnd_data = 0xDEADBEEFDULL;
inline void my_srand(int seed) { rnd_data = ((uint64_t)seed << 16) | 0x330E; }
inline int my_rand() {
  rnd_data = rnd_data * 0x5DEECE66DULL + 0xB;
  return (rnd_data >> 17) & 0x7FFFFFFF;
}
template <typename T>
void my_random_shuffle(T b, T e) {
  for (int i = (1); i <= (int)((int)(e - b) - 1); i++) {
    swap(b[i], b[my_rand() % (i + 1)]);
  }
}
template <class _T>
inline _T sqr(const _T &x) {
  return x * x;
}
long long d[16][16][2][16];
int t[16][16];
int dma[1 << 16];
void precalc() {
  memset((t), 0, sizeof(t));
  for (int i = 0; i < (int)(1 << 16); i++) {
    int x = i;
    int ma = 0;
    for (int j = 0; j < (int)(4); j++) {
      int z = x & 15;
      ma = max(ma, z);
      x >>= 4;
    }
    dma[i] = ma;
    for (int j = 0; j < (int)(16); j++) {
      if (i & (1 << j)) t[ma][j]++;
    }
  }
}
inline long long *rec(int s, int lim, int cur_ma, int b, long long n) {
  int ds = s >> 2;
  long long *ans = d[ds][cur_ma][b];
  if (ans[0] >= 0) return ans;
  for (int i = 0; i < (int)(16); i++) {
    ans[i] = 0;
  }
  if (s < lim) {
    if (b) ans[cur_ma] = 1;
    return ans;
  }
  int ma = b ? 15 : ((n >> s) & 15);
  for (int i = (0); i <= (int)(ma); i++) {
    long long *add = rec(s - 4, lim, max(cur_ma, i), b || i < ma, n);
    for (int j = 0; j < (int)(16); j++) {
      ans[j] += add[j];
    }
  }
  return ans;
}
long long solve(long long n) {
  if (n <= 0) return 0;
  long long ans = 0;
  int r = n & 0xffff;
  if (r >= 0x8000) n += 0x10000;
  memset(d, 0xff, sizeof(d));
  long long *cma = rec(60, 16, 0, 0, n);
  long long sum = 0;
  for (int i = 0; i < (int)(16); i++) {
    sum += cma[i];
    ans += t[i][i] * sum;
  }
  for (int i = 0; i < (int)(16); i++) {
    long long sum = 0;
    for (int j = 0; j < (int)(i); j++) {
      sum += t[j][i];
    }
    ans += cma[i] * sum;
  }
  if (r >= 0x8000) n -= 0x10000;
  int lma = 0;
  for (int i = (4); i <= (int)(14); i++) {
    int z = (n >> (i * 4)) & 15;
    lma = max(lma, z);
  }
  if (r >= 0x8000) {
    for (int i = (r + 1); i <= (int)(0xffff); i++) {
      int z = max(dma[i], lma);
      ans -= (i >> z) & 1;
    }
  } else {
    for (int i = (0); i <= (int)(r); i++) {
      int z = max(dma[i], lma);
      ans += (i >> z) & 1;
    }
  }
  return ans;
}
int main() {
  precalc();
  int qq;
  scanf("%d", &qq);
  while (qq--) {
    long long l, r;
    scanf("%llx%llx", &l, &r);
    long long ans = solve(r) - solve(l - 1);
    printf("%lld\n", ans);
  }
  return 0;
}
