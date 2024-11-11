#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141592653589793;
long long a, b, n;
long long l, t, m;
long long MySearch() {
  long long L = 0, R = 1e6, MID, cnt;
  long long A = a + (l - 1) * b, B = b;
  while (R - L > 1) {
    MID = (L + R) >> 1LL;
    cnt = max(A + (MID - 1LL) * B,
              ((2 * A + B * (MID - 1LL)) * MID / (2LL) - 1LL) / m + 1);
    if (cnt <= t)
      L = MID;
    else
      R = MID;
  }
  if (L == 0) return -1;
  return L + l - 1;
}
void init() { scanf("%I64d %I64d %I64d", &a, &b, &n); }
void work() {
  for (long long i = 1; i <= n; i++) {
    scanf("%I64d%I64d%I64d", &l, &t, &m);
    printf("%I64d\n", MySearch());
  }
}
int main() {
  init();
  work();
  return 0;
}
