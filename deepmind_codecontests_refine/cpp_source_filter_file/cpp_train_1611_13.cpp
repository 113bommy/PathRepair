#include <bits/stdc++.h>
using namespace std;
long long A, B, C, tot;
void calc(long long a, long long b, long long c, long long d, long long dep) {
  assert(dep <= 70);
  if ((!b && d) || (b && !d)) return;
  if (!b && !d) {
    tot++;
    return;
  }
  long long a0 = d % c;
  if (b - a0 >= 0 && (b - a0) % a == 0 && d - a0 >= 0 && (d - a0) % c == 0)
    calc(a, (b - a0) / a, c, (d - a0) / c, dep + 1);
  if (a0 == 0) {
    if (b == d)
      calc(a, 0, c, 0, dep + 1);
    else
      return;
  }
}
void solve() {
  scanf("%lld%lld%lld", &A, &B, &C);
  tot = 0;
  if (A == 1 && B == 1 && C == 1) {
    puts("-1");
    return;
  }
  if (A == 1 && B == 1 && C > 1) {
    puts("0");
    return;
  }
  calc(A, B, B, C, 0);
  printf("%lld", tot);
}
signed main() { solve(); }
