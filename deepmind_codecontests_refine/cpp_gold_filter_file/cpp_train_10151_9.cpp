#include <bits/stdc++.h>
const long long CZece18 = 5 * 1000000000000000000LL;
int prime[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
using namespace std;
long long mini(long long a, long long b) {
  if (a < b) return a;
  return b;
}
long long maxi(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long cmmdc(long long a, long long b) {
  if (!b) return a;
  return cmmdc(b, a % b);
}
long long cmmmc(long long a, long long b) { return (a / cmmdc(a, b)) * b; }
long long next(long long val, long long crt) {
  long long k = (crt / val) * val + val;
  return k;
}
long double exista_cmm(long long a, long long b) {
  long double d = cmmdc(a, b);
  long long dd = d;
  for (int i = 0; i <= 12; ++i)
    while (dd % prime[i] == 0) {
      dd /= prime[i];
      a /= prime[i];
    }
  long double v1 = a, v2 = b;
  d = (v1 / d) * v2;
  if (d <= CZece18) return d;
  return 0;
}
long long x, y, N;
long long cm;
long long rez, smen;
long long step;
long long ultimul(long long crt) { return (N / crt) * crt; }
int main() {
  cin >> N >> x >> y;
  cm = cmmmc(x, y);
  step = mini(next(x, cm) - cm, next(y, cm) - cm);
  smen = min(N, maxi(0LL, mini(x - 1, y - 1)));
  rez = smen;
  if (exista_cmm(x, y) && cm <= N) {
    rez += (N / cm - 1) * step;
    rez += mini(step, N - ultimul(cm) + 1);
  }
  if (rez)
    cout << rez / cmmdc(rez, N) << "/" << N / cmmdc(rez, N);
  else
    cout << 0 << "/" << 1;
  return 0;
}
