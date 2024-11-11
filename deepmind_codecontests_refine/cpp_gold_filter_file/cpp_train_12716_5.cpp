#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c;
  while (scanf("%lld %lld %lld", &a, &b, &c) != EOF) {
    long long ans = c * 2 + min(a, b) * 2 + (a > b);
    ans = max(ans, min(a, b) * 2 + c * 2 + (b > a));
    printf("%lld\n", ans);
  }
  return 0;
}
