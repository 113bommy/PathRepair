#include <bits/stdc++.h>
using namespace std;
int n, l, r, num, p;
int m, w[100010], phi[300];
int count_phi(int p) {
  int l = 1, i = 2;
  if (p == 1) return 0;
  while (p != 1) {
    while (p % i != 0) i++;
    l *= (i - 1);
    p /= i;
    while (p % i == 0) {
      p /= i;
      l *= i;
    }
  }
  return l;
}
int mpow(int a, int n, int mod) {
  if (n == 0) return 1;
  int b = mpow(a, n / 2, mod);
  b = (1LL * b * b) % mod;
  if (n % 2 == 1) b = (1LL * a * b) % mod;
  return b;
}
int com(int a, int b, int c) {
  long long d = 1;
  if ((a == 1) && (c > 1)) return 1;
  for (int i = 1; i <= b; i++) {
    if (d >= c / a) return 0;
    d = d * a;
  }
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
  phi[0] = m;
  while (phi[num++] != 0) phi[num] = count_phi(phi[num - 1]);
  num -= 2;
  scanf("%d", &p);
  for (int i = 0; i < p; i++) {
    scanf("%d %d", &l, &r);
    int k = 1;
    for (int i = min(r, l + num); i >= l; i--) {
      if (com(w[i], k, phi[i - l]))
        k = mpow(w[i], k, phi[i - l]);
      else
        k = mpow(w[i], k, phi[i - l]) + phi[i - l];
    }
    printf("%d\n", k % m);
  }
}
