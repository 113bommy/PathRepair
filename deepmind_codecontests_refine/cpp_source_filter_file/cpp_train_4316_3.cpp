#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
const int IT_MAX = 131072;
const long long MOD = 1000000007;
const int INF = 2034567891;
const long long LL_INF = 1234567890123456789ll;
int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    long long N, K, d1, d2, i, j;
    scanf("%I64d %I64d %I64d %I64d", &N, &K, &d1, &d2);
    if (N % 3 != 0) {
      printf("no\n");
      continue;
    }
    for (i = -1; i <= 1; i += 2) {
      for (j = -1; j <= 1; j += 2) {
        long long t1 = d1 * i, t2 = d2 * i;
        long long x1, x2, x3;
        if ((K - t1 - 2 * t2) % 3 != 0 || (K - t1 - 2 * t2) < 0) continue;
        x3 = (K - t1 - 2 * t2) / 3;
        x2 = x3 + t2;
        x1 = x2 + t1;
        if (max(max(x1, x2), x3) <= N / 3 && min(min(x1, x2), x3) >= 0) break;
      }
      if (j <= 1) break;
    }
    if (i <= 1)
      printf("yes\n");
    else
      printf("no\n");
  }
  return 0;
}
