#include <bits/stdc++.h>
using namespace std;
unsigned long long n, m, k;
vector<long long> a(1e5 + 1);
int main() {
  unsigned int t;
  cin >> t;
  while (t--) {
    cin >> n;
    double f_2 = 0.5 * 3.14159265358979323846 / (double)n;
    double a;
    if (n % 2) {
      double f_3 = 1.57079632679489661923 -
                   ceil(0.5 * 0.78539816339744830962 / f_2) * 2.0 * f_2;
      a = 0.5 / sin(f_2);
      double d_2 = a * (sin(f_3) + cos(f_3));
      a = d_2 / sin(0.78539816339744830962);
    } else
      a = 1.0 / tan(f_2);
    printf("%.8lf\n", a);
  }
  return 0;
}
