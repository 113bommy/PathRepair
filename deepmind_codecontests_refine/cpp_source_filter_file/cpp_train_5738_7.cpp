#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main() {
  int n, i;
  long long k, ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i) {
    scanf("%I64d", &k);
    ans += i * k;
  }
  ans -= n * (n - 1) / 2;
  printf("I64d", ans);
  return 0;
}
