#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000")
using namespace std;
long long n, m;
long long F(long long x) {
  if (x < 0) return 0;
  long long r = floor(sqrt((double)x)) + 1;
  return r;
}
int main() {
  scanf("%I64d %I64d", &n, &m);
  long long res = 0;
  for (long long b = 1; b <= n; b++) {
    long long l = 1, r = m;
    long long L = b * b - r, R = b * b - l;
    if (R <= 0) continue;
    if (L < 0) {
      L = 0;
      r = b * b;
    }
    if (l > r) continue;
    long long count = (r - l + 1);
    count -= F(R) - F(L - 1);
    res += count;
  }
  res = res * 2;
  for (long long x = 1; x <= 5000010; x++) {
    bool ok = false;
    for (int(j) = (1); (j) < (3); ++(j)) {
      if (x * (j) <= m && x * (j) > 0)
        if ((x + j) % 2 == 0)
          if (x + j <= 2 * n && x + j > 0) ok = true;
    }
    if (ok) {
      res++;
    }
  }
  printf("%I64d\n", res);
  return 0;
}
