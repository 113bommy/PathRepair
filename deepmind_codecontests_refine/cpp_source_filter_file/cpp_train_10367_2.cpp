#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int f, w, h;
const int MAXFACT = 300000;
long long fact[MAXFACT];
long long rfact[MAXFACT];
long long rev[MAXFACT];
long long cnk(long long n, long long k) {
  return fact[n] * rfact[k] % MOD * rfact[n - k] % MOD;
}
long long spread(long long n, long long k) {
  if (n == 0) return 1;
  return cnk(n + k - 1, k - 1);
}
long long get_total(long long food_stacks, long long water_stacks, long long f,
                    long long w) {
  if (food_stacks <= 0 || food_stacks > f) return 0;
  f -= food_stacks;
  w -= water_stacks;
  if (f < 0) return 0;
  if (w < 0) return 0;
  return spread(w, water_stacks) * spread(f, food_stacks) % MOD;
}
long long solve(long long food_stacks, long long water_stacks) {
  if (food_stacks <= 0 || food_stacks > f) return 0;
  return get_total(food_stacks, water_stacks, f, w - water_stacks * h);
}
long long qpowmod(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
long long revmod(long long a, long long mod) {
  return qpowmod(a, mod - 2, mod);
}
int main() {
  rev[1] = 1;
  for (int i = 2; i < MAXFACT; i++)
    rev[i] = (MOD - MOD / i * rev[MOD % i] % MOD) % MOD;
  fact[0] = 1;
  rfact[0] = 1;
  for (int i = 1; i < MAXFACT; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    rfact[i] = rfact[i - 1] * rev[i] % MOD;
  }
  scanf("%d%d%d", &f, &w, &h);
  if (f == 0) {
    puts("1");
    return 0;
  } else if (w == 0) {
    if (f > h)
      puts("1");
    else
      puts("0");
    return 0;
  }
  long long res = 0;
  long long total = 0;
  for (int wst = 1; wst <= w; wst++) {
    res = (res + solve(wst - 1, wst)) % MOD;
    res = (res + 2 * solve(wst, wst)) % MOD;
    res = (res + solve(wst + 1, wst)) % MOD;
    total = (total + get_total(wst - 1, wst, f, w)) % MOD;
    total = (total + 2 * get_total(wst, wst, f, w)) % MOD;
    total = (total + get_total(wst + 1, wst, f, w)) % MOD;
  }
  cerr << res << endl;
  cerr << total << endl;
  printf("%lld\n", res * revmod(total, MOD) % MOD);
  return 0;
}
