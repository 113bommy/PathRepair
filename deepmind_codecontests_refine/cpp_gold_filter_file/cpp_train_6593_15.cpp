#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:214721677")
using namespace std;
template <class T>
T sqr(T a) {
  return (a) * (a);
}
template <class T>
T abs(T a) {
  return (a < 0) ? -(a) : (a);
}
const double Pi = acos(-1.0);
const double eps = 1e-10;
const int INF = 1000 * 1000 * 1000;
const double phi = 0.5 + sqrt(1.25);
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int main() {
  int n, m, k;
  string a, b;
  scanf("%d\n", &n);
  getline(cin, a);
  getline(cin, b);
  m = ((int)((a).size()));
  k = ((int)((b).size()));
  int len = gcd(m, k), lcm = m * k / len;
  string x = "", y = "";
  for (int i = 0, _n = (lcm / m) - 1; i <= _n; ++i) x += a;
  for (int i = 0, _n = (lcm / k) - 1; i <= _n; ++i) y += b;
  int countx = 0, county = 0;
  for (int i = 0, _n = (((int)((x).size()))) - 1; i <= _n; ++i) {
    countx += ((x[i] == 'S' && y[i] == 'P') || (x[i] == 'P' && y[i] == 'R') ||
               (x[i] == 'R' && y[i] == 'S'));
    county += ((y[i] == 'S' && x[i] == 'P') || (y[i] == 'P' && x[i] == 'R') ||
               (y[i] == 'R' && x[i] == 'S'));
  }
  int ansx = n / lcm * countx, ansy = n / lcm * county;
  n %= lcm;
  for (int i = 0; i < n; ++i) {
    ansx += ((x[i] == 'S' && y[i] == 'P') || (x[i] == 'P' && y[i] == 'R') ||
             (x[i] == 'R' && y[i] == 'S'));
    ansy += ((y[i] == 'S' && x[i] == 'P') || (y[i] == 'P' && x[i] == 'R') ||
             (y[i] == 'R' && x[i] == 'S'));
  }
  printf("%d %d\n", ansy, ansx);
  return 0;
}
