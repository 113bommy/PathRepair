#include <bits/stdc++.h>
#pragma GCC diagnostic ignored "-Wunused-result"
using namespace std;
long long n, m;
const long long bm = 101 * 1000;
long long valeurs[bm];
bool connu[bm];
long long ask(long long x) {
  x %= n;
  ++x;
  if (connu[x]) return valeurs[x];
  printf("? %lld\n", x);
  fflush(stdout);
  long long res;
  scanf("%lld", &res);
  connu[x] = true;
  valeurs[x] = res;
  return res;
}
long long solve(long long a, long long b) {
  long long md = (a + b) / 2;
  long long dlt = ask(md) - ask(md + m);
  if (dlt > 0)
    return solve(md + 1, b);
  else if (dlt < 0)
    return solve(a, md - 1);
  else
    return (md % n) + 1;
}
signed main() {
  scanf("%lld", &n);
  m = n / 2;
  long long d0 = ask(0) - ask(0 + m), dM = ask(m) - ask(m + m);
  long long rr;
  if (abs(d0) % 2 == 1)
    rr = -1;
  else if (d0 == 0)
    rr = 0 + 1;
  else if (dM == 0)
    rr = m + 1;
  else if (d0 > 0 && dM < 0)
    rr = solve(0, m);
  else
    rr = solve(m, n);
  printf("! %lld\n", rr);
  fflush(stdout);
  return 0;
}
