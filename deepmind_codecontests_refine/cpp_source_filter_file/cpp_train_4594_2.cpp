#include <bits/stdc++.h>
using namespace std;
double dis(double x1, double y1, double x2, double y2) {
  return sqrt(abs(x1 - x2) * abs(x1 - x2) + abs(y1 - y2) * abs(y1 - y2));
}
int main() {
  double a, b, c;
  cin >> a >> b >> c;
  double x1, x2, y1, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (y1 < y2) swap(x1, x2), swap(y1, y2);
  double dis1 = abs(x1 - x2) + abs(y1 - y2);
  double py1 = ((-c - a * x1) / b);
  double py2 = ((-c - a * x2) / b);
  double px1 = ((-c - b * y1) / a);
  double px2 = ((-c - b * y2) / a);
  cout << fixed << setprecision(10);
  double dis2 = abs(y1 - ((-c - a * x1) / b)) + abs(y2 - ((-c - a * x2) / b)) +
                dis(x1, ((-c - a * x1) / b), x2, ((-c - a * x2) / b));
  double dis3 = abs(y1 - ((-c - a * x1) / b)) + abs(x2 - ((-c - b * y1) / a)) +
                dis(x1, ((-c - a * x1) / b), ((-c - b * y1) / a), y2);
  double dis4 = abs(x1 - ((-c - b * y1) / a)) + abs(x2 - ((-c - b * y2) / a)) +
                dis(((-c - b * y1) / a), y1, ((-c - b * y2) / a), y2);
  double dis5 = abs(x1 - ((-c - b * y1) / a)) + abs(y2 - ((-c - a * x2) / b)) +
                dis(((-c - b * y1) / a), y1, x2, ((-c - a * x2) / b));
  cout << min(dis1, min(dis2, min(dis3, min(dis5, dis4)))) << endl;
}
