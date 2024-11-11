#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  long long ans[100000];
  long long k = 0;
  int i;
  memset(ans, 0, sizeof ans);
  scanf("%lld", &n);
  for (i = 1; i <= 100; i++) {
    if (n - i < 0)
      continue;
    else {
      long long s = n - i;
      long long sum = n - i;
      while (s) {
        sum += s % 10;
        s = s / 10;
      }
      if (sum == n) ans[k++] = n - i;
    }
  }
  printf("%lld\n", k);
  for (i = 0; i < k; i++) printf("%lld\n", ans[i]);
}
