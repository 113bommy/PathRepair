#include <bits/stdc++.h>
using namespace std;
const long long w = 5;
const long long oo = 1e9 + 7;
struct PP {
  long long x, y;
  PP() {}
  PP(long long x, long long y) : x(x % oo), y(y % oo) {}
};
PP operator+(PP a, PP b) { return PP((a.x + b.x) % oo, (a.y + b.y) % oo); }
PP operator-(PP a, PP b) {
  return PP((a.x - b.x + oo) % oo, (a.y - b.y + oo) % oo);
}
PP operator*(PP a, PP b) {
  return PP((a.x * b.x % oo + a.y * b.y % oo * w % oo) % oo,
            (a.x * b.y % oo + a.y * b.x % oo) % oo);
}
void write(PP a) { cout << a.x << ' ' << a.y << endl; }
PP exp(PP a, long long b, long long p) {
  PP tmp = PP(1, 0);
  while (b) {
    if (b & 1) tmp = tmp * a;
    a = a * a;
    b = b >> 1;
  }
  return tmp;
}
PP inv(PP a) {
  PP r = exp(PP((a.x * a.x % oo - a.y * a.y % oo * w % oo + oo) % oo, 0),
             oo - 2, oo);
  return r * PP(a.x, oo - a.y);
}
PP frac[220], invf[220];
long long s[220][220];
int fibosum(long long n, int k) {
  PP inv_2 = inv(PP(2, 0));
  PP a = PP(1, 1) * inv_2;
  PP b = PP(1, oo - 1) * inv_2;
  PP ans = PP(0, 0);
  for (int j = 0; j <= k; j++) {
    PP t = exp(a, j, oo) * exp(b, k - j, oo);
    PP coe = frac[k] * invf[j] * invf[k - j];
    if ((k - j) % 2 == 1) coe = coe * PP(oo - 1, 0);
    if (t.x == 1 && t.y == 0)
      ans = ans + coe * PP(n, 0);
    else {
      PP a1 = exp(t, n, oo) - PP(1, 0);
      PP a2 = inv(t - PP(1, 0));
      ans = ans + coe * a1 * a2 * t;
    }
  }
  ans = ans * inv(exp(PP(0, 1), k, oo));
  return ans.x;
}
void init() {
  frac[0] = PP(1, 0);
  invf[0] = PP(1, 0);
  for (int i = 1; i <= 202; i++) {
    frac[i] = frac[i - 1] * PP(i, 0);
    invf[i] = inv(frac[i]);
  }
  for (int i = 1; i <= 202; i++) {
    s[i][0] = 0;
    for (int j = 1; j < i; j++)
      s[i][j] = ((oo - i + 1) % oo * s[i - 1][j] % oo + s[i - 1][j - 1]) % oo;
    s[i][i] = 1;
  }
}
long long l, r;
int k;
int main() {
  init();
  scanf("%d%I64d%I64d", &k, &l, &r);
  long long ans = 0;
  for (int j = 0; j <= k; j++) {
    long long tmp = (fibosum(r + 2, j) + oo - fibosum(l + 1, j)) % oo;
    (ans += s[k][j] * tmp % oo) %= oo;
  }
  ans = ans * invf[k].x % oo;
  printf("%d\n", ans);
  return 0;
}
