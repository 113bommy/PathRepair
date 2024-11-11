#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long getans(long long n) {
  if (n == 1) return 3 % m;
  long long k = getans(n / 2);
  k *= k;
  if (n % 2) k *= 3;
  return k % m;
}
int main() {
  while (~scanf("%I64d%I64d", &n, &m)) {
    long long ans = getans(n) - 1;
    if (ans == -1) ans = m - 1;
    printf("%I64d\n", ans);
  }
  return 0;
}
