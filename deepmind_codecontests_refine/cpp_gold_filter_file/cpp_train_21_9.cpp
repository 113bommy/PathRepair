#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n, l, r;
    scanf("%lld%lld%lld", &n, &l, &r);
    long long suml = 0, sumr = 0;
    long long headl = 1, headr = -1;
    long long flag1 = 0;
    for (long long i = 1; i < n; ++i) {
      if (!flag1) {
        suml += 2 * (n - i);
      }
      sumr += 2 * (n - i);
      if (suml >= l && !flag1) {
        suml -= 2 * (n - i);
        flag1 = 1;
        headl = i;
      } else if (sumr >= r) {
        headr = i;
        break;
      }
    }
    long long vv = 0;
    if (headr == -1) {
      vv = 1;
    }
    long long flag = 1;
    long long now = headl + 1;
    for (long long i = suml + 1; i <= sumr; ++i) {
      if (flag == 1) {
        if (l <= i && i <= r) {
          printf("%lld ", headl);
        }
        flag = 2;
      } else if (flag == 2) {
        if (l <= i && i <= r) {
          printf("%lld ", now);
        }
        now++;
        if (now > n) {
          headl++;
          now = headl + 1;
        }
        flag = 1;
      }
    }
    if (vv == 1) {
      printf("1 ");
    }
    putchar('\n');
  }
  return 0;
}
