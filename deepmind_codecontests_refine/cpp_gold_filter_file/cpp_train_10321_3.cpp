#include <bits/stdc++.h>
using namespace std;
int check(int m) {
  printf("> %d\n", m);
  fflush(stdout);
  int r;
  scanf("%d", &r);
  return r;
}
int gcd(int a, int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int brand() {
  int res = 0;
  for (int i = 0; i < 5; ++i) res = (res << 5) | (rand() & 31);
  return res;
}
int main() {
  srand(time(0));
  int n;
  scanf("%d", &n);
  bool* u = new bool[n];
  for (int i = 0; i < n; ++i) u[i] = false;
  int l = 0, r = 1e9, m;
  while (r - l > 1) {
    m = (l + r) / 2;
    if (check(m))
      l = m;
    else
      r = m;
  }
  int xn = l + 1;
  int d = 0;
  for (int it = 0; it < min(n, 25);) {
    int i = brand() % n;
    if (u[i]) continue;
    u[i] = true;
    ++it;
    printf("? %d\n", i + 1);
    fflush(stdout);
    int ai;
    scanf("%d", &ai);
    d = gcd(xn - ai, d);
  }
  printf("! %d %d\n", xn - (n - 1) * d, d);
  fflush(stdout);
}
