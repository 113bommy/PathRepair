#include <bits/stdc++.h>
int F(const void* x, const void* y) { return *(int*)x - *(int*)y; }
unsigned N[555555], n;
unsigned lo(unsigned k) {
  unsigned i;
  long long unsigned r = 0llu, t;
  for (i = 0; ++i < n;)
    if ((r += (t = (N[i] - N[i - 1]) * (long long unsigned)i)) > k)
      return N[i - 1] + (k - (r - t)) / i;
  return N[n - 1];
}
unsigned hi(unsigned k) {
  unsigned i;
  long long unsigned r = 0llu, t;
  for (i = n; --i;)
    if ((r += (t = (N[i] - N[i - 1]) * (long long unsigned)(n - i))) > k)
      return N[i] - (k - (r - t)) / (n - i);
  return *N;
}
int main() {
  unsigned i = -1, k, l, h;
  long long unsigned s = 0;
  for (scanf("%u%u", &n, &k); ++i < n; s += (N[i] = l)) scanf("%u", &l);
  qsort(N, n, sizeof(unsigned), F);
  l = lo(k);
  h = hi(k);
  printf("%u\n", l >= h ? s % n ? 1 : 0 : h - l);
  return 0;
}
