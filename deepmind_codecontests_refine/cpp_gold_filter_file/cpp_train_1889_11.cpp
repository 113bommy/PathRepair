#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long cnt;
  while (scanf("%d", &n) != EOF) {
    cnt = 0;
    long long sum = 0;
    while (n--) {
      long long m;
      scanf("%I64d", &m);
      long long i = m / 2;
      long long j = sum - 3 * cnt;
      if (i <= j)
        cnt += i;
      else
        cnt = cnt + j + (m - 2 * j) / 3;
      sum += m;
    }
    printf("%I64d\n", cnt);
  }
  return 0;
}
