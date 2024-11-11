#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long n, Zcnt, Fcnt, Ztot, Ftot;
long long a[maxn], judone[maxn];
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
  }
  for (long long i = 1; i <= n; i++) {
    if (a[i] <= i) {
      Fcnt++;
      Ftot += (i - a[i]);
    } else {
      judone[a[i] - i]++;
      Zcnt++;
      Ztot += (a[i] - i);
    }
  }
  long long ans = Ztot + Ftot, jl = 0;
  for (long long i = 1; i < n; i++) {
    Ztot -= Zcnt;
    Zcnt -= judone[i];
    Ftot += Fcnt;
    Fcnt += judone[i];
    long long x = a[n - i + 1];
    Ftot -= n + 1 - x, --Fcnt;
    if (x > 1)
      ++judone[x - 1 + i], Ztot += x - 1, ++Zcnt;
    else
      ++Fcnt;
    if (ans > Ftot + Ztot) ans = Ftot + Ztot, jl = i;
  }
  printf("%lld %lld\n", ans, jl);
  return 0;
}
