#include <bits/stdc++.h>
using namespace std;
long long int lvl[64] = {0};
long long int sft[64] = {0};
void init() {
  long long int i, j, k = 1;
  for (i = 1; i < 64; i++) {
    lvl[i] = k;
    k *= 2;
  }
  return;
}
long long int levelof(long long int n) {
  long long int i, j, k, l;
  k = 1;
  l = 0;
  for (i = 1; i < 64; i++) {
    l += lvl[i];
    if (l >= n) {
      return k;
    }
    k++;
  }
  return k;
}
void addshift(long long int lvlofx, long long int n) {
  long long int i, j, k, m;
  if (n == 0) {
    return;
  }
  if (lvlofx == 1) {
    return;
  }
  n %= lvl[lvlofx];
  if (n < 0) {
    n += lvl[lvlofx];
  }
  sft[lvlofx] += n;
  sft[lvlofx] %= lvl[lvlofx];
  return;
}
void addlayershift(long long int lvlofx, long long int n) {
  long long int i, j, k, l, m;
  if (n == 0) {
    return;
  }
  if (lvlofx == 1) {
    return;
  }
  for (i = lvlofx; i < 64; i++) {
    n %= lvl[i];
    addshift(i, n);
    n *= 2;
  }
  return;
}
void print(long long int n) {
  long long int i, j, k, l;
  printf("%lld ", n);
  long long int lvlofx = levelof(n);
  k = n + sft[lvlofx];
  if (k >= lvl[lvlofx + 1]) {
    l = k - lvl[lvlofx + 1] + 1;
    k = l + lvl[lvlofx];
  }
  for (i = lvlofx - 1; i > 0; i--) {
    l = k / 2;
    j = l - sft[i];
    if (j < lvl[i]) {
      j += lvl[i];
    }
    printf("%lld ", j);
    k /= 2;
  }
  printf("\n");
  return;
}
int main() {
  long long int n, q, m, i, j, k, l, chk, x;
  init();
  long long int levelofx;
  scanf("%lld", &q);
  while (q--) {
    scanf("%lld", &chk);
    if (chk == 1) {
      scanf("%lld %lld", &x, &k);
      levelofx = levelof(x);
      addshift(levelofx, k);
    } else if (chk == 2) {
      scanf("%lld %lld", &x, &k);
      levelofx = levelof(x);
      addlayershift(levelofx, k);
    } else {
      scanf("%lld", &x);
      print(x);
    }
  }
}
