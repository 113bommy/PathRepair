#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
const int inf = 1e9;
int a[maxn];
int t;
long long n, k;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld", &n, &k);
    long long p = (n - k) / (k + 1);
    printf("%lld\n", n * (n + 1) / 2 - p * (p + 1) / 2 * (k + 1) -
                         (p + 1) * ((n - k) % (k + 1)));
  }
  return 0;
}
