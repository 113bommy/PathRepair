#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 33;
const double eps = 0.00000000001;
struct point {
  double x, y, z;
  point() {}
  point(double x, double y, double z) : x(x), y(y), z(z) {}
};
double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
point arr[MAX];
double dist[MAX];
int main() {
  int n, vBall, vHarry, X, Y, Z;
  cin >> n;
  for (int i = 0; i < n + 1; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[i] = point(a, b, c);
  }
  cin >> vHarry >> vBall;
  cin >> X >> Y >> Z;
  point harry = point(X, Y, Z);
  int po = -1;
  for (int i = 1; i < n + 1; ++i) {
    double disBall, disHarry;
    disBall = dist[i - 1] + dis(arr[i - 1], arr[i]);
    dist[i] = disBall;
    disHarry = dis(harry, arr[i]);
    double tHarry, tBall;
    tHarry = disHarry / vHarry;
    tBall = disBall / vBall;
    if (tBall >= tHarry) {
      po = i;
      break;
    }
  }
  if (po == -1) return puts("NO");
  puts("YES");
  point Pst, Pen, Pmd;
  Pst = arr[po - 1];
  Pen = arr[po];
  double st = dist[po - 1] / vBall, en = dist[po] / vBall;
  while (abs(st - en) > eps) {
    double md = (st + en) / 2;
    Pmd = point((Pst.x + Pen.x) / 2, (Pst.y + Pen.y) / 2, (Pst.z + Pen.z) / 2);
    double disBall, disHarry;
    disBall = dist[po - 1] + dis(arr[po - 1], Pmd);
    disHarry = dis(harry, Pmd);
    double tHarry, tBall;
    tHarry = disHarry / vHarry;
    tBall = disBall / vBall;
    if (tHarry < tBall)
      en = md, Pen = Pmd;
    else
      st = md, Pst = Pmd;
  }
  cout << setprecision(10) << fixed;
  cout << st << endl;
  cout << Pmd.x << ' ' << Pmd.y << ' ' << Pmd.z;
  return 0;
}
