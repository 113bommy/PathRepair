#include <bits/stdc++.h>
using namespace std;
const int MAX = 20;
int n, l, r;
double f[1 << MAX];
double first[MAX], second[MAX], a[MAX];
double get(double l, double first, double second, double a) {
  a = a * M_PI / 180;
  double ang = atan2(second, l - first);
  ang -= a;
  if (ang > 1e-9) return first + second / tan(ang);
  return r;
}
int main() {
  int i, j;
  cin >> n >> l >> r;
  for ((i) = (0); (i) != (n); ++(i)) cin >> first[i] >> second[i] >> a[i];
  for ((i) = (0); (i) != ((1 << n) - 1); ++(i)) f[i] = l;
  f[0] = l;
  for ((i) = (0); (i) != ((1 << n) - 1); ++(i))
    for ((j) = (0); (j) != (n); ++(j))
      if (!(i & (1 << j)))
        f[i | (1 << j)] =
            max(f[i | (1 << j)], get(f[i], first[j], second[j], a[j]));
  printf("%.6f\n", min(f[(1 << n) - 1], (double)r) - l);
  return 0;
}
