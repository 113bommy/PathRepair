#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
long long n, m, k, ans, cnt, last, cut, tmp;
struct node {
  long long p, num, pre, ye;
} a[N];
int main() {
  scanf("%I64d%I64d%I64d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%I64d", &a[i].p);
    a[i].ye = ((a[i].p - 1) / k) + 1;
  }
  cnt = 1;
  last = a[1].ye;
  while (cnt <= m) {
    tmp = 0;
    while (cnt <= m) {
      a[cnt].ye = ((a[cnt].p - cut - 1) / k) + 1;
      if (a[cnt].ye == last)
        ++cnt, ++tmp;
      else
        break;
    }
    ++ans;
    cut += tmp;
    last = ((a[cnt].p - cut - 1) / k) + 1;
  }
  printf("%I64d\n", ans);
  return 0;
}
