#include <bits/stdc++.h>
using namespace std;
long long n, ans;
long long cal(long long x) {
  return (n >= x) ? (x - 1) / 2 : ((n - (x - n) + 1) / 2);
}
int main() {
  long long i, j, k;
  cin >> n;
  for (i = 9; i <= 999999999; i = i * 10 + 9)
    if (n + n - 1 < i) break;
  for (k = i / 10, i = 0; i < 9; i++)
    if ((long long)i * (k + 1) + k <= n + n - 1)
      ans += max((long long)0, cal((long long)i * (k + 1) + k));
    else
      return printf("%lld", ans), 0;
}
