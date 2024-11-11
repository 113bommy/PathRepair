#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int main() {
  double d, h, v, e;
  cin >> d >> h >> v >> e;
  double V = (d / 2) * (d / 2) * PI * h;
  double growth = e * PI * (d / 2) * (d / 2);
  if (growth >= v)
    puts("NO");
  else
    printf("%.12lf\n", V / (v - growth));
}
