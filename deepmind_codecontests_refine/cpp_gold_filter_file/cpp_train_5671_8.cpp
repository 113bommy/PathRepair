#include <bits/stdc++.h>
using namespace std;
int const N = 1002000;
int n, m;
int dx, dy;
int phi;
int a[N];
int gcd(int a, int b) {
  while (b != 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int modpow(int a, int b, int mod) {
  int ret = 1;
  while (b > 0) {
    if ((b & 1) == 1) {
      ret = 1LL * ret * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return ret;
}
int moddiv(int a, int b, int mod) {
  return 1LL * a * modpow(b, phi - 1, mod) % mod;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &dx, &dy);
  for (int i = 1; i <= n; ++i) {
    if (gcd(i, n) == 1) {
      ++phi;
    }
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int cnt = moddiv(x, dx, n);
    int t = (1LL * n * n + y - 1LL * cnt * dy) % n;
    ++a[t];
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[ans] < a[i]) {
      ans = i;
    }
  }
  printf("0 %d\n", ans);
  return 0;
}
