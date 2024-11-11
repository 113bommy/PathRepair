#include <bits/stdc++.h>
using namespace std;
int main() {
  double PI = acos(-1);
  double n, r, d, star;
  cin >> n >> r;
  d = 2 * n - 3;
  star = n * r * r * sin(PI / n) * sin(PI / (2 * n)) / sin((d * PI) / (2 * n));
  cout << setprecision(20) << fixed << abs(star) << endl;
}
