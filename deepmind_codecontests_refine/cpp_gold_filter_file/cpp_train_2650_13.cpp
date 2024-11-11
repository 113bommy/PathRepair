#include <bits/stdc++.h>
using namespace std;
typedef long double real;
signed long long int l, r;
int k;
int bitcount(signed long long int num) {
  int res = 0;
  for (int i = 0; i < 43; ++i) {
    res += !!(num & (1ll << (signed long long int)(i)));
  }
  return res;
}
int main() {
  scanf("%I64d %I64d %d", &l, &r, &k);
  if (r - l + 1 < 16) {
    int sz = r - l + 1;
    vector<signed long long int> dp(1 << sz);
    dp[0] = 0;
    for (int mask = 1; mask < (int)(dp).size(); ++mask) {
      for (int j = 0; j < sz; ++j) {
        if (mask & (1 << j)) {
          dp[mask] = dp[mask ^ (1 << j)] ^ (l + j);
        }
      }
    }
    int mask = 0;
    signed long long int best = LLONG_MAX;
    for (int i = 1; i < (int)(dp).size(); ++i) {
      if (bitcount(i) > k) {
        continue;
      }
      if (dp[i] < best) {
        best = dp[i];
        mask = i;
      }
    }
    printf("%I64d\n%d\n", best, bitcount(mask));
    for (int j = 0; j < sz; ++j) {
      if (mask & (1 << j)) {
        printf("%I64d ", l + j);
      }
    }
    puts("");
  } else {
    if (k == 1) {
      printf("%I64d\n1\n%I64d\n", l, l);
      return 0;
    }
    if (k == 3) {
      signed long long int p = 1;
      while (1) {
        signed long long int p1 = (1ll << p) + (1ll << (p - 1));
        if (p1 > r) {
          break;
        }
        signed long long int p2 = p1 - 1;
        signed long long int p3 = (1ll << p) - 1;
        if (p3 >= l) {
          printf("0\n3\n%I64d %I64d %I64d\n", p1, p2, p3);
          return 0;
        }
        ++p;
      }
    }
    if (k <= 3) {
      while (l & 3) {
        ++l;
      }
      printf("1\n2\n%I64d %I64d\n", l, l + 1);
      return 0;
    }
    while (l & 3) {
      ++l;
    }
    printf("0\n4\n%I64d %I64d %I64d %I64d\n", l, l + 1, l + 2, l + 3);
  }
}
