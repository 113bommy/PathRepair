#include <bits/stdc++.h>
using namespace std;
long long l, r;
int main() {
  scanf("%lld%lld", &r, &l);
  long long num1, num2, ans;
  num1 = l - 1, num2 = r - l;
  if (num1 > num2)
    ans = max(l - 1, 1ll);
  else
    ans = min(l + 1, r);
  printf("%lld\n", ans);
  return 0;
}
