#include <bits/stdc++.h>
using namespace std;
int t;
long long n, m, k;
long long blocks[233333];
long long mmax(long long a, long long b) { return (a > b ? a : b); }
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &blocks[i]);
    for (int i = 1; i < n; i++) {
      if (blocks[i] > blocks[i + 1] - k)
        m += blocks[i] - mmax(blocks[i + 1] - k, 0LL);
      if (blocks[i + 1] - blocks[i] > k) {
        m -= blocks[i + 1] - blocks[i] - k;
        if (m < 0) break;
      }
    }
    if (m >= 0)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
