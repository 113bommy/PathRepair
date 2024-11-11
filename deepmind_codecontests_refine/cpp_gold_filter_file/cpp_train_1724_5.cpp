#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int mo = 1e9 + 7;
int k;
long long l, r;
long long js[N], inv[N];
long long c[N];
struct comp {
  long long x, y;
  comp(const long long x_ = 0, const long long y_ = 0) {
    x = x_;
    y = y_;
  }
} a0, a1;
long long add(long long x, long long y) {
  return x + y >= mo ? x + y - mo : x + y;
}
long long dec(long long x, long long y) { return x < y ? x - y + mo : x - y; }
comp operator+(comp a, comp b) { return comp(add(a.x, b.x), add(a.y, b.y)); }
comp operator-(comp a, comp b) { return comp(dec(a.x, b.x), dec(a.y, b.y)); }
comp operator*(comp a, comp b) {
  return comp((a.x * b.x % mo + a.y * b.y % mo * 5) % mo,
              (a.x * b.y % mo + a.y * b.x % mo) % mo);
}
long long quickmi(long long x, long long tim) {
  long long ret = 1;
  for (; tim; tim /= 2, x = x * x % mo)
    if (tim & 1) ret = ret * x % mo;
  return ret;
}
comp quickmi(comp x, long long tim) {
  comp ret = comp(1, 0);
  for (; tim; tim /= 2, x = x * x)
    if (tim & 1) ret = ret * x;
  return ret;
}
comp getinv(comp a) {
  long long tmp = (a.x * a.x % mo + mo - a.y * a.y % mo * 5 % mo) % mo;
  tmp = quickmi(tmp, mo - 2);
  return comp(a.x * tmp % mo, dec(0, a.y * tmp % mo));
}
long long calc(int n, int m) { return js[n] * inv[m] % mo * inv[n - m] % mo; }
long long solve(long long n) {
  comp ret = comp(0, 0);
  comp inv5 = comp(0, quickmi(5, mo - 2));
  for (int i = 0; i <= k; i++)
    if (c[i]) {
      comp sum = comp(0, 0);
      for (int j = 0; j <= i; j++) {
        int tim = i - j * 2;
        long long cv = calc(i, j);
        if (tim > 0) {
          comp u = quickmi(comp(mo - 1, 0), j) * quickmi(a0, tim);
          comp v = quickmi(u, n + 1) - comp(1, 0);
          u = u - comp(1, 0);
          sum = sum + v * getinv(u) * comp(cv, 0) * quickmi(comp(mo - 1, 0), j);
        }
        if (tim == 0) {
          if (j & 1)
            sum = sum + comp(n & 1 ? 0 : mo - 1, 0) * comp(cv, 0);
          else
            sum = sum + comp((n + 1) % mo, 0) * comp(cv, 0);
        }
        if (tim < 0) {
          comp u = quickmi(comp(mo - 1, 0), j) * quickmi(a1, -tim);
          comp v = quickmi(u, n + 1) - comp(1, 0);
          u = u - comp(1, 0);
          sum = sum + v * getinv(u) * comp(cv, 0) * quickmi(comp(mo - 1, 0), j);
        }
      }
      sum = sum * quickmi(inv5, i) * comp(c[i], 0);
      ret = ret + sum;
    }
  return ret.x;
}
int main() {
  scanf("%d%I64d%I64d", &k, &l, &r);
  a0 = comp((mo + 1) / 2, (mo + 1) / 2);
  a1 = getinv(a0);
  js[0] = 1;
  for (int i = 1; i <= k; i++) js[i] = js[i - 1] * i % mo;
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= k; i++) inv[i] = 1ll * (mo - mo / i) * inv[mo % i] % mo;
  for (int i = 2; i <= k; i++) inv[i] = inv[i] * inv[i - 1] % mo;
  c[0] = 1;
  for (int i = 0; i <= k - 1; i++) {
    long long v = (mo - i) % mo;
    for (int j = k; j >= 1; j--) c[j] = (c[j] * v + c[j - 1]) % mo;
    c[0] = c[0] * v % mo;
  }
  printf("%I64d\n", (solve(r + 2) + mo - solve(l + 1)) % mo * inv[k] % mo);
  return 0;
}
