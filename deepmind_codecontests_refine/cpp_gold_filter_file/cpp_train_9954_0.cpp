#include <bits/stdc++.h>
using namespace std;
long long q;
long long f[1000500], ni[1000500];
long long ci[1000500];
long long pri[101], cnt;
long long edans[1000500];
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= (a / b) * x;
}
long long quickpow(long long x, long long t, long long p) {
  long long ans = 1;
  for (; t; t >>= 1, x = (x * x) % p)
    if (t & 1) ans = (ans * x) % p;
  return ans;
}
long long n1, m1, a;
long long s, frog;
long long work() {
  long long sum = a, now = 1;
  while (sum != 1) {
    sum = sum * a % q;
    now++;
  }
  return now;
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n1, &m1, &a, &q);
  frog = work();
  f[0] = 1;
  for (int i = 1; i <= frog; i++) f[i] = f[i - 1] * i % frog;
  ni[frog - 1] = frog - 1;
  for (int i = frog - 2; i >= 0; i--) ni[i] = ni[i + 1] * (i + 1) % frog;
  int sum = 1, nsum = 0;
  ;
  for (int i = 0; i <= (n1 - 1 < m1 ? n1 - 1 : m1); i++) {
    sum = f[m1] % frog * ni[i] % frog * ni[m1 - i] % frog;
    nsum = (nsum + sum) % frog;
    ci[n1 - i] = quickpow(a, nsum, q);
  }
  for (int i = n1 - m1 - 1; i > 0; i--) ci[i] = ci[i + 1];
  for (int i = 1; i <= n1; i++) printf("%I64d ", ci[i]);
}
