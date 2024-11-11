#include <bits/stdc++.h>
using namespace std;
const int N = 100050;
const int S = 32000;
vector<int> Prime;
bool sieve[S];
void FindPrimes() {
  int i, j;
  for (i = 2; i < S; i++) {
    if (!sieve[i]) {
      Prime.push_back(i);
      for (j = i; j < S; j += i) sieve[j] = 1;
    }
  }
}
int phi(int x) {
  int i, ret = 1;
  for (i = 0; i < Prime.size() && Prime[i] * Prime[i] <= x; i++) {
    if (x % Prime[i]) continue;
    ret *= Prime[i] - 1;
    x /= Prime[i];
    while (!(x % Prime[i])) ret *= Prime[i], x /= Prime[i];
  }
  if (x > 1) ret *= x - 1;
  return ret;
}
long long modulo(long long a, long long b) {
  if (a < b)
    return a;
  else
    return (a % b) + b;
}
long long pow(long long x, long long k, long long mod) {
  long long ret = 1;
  for (; k; k >>= 1, x = modulo(x * x, mod))
    if (k & 1) ret = modulo(ret * x, mod);
  return ret;
}
long long a[N];
vector<long long> mod;
long long Solve(int l, int r, int lvl) {
  if (lvl == mod.size() || l == r + 1) return 1;
  long long k = Solve(l + 1, r, lvl + 1);
  long long ret = pow(a[l], k, mod[lvl]);
  return ret;
}
int main() {
  FindPrimes();
  int n, m, i, l, r, q;
  scanf("%i %i", &n, &m);
  mod.push_back(m);
  while (mod.back() != 1) mod.push_back(phi(mod.back()));
  for (i = 1; i <= n; i++) scanf("%i", &a[i]);
  scanf("%i", &q);
  while (q--) {
    scanf("%i %i", &l, &r);
    printf("%lld\n", Solve(l, r, 0) % m);
  }
  return 0;
}
