#include <bits/stdc++.h>
using namespace std;
long long modular_power(long long x, long long y, long long m) {
  long long r = 1;
  while (y) {
    if (y & 0x1) r = r * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return r;
}
long long invert(long long x, long long m) {
  return modular_power(x, m - 2, m);
}
const int R = 1000000009;
const int N = 100010;
int n;
int a[N];
long long fac[N], rfac[N], p2[N];
void init_comb() {
  fac[0] = rfac[0] = p2[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = fac[i - 1] * i % R;
    rfac[i] = invert(fac[i], R);
    if (fac[i] * rfac[i] % R != 1) puts("ooops");
    p2[i] = (p2[i - 1] << 1) % R;
  }
}
long long c(int n, int k) { return fac[n] * rfac[k] % R * rfac[n - k] % R; }
int solve(int l, int r, int fl, int fr) {
  int m = r - l + 1;
  if (fl < l) fl = l;
  if (r < fr) fr = r;
  while (fl < n && a[fl] < 0) fl++;
  while (fr >= 0 && a[fr] < 0) fr--;
  if (l > r) return 1;
  if (fl > fr) return p2[m - 1];
  long long ans = 0;
  if (a[fl] >= a[fr]) {
    int k = m - 1 - a[fl];
    int d1 = fl - l;
    int d2 = k - d1;
    if (k >= 0 && d1 <= k) {
      ans = (ans + c(k, d1) * solve(l + d1 + 1, r - d2, fl, fr)) % R;
    }
  }
  if (a[fl] < a[fr] || a[fl] == a[fr] && a[fl] > 0) {
    int k = m - 1 - a[fr];
    int d1 = r - fr;
    int d2 = k - d1;
    if (k >= 0 && d1 <= k) {
      ans = (ans + c(k, d1) * solve(l + d2, r - d1 - 1, fl, fr)) % R;
    }
  }
  return ans;
}
int main() {
  init_comb();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    a[i]--;
  }
  printf("%d\n", solve(0, n - 1, 0, n - 1));
  return 0;
}
