#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    long long a, b, k;
    scanf("%lld%lld%lld", &a, &b, &k);
    long long ans;
    ans = (a - b) * (k / 2);
    if (k % 2) {
      ans += a;
    }
    printf("%lld", ans);
  }
}
