#include <bits/stdc++.h>
using namespace std;
void solve(long long n, long long k) {
  long long cnt = 0;
  if (n > k * k - k)
    puts("NO");
  else {
    puts("YES");
    for (long long i = 1; i <= k; ++i)
      for (long long j = i + 1; j <= k; ++j) {
        printf("%lld %lld\n", i, j);
        if (++cnt > n) return;
        printf("%lld %lld\n", j, i);
        if (++cnt > n) return;
      }
  }
}
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  solve(n, k);
}
