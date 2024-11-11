#include <bits/stdc++.h>
using namespace std;
long long int h, m, lenh, lenm, cerosh, cerosm, k;
long long int valor(int ceros) {
  long long int fac = 1;
  for (int i = 1; i <= ceros; i++) {
    if (i < lenm)
      fac *= 10;
    else if (i == lenm)
      fac = m;
    else if (i < lenm + lenh)
      fac *= 10;
    else
      fac = h * m;
  }
  return fac;
}
long long int diezala(int ceros) {
  long long int r = 1;
  for (int i = 0; i < ceros; i++) r *= 10;
  return r;
}
long long int cambios(long long int t) {
  if (k > lenm) {
    long long int kk = k + cerosm;
    if (kk > lenm + lenh) return 0;
    if (kk == lenm + lenh) {
      if (t < h * m) return t / valor(kk - 1);
      if (cerosh == 0) return (t - 1) / valor(kk - 1) + 1;
      return (t - 1) / valor(kk - 1);
    }
    if (t < h * m) return t / valor(kk - 1);
    if (lenm + lenh - cerosm - cerosh >= k) return (t - 1) / valor(kk - 1) + 1;
    return (t - 1) / valor(kk - 1);
  }
  if (lenm - cerosm >= k)
    return t / m * (1 + (m - 1) / valor(k - 1)) + t % m / valor(k - 1);
  long long int cambiosfaltan = k - (lenm - cerosm);
  if (t < h * m)
    return t / m * ((m - 1) / valor(k - 1)) +
           t / m / diezala(cambiosfaltan - 1) + t % m / valor(k - 1);
  if (lenm + lenh - cerosm - cerosh >= k)
    return (t - 1) / m * ((m - 1) / valor(k - 1)) +
           (t - 1) / m / diezala(cambiosfaltan - 1) +
           (t - 1) % m / valor(k - 1) + 1;
  return (t - 1) / m * ((m - 1) / valor(k - 1)) +
         (t - 1) / m / diezala(cambiosfaltan - 1) + (t - 1) % m / valor(k - 1);
}
int main() {
  cin >> h >> m >> k;
  long long int mm = m;
  lenm = 1;
  cerosm = 0;
  while (mm >= 10) {
    if (mm % 10 == 0) cerosm++;
    lenm++;
    mm /= 10;
  }
  long long int hh = h;
  lenh = 1;
  cerosh = 0;
  while (hh >= 10) {
    if (hh % 10 == 0) cerosh++;
    lenh++;
    hh /= 10;
  }
  long long int h1, m1, h2, m2;
  cin >> h1 >> m1 >> h2 >> m2;
  if (k > lenm + lenh) {
    cout << 0 << endl;
    exit(0);
  }
  long long int t1 = h1 * m + m1;
  long long int t2 = h2 * m + m2;
  long long int c1 = cambios(t1);
  long long int c2 = cambios(t2);
  long long int r;
  if (t2 >= t1)
    r = c2 - c1;
  else
    r = c2 + cambios(h * m) - c1;
  cout << r << endl;
}
