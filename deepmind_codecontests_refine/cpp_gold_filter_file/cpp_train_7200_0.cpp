#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long INF = (long long)2e18;
const int B = 6;
long long mult(long long x, long long y, long long md) {
  if (y == 0) return 0;
  return (mult((x * B) % md, y / B, md) + (x * (y % B))) % md;
}
long long bin_pow(long long x, long long p, long long md) {
  if (p == 0) return 1 % md;
  if (p & 1) return mult(x, bin_pow(x, p - 1, md), md);
  return bin_pow(mult(x, x, md), p / 2, md);
}
const int CC = (int)5e6;
bool used[CC + 1];
long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }
long long F(long long x, long long m) {
  x = mult(x, x, m);
  x++;
  if (x == m) x -= m;
  return x;
}
vector<long long> findDivs(long long m) {
  vector<long long> ans;
  for (long long x = 2; x < CC; x++) {
    if (m % x) continue;
    ans.push_back(x);
    while (m % x == 0) m /= x;
  }
  if (m == 1) return ans;
  if (m < (long long)(CC - 2) * (CC - 2)) {
    ans.push_back(m);
    return ans;
  }
  for (int it = 0; it < 5; it++) {
    long long x = rng() % 100 + 1;
    long long y = x;
    for (int it2 = 0; it2 < 100000; it2++) {
      x = F(x, m);
      y = F(y, m);
      y = F(y, m);
      long long d = gcd(abs(x - y), m);
      if (d != 1 && d != m) {
        ans.push_back(d);
        ans.push_back(m / d);
        return ans;
      }
    }
  }
  ans.push_back(m);
  return ans;
}
long long getOrder(long long g, long long m, long long phi,
                   vector<long long> divs) {
  for (long long x : divs) {
    long long z = bin_pow(g, phi / x, m);
    if (z == 1) return x;
  }
  return 1;
}
long long myPow(long long x, long long p) {
  long long res = 1;
  while (p--) {
    if ((double)res * x > INF) return INF;
    res *= x;
  }
  return min(res, INF);
}
int main() {
  int n;
  long long m, w;
  scanf("%d%lld%lld", &n, &m, &w);
  long long p = m;
  int t = 1;
  for (int k = 2; k < 60; k++) {
    long long z = (long long)(powl(m, 1. / k));
    if (z > 1) z--;
    z = max(z, 1LL);
    while (myPow(z, k) > m) z--;
    while (myPow(z, k) < m) z++;
    if (myPow(z, k) == m) {
      p = z;
      t = k;
    }
  }
  if (m < CC) {
    for (int i = 0; i < m; i++) {
      used[i] = 0;
    }
    long long x = 1;
    while (true) {
      if (used[x]) break;
      used[x] = 1;
      x = (x * w) % m;
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
      if (!used[i] && (i % p != 0)) {
        res++;
      }
    }
    if (res < n) {
      printf("-1\n");
      return 0;
    }
    for (int i = 0; n > 0 && i < m; i++) {
      if (!used[i] && (i % p != 0)) {
        printf("%d ", i);
        n--;
      }
    }
    printf("\n");
    return 0;
  }
  if (w % p == 0) {
    long long res = (m / p) * (p - 1) - 1;
    if (res < n) {
      printf("-1\n");
      return 0;
    }
    for (long long x = 2; n > 0; x++) {
      if (x % p == 0) continue;
      printf("%lld ", x);
      n--;
    }
    printf("\n");
    return 0;
  }
  if (p == 2) {
    int x = 3;
    while (w % 8 == x) x += 2;
    for (int i = 0; i < n; i++) printf("%d ", 8 * i + x);
    printf("\n");
    return 0;
  }
  long long phi = (m / p) * (p - 1);
  vector<long long> divs = findDivs(p - 1);
  if (t > 1) divs.push_back(p);
  long long ord = getOrder(w, m, phi, divs);
  if (ord == 1) {
    printf("-1\n");
    return 0;
  }
  long long g = 0;
  while (true) {
    if (g % p == 0 || getOrder(g, m, phi, divs) != 1) {
      g = rng() % m;
    } else
      break;
  }
  long long x = 1;
  for (int i = 1; n > 0; i++) {
    x = mult(x, g, m);
    if (i % ord != 0) {
      printf("%lld ", x);
      n--;
    }
  }
  printf("\n");
  return 0;
}
