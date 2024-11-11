#include <bits/stdc++.h>
using namespace std;
long int n, s;
long long int x, y, nr;
struct contestant {
  long int s, a, b;
} c[100005], aux;
void citire() {
  long int i;
  long long int sum = 0;
  cin >> n >> s;
  for (i = 1; i <= n; i++) {
    cin >> c[i].s >> c[i].a >> c[i].b;
    sum += c[i].s;
  }
  nr = sum / s;
  if (sum % s != 0) nr++;
  n++;
  c[i].a = c[i].b = 0;
  c[i].s = nr * s - sum;
}
void sortare() {
  long int i, j, gap;
  for (gap = n / 2; gap >= 1; gap /= 2)
    for (i = 1 + gap; i <= n; i++) {
      aux = c[i];
      for (j = i - gap; (j >= 1) && (((c[j].a - c[j].b) < (aux.a - aux.b)) ||
                                     (((c[j].a - c[j].b) == (aux.a - aux.b)) &&
                                      (c[j].a < aux.a)));
           j -= gap)
        c[j + gap] = c[j];
      c[j + gap] = aux;
    }
}
long long int minim(long long int a, long long int b) {
  return (a < b ? a : b);
}
void solve() {
  long int i, j;
  long long int happy = 0, nrfel, felii1, felii2, diff1, diff2;
  for (i = 1; i <= n; i++) happy += c[i].s * c[i].b;
  i = 1;
  nrfel = 0;
  while (i <= n && c[i].a > c[i].b) {
    happy += c[i].s * (c[i].a - c[i].b);
    nrfel += c[i].s;
    i++;
  }
  felii1 = nrfel % s;
  if (felii1) {
    felii2 = s - felii1;
    j = i - 1;
    diff1 = 0;
    while (felii1 > 0) {
      if (felii1 > c[j].s) {
        diff1 += c[j].s * (c[j].a - c[j].b);
        felii1 -= c[j].s;
        j--;
      } else {
        diff1 += felii1 * (c[j].a - c[j].b);
        felii1 = 0;
      }
    }
    diff2 = 0;
    while (felii2 > 0) {
      if (felii2 > c[i].s) {
        diff2 += c[i].s * (c[i].b - c[i].a);
        felii2 -= c[i].s;
        i++;
      } else {
        diff2 += felii2 * (c[i].b - c[i].a);
        felii2 = 0;
      }
    }
    if (diff1 > diff2)
      happy -= diff2;
    else
      happy -= diff1;
  }
  cout << happy;
}
int main() {
  ios::sync_with_stdio(false);
  citire();
  sortare();
  solve();
  return 0;
}
