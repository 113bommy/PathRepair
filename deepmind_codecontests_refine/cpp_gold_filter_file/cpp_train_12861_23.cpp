#include <bits/stdc++.h>
using namespace std;
const int N = 300001;
long long m;
long long solve(long long x) {
  long long ans = 0;
  for (int k = 2; k < N; ++k) {
    long long c = 1ll * k * k * k;
    ans += x / c;
  }
  return ans;
}
int main() {
  scanf("%I64d", &m);
  long long l = 1, r = 1e16;
  while (l + 1 < r) {
    long long x = (l + r) / 2;
    if (solve(x) >= m)
      r = x;
    else
      l = x;
  }
  if (solve(r) == m)
    printf("%I64d\n", r);
  else
    printf("-1\n");
  return 0;
}
