#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0),
      cout.precision(15);
  long double n, r;
  long double ang = 2 * 3.14159265358979323846;
  while (cin >> n >> r) {
    long double intAng = ang / n;
    long double alpha = (3.14159265358979323846 - intAng * (n / 2)) / 2;
    long double beta = (3.14159265358979323846 - intAng) / 2 - alpha;
    long double tetha = (3.14159265358979323846 - beta * 2) / 2;
    long double ap =
        sqrt(r * r - pow(r * sin(3.14159265358979323846 / n), 2.0));
    long double areaPoligono = r * sin(3.14159265358979323846 / n) * n * ap;
    long double a2 = r * sin(3.14159265358979323846 / n) / tan(tetha);
    long double a3 = r * sin(3.14159265358979323846 / n) * a2;
    cout << fixed << setprecision(8) << areaPoligono - a3 * n << endl;
  }
  return 0;
}
