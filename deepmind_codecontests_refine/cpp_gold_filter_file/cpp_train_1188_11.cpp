#include <bits/stdc++.h>
using namespace std;
long long modular(long long a, long long b) { return (a % b + b) % b; }
long long exgcd(long long m, long long n, long long &a, long long &b) {
  if (!n) return a = 1, b = 0, m;
  long long d = exgcd(n, m % n, b, a);
  b -= m / n * a;
  return d;
}
long long invert(long long x, long long m) {
  long long a, b;
  exgcd(x, m, a, b);
  return modular(a, m);
}
const int R = 1000000007;
const int N = 100010;
int n;
int a[N];
bool asc[N], desc[N];
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
void init_asc_desc() {
  int pv = n;
  desc[0] = true;
  for (int i = 1; i <= n; i++) {
    desc[i] = desc[i - 1];
    if (a[i - 1] >= 0) {
      desc[i] &= a[i - 1] < pv;
      pv = a[i - 1];
    }
  }
  pv = n;
  asc[n] = true;
  for (int i = n - 1; i >= 0; i--) {
    asc[i] = asc[i + 1];
    if (a[i] >= 0) {
      asc[i] &= a[i] < pv;
      pv = a[i];
    }
  }
}
int solve(int p) {
  long long ans = 1;
  bool flag = a[p] < 0;
  auto out = [&](int m, int k) {
    if (flag) {
      flag = 0;
      ans = ans * p2[m] % R;
    } else {
      ans = ans * c(m, k) % R;
    }
  };
  int s = 1;
  int l = p - 1, r = p + 1;
  int fl = l, fr = r;
  while (l >= 0 || r < n) {
    while (fl >= 0 && a[fl] < 0) fl--;
    while (fr < n && a[fr] < 0) fr++;
    int lx = fl >= 0 ? a[fl] : n;
    int rx = fr < n ? a[fr] : n;
    if (lx < rx) {
      int m = lx - s;
      int k = l - fl;
      if (m < k) return 0;
      out(m, k);
      l -= k + 1;
      if (l < fl) fl = l;
      r += m - k;
      if (r > fr) return 0;
      s = lx + 1;
    } else if (lx > rx) {
      int m = rx - s;
      int k = fr - r;
      if (m < k) return 0;
      out(m, k);
      r += k + 1;
      if (fr < r) fr = r;
      l -= m - k;
      if (l < fl) return 0;
      s = rx + 1;
    } else {
      if (lx != n) puts("oops");
      int m = rx - s;
      int k = fr - r;
      if (m < k) return 0;
      out(m, k);
      break;
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
  init_asc_desc();
  int ans = 0;
  int p = find(a, a + n, 0) - a;
  if (p != n) {
    ans = solve(p);
  } else {
    p = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] >= 0 && (p == -1 || a[i] < a[p])) p = i;
    }
    if (p == -1) {
      ans = p2[n - 1];
    } else {
      for (int i = 0; i < n; i++) {
        if (asc[i] && desc[i + 1] && abs(i - p) == 1 && a[i] < 0) {
          ans += solve(i);
          ans %= R;
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
