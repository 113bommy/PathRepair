#include <bits/stdc++.h>
using namespace std;
const long long K = 60;
double oblicz(double y) {
  double pocz = y - 10.0, kon = y + 10.0;
  for (int q = 0; q < (K); q++) {
    double srod = (pocz + kon) / 2;
    if (srod > y + sin(srod))
      kon = srod;
    else
      pocz = srod;
  }
  return (pocz + kon) / 2;
}
double rozwiaz(double c) {
  return min(oblicz(M_PI + c / 2) - oblicz(M_PI - c / 2), 2 * oblicz(c / 2));
}
void zrob_test() {
  int n, r, v;
  cin >> n >> r >> v;
  double czynnik = double(r) / double(v);
  while (n--) {
    int s, f;
    cin >> s >> f;
    cout << rozwiaz(double(f - s) / double(r)) * czynnik << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.setf(ios::fixed);
  cout.precision(9);
  zrob_test();
  return 0;
}
