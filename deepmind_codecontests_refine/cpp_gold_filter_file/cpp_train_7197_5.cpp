#include <bits/stdc++.h>
using namespace std;
int main() {
  long long pa = 0, pb = 0;
  long long a, b;
  int n;
  scanf("%d", &n);
  long long ans = 0;
  while (n--) {
    scanf("%I64d%I64d", &a, &b);
    ans += max(min(a, b) - max(pa, pb) + 1, 0LL);
    pa = a, pb = b;
    if (pa == pb) pa++, pb++;
  }
  printf("%I64d\n", ans);
}
