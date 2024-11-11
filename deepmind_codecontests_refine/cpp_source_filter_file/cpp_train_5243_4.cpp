#include <bits/stdc++.h>
using namespace std;
void reop_func(const char *in) { freopen(in, "r", stdin); }
long long binpow(long long v, long long p) {
  long long ans = 1LL;
  for (; p; p >>= 1LL, v *= v, v %= 1000 * 1000 * 1000 + 7)
    if (p & 1LL) ans *= v, ans %= (long long)1000 * 1000 * 1000 + 7;
  return ans;
}
int main() {
  ;
  int n = 0;
  scanf("%d", &n);
  int p[] = {1,       2,       4,       6,        12,      16,      18,
             30,      60,      88,      106,      126,     520,     606,
             1278,    2202,    2280,    3216,     4252,    4422,    9688,
             9940,    11212,   19936,   21700,    23208,   44496,   86242,
             110502,  132048,  216090,  756838,   859432,  1257786, 1398268,
             2976220, 3021376, 6972592, 13466916, 20996011};
  printf("%I64d", binpow(2, p[n - 1]) == 0LL
                      ? ((long long)1000 * 1000 * 1000 + 7 - 1LL)
                      : binpow(2, p[n - 1]) - 1LL);
  return 0;
}
