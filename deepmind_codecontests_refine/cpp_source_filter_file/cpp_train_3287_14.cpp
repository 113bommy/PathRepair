#include <bits/stdc++.h>
using namespace std;
long long pil, n, k, ls, ld, ras, l;
int andreea(long long l) {
  long long dr, st;
  st = l * (l - 1) / 2;
  if (l > k) st = st - (l - k) * (l - k + 1) / 2;
  if (st < 0) st = 0;
  dr = l * (l - 1) / 2;
  if (l > n - k + 1) dr = dr - (l - n + k) * (l - n + k + 1) / 2;
  if (dr < 0) dr = 0;
  if (st + dr + l > pil) return 0;
  return 1;
}
int main() {
  scanf("%I64d%I64d%I64d", &n, &pil, &k);
  pil = pil - n;
  ls = 1;
  ld = pil;
  while (ls <= ld) {
    l = (ls + ld) / 2;
    if (andreea(l)) {
      if (ras < l) ras = l;
      ls = l + 1;
    } else
      ld = l - 1;
  }
  printf("%I64d", ras + 1);
  return 0;
}
