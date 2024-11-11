#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans;
  scanf("%d", &n);
  printf("2\n");
  for (long long i = 2; i <= n; i++) {
    ans = (i + 1) * (i + 1) * i - (i - 1);
    printf("%I64d\n", ans);
  }
  return 0;
}
