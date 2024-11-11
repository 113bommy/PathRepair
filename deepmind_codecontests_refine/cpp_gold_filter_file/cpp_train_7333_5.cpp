#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long fac[100100];
long long cnt, step;
int first;
void dfs(long long n, long long k) {
  if (step >= 1e5) return;
  if (k == 0 || n == 1) {
    step++;
    if (first) {
      printf("%lld", n);
      first = 0;
    } else
      printf(" %lld", n);
    return;
  }
  for (long long i = 0; i < cnt; i++) {
    if (n % fac[i] == 0) dfs(fac[i], k - 1);
    if (n < fac[i]) break;
  }
  return;
}
int main() {
  long long n, k;
  while (~scanf("%lld%lld", &n, &k)) {
    cnt = step = 0;
    first = 1;
    for (long long i = 1; i * i <= n; i++)
      if (n % i == 0) {
        fac[cnt++] = i;
        if (i * i != n) fac[cnt++] = n / i;
      }
    sort(fac, fac + cnt);
    dfs(n, k);
    puts("");
  }
  return 0;
}
