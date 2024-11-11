#include <bits/stdc++.h>
const long long m = 1e9 + 7;
long long n, fak[3000000];
long long zamena;
long long brzo_st(long long a, long long x) {
  if (x == 1) return a;
  if (x % 2)
    return (a * brzo_st((a * a) % m, x / 2)) % m;
  else
    return brzo_st((a * a) % m, x / 2) % m;
}
long long komb(long long n, long long k) {
  return (((fak[n] * zamena) % m) * brzo_st(fak[n - k], m - 2)) % m;
}
int main() {
  scanf("%lld", &n);
  fak[1] = 1;
  for (long long i = 2; i <= 2 * n + 2; i++) fak[i] = (fak[i - 1] * i) % m;
  long long ans = komb(n + 1, n);
  zamena = brzo_st(fak[n], m - 2);
  for (long long i = 1; i <= n; i++) ans = (ans + komb(n + 1 + i, n)) % m;
  printf("%lld", ans);
  return 0;
}
