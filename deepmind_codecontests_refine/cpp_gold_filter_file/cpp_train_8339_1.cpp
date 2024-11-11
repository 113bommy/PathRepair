#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x;
  scanf("%lld", &x);
  return x;
}
long long n, m, init[1000010], vis[1000010], a, b, c, d, numa, numb;
long long lowbit(long long x) { return x & -x; }
signed main() {
  a = read(), b = read();
  while ((c + 1) * c / 2 <= a + b) c++;
  c--;
  while ((1LL << d) <= c) d++;
  d--;
  for (long long i = 0; (1 << i) <= c; ++i) init[1 << i] = 1;
  for (long long i = c; i >= 1; --i) {
    if (init[i]) continue;
    if (a >= i) a -= i, vis[i] = 1, numa++;
  }
  for (long long i = d; i >= 0; --i)
    if (a >= (1LL << i)) a -= (1LL << i), vis[1LL << i] = 1, numa++;
  printf("%lld\n", numa);
  for (long long i = 1; i <= c; ++i)
    if (vis[i]) printf("%lld ", i);
  cout << endl;
  printf("%lld\n", c - numa);
  for (long long i = 1; i <= c; ++i)
    if (!vis[i]) printf("%lld ", i);
  cout << endl;
}
