#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  for (int ks = 1; ks <= t; ks++) {
    long long x;
    scanf("%I64d", &x);
    if (x == 0) {
      printf("1 1\n");
      continue;
    }
    long long sq;
    sq = sqrt((double)x);
    bool flag = false;
    long long n, m;
    for (long long uu = sq + 1; uu <= 40000; uu++) {
      long long sum = uu * uu;
      long long lo = 2;
      long long hi = uu;
      while (lo <= hi) {
        long long vv = (lo + hi) / 2;
        long long zero = (uu / vv) * (uu / vv);
        long long one = sum - zero;
        if (one == x) {
          flag = true;
          n = uu;
          m = vv;
          break;
        } else if (one > x)
          hi = vv - 1;
        else
          lo = vv + 1;
      }
      if (flag == true) break;
    }
    if (flag)
      printf("%I64d %I64d\n", n, m);
    else
      printf("-1\n");
  }
  return 0;
}
