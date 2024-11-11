#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  long long sum1 = 0, sum2 = 0;
  for (int i = 1, _b = (n); i <= _b; i++) {
    int x;
    scanf("%d", &x);
    if (x >= 0)
      sum1 += x;
    else
      sum2 += x;
  }
  long long ans = sum1 - sum2;
  printf("%lld\n", ans);
  return 0;
}
