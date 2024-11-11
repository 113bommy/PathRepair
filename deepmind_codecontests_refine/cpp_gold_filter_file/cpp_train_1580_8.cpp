#include <bits/stdc++.h>
using namespace std;
int const N = 100000, M = 2000000, md = 998244353;
int x[N], fc[M], inv[M], fcin[M];
int ch(int n, int r) {
  return (long long)fc[n] * fcin[r] % md * fcin[n - r] % md;
}
int fancyCh(int n, int p) { return ch(n + p - 1, p); }
void ad(int &x, int y) {
  if ((x += y) >= md) x -= md;
}
int main() {
  fc[0] = 1;
  for (int i = 1; i < (int)(M); ++i) fc[i] = (long long)fc[i - 1] * i % md;
  inv[1] = 1;
  for (int i = 2; i < (int)(M); ++i)
    inv[i] = md - md / i * (long long)inv[md % i] % md;
  fcin[0] = 1;
  for (int i = 1; i < (int)(M); ++i)
    fcin[i] = (long long)fcin[i - 1] * inv[i] % md;
  int k;
  scanf("%d", &k);
  for (int i = 0; i < (int)(k); ++i) scanf("%d", x + i);
  sort(x, x + k);
  bool dead = false;
  for (int i = 0; i < (int)(k); ++i)
    if (x[i] < i) {
      dead = true;
      break;
    }
  int an = 0;
  if (dead) {
    int j = 0;
    for (int i = 0; i < (int)(k); ++i) {
      while (j < k && x[j] < i) ++j;
      if (j > i) break;
      ad(an, fancyCh(k, i - j));
    }
  } else {
    int s = 0, j = 0;
    for (int i = 0; i < (int)(k); ++i) s += x[i] / k;
    for (int i = 0; i < (int)(k); ++i) x[i] %= k;
    sort(x, x + k);
    for (int i = 0; i < (int)(k); ++i) {
      ad(an, fancyCh(k, s));
      ++s;
      while (j < k && x[j] == i) ++j, --s;
    }
  }
  printf("%d\n", an);
}
