#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2e5 + 10;
int q, a, b;
long long n;
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%lld%d%d", &n, &a, &b);
    long long ans = 0;
    if (a < b / 2)
      ans = n * a;
    else
      ans = (n / 2) * b + (n & 1) * a;
    printf("%lld\n", ans);
  }
  return 0;
}
