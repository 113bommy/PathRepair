#include <bits/stdc++.h>
using namespace std;
const long long inf = 1000000000000;
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  if (m == 3) {
    if (n >= 5)
      puts("-1");
    else {
      puts("0 0");
      puts("0 100");
      puts("100 0");
    }
    if (n == 4) puts("1 1");
  } else {
    for (long long i = 1; i <= m; ++i) {
      printf("%lld %lld\n", i, i * i + inf);
    }
    for (long long i = 1; i <= n - m; ++i)
      printf("%lld %lld\n", i, -i * i - inf);
  }
}
