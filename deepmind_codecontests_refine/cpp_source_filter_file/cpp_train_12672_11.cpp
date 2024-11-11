#include <bits/stdc++.h>
using namespace std;
const int MAX_P = 3200;
bool primes[MAX_P + 1];
int gen_primes(int maxp, vector<int> &pnums) {
  memset(primes, true, sizeof(primes));
  primes[0] = primes[1] = false;
  int p;
  for (p = 2; p * p <= maxp; p++)
    if (primes[p]) {
      pnums.push_back(p);
      for (int q = p * p; q <= maxp; q += p) primes[q] = false;
    }
  for (; p <= maxp; p++)
    if (primes[p]) pnums.push_back(p);
  return (int)pnums.size();
}
bool prime_decomp(int n, vector<int> &pnums, vector<int> &pds) {
  pds.clear();
  int pn = pnums.size();
  for (int i = 0; i < pn; i++) {
    int pi = pnums[i];
    if (pi * pi > n) {
      if (n > 1) pds.push_back(n);
      return true;
    }
    if (n % pi == 0) {
      int fi = 1;
      while (n % pi == 0) n /= pi, fi *= pi;
      pds.push_back(fi);
    }
  }
  return false;
}
int main() {
  int l, r, x, y;
  scanf("%d%d%d%d", &l, &r, &x, &y);
  if (x == y) {
    printf("%d\n", (l <= x && x <= r) ? 1 : 0);
    return 0;
  }
  if (y % x != 0) {
    puts("0");
    return 0;
  }
  vector<int> pnums;
  gen_primes(MAX_P, pnums);
  int z = y / x;
  vector<int> pds;
  prime_decomp(z, pnums, pds);
  int n = pds.size(), nbits = 1 << n;
  int cnt = 0;
  for (int bits = 0; bits < nbits; bits++) {
    int a = x;
    for (int i = 0, bi = 1; i < n; i++, bi <<= 1)
      if (bits & bi) a *= pds[i];
    int b = z / a * x;
    if (l <= a && a <= r && l <= b && b <= r) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
