#include <bits/stdc++.h>
using namespace std;
class Point {
 public:
  int x;
  int y;
  int z;
};
int n;
Point points[10005];
Point harry;
int vp, vs;
int main(int argc, char** argv) {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    scanf("%d %d %d", &points[i].x, &points[i].y, &points[i].z);
  }
  scanf("%d %d", &vp, &vs);
  scanf("%d %d %d", &harry.x, &harry.y, &harry.z);
  bool ulovljen = false;
  double potHarry, potSnitch, potSnitchStara = 0;
  double casHarry, casSnitch;
  double xz, yz, zz, xk, yk, zk, x, y, z;
  if (harry.x == points[0].x && harry.y == points[0].y &&
      harry.z == points[0].z) {
    cout << "YES\n";
    cout << fixed << setprecision(8) << potSnitchStara << "\n";
    cout << fixed << setprecision(8) << (double)harry.x << " "
         << (double)harry.y << " " << (double)harry.z;
    return 0;
  }
  for (int i = 1; i < n + 1; i++) {
    potHarry =
        sqrt(pow(harry.x - points[i].x, 2) + pow(harry.y - points[i].y, 2) +
             pow(harry.z - points[i].z, 2));
    potSnitch = sqrt(pow(points[i - 1].x - points[i].x, 2) +
                     pow(points[i - 1].y - points[i].y, 2) +
                     pow(points[i - 1].z - points[i].z, 2));
    casHarry = potHarry / vp;
    casSnitch = (potSnitch + potSnitchStara) / vs;
    if (casHarry <= casSnitch) {
      ulovljen = true;
      xz = (double)points[i - 1].x;
      yz = (double)points[i - 1].y;
      zz = (double)points[i - 1].z;
      xk = (double)points[i].x;
      yk = (double)points[i].y;
      zk = (double)points[i].z;
      for (int j = 0; j < 200; j++) {
        x = (xz + xk) * 0.5;
        y = (yz + yk) * 0.5;
        z = (zz + zk) * 0.5;
        potHarry = sqrt(pow(harry.x - x, 2) + pow(harry.y - y, 2) +
                        pow(harry.z - z, 2));
        potSnitch =
            sqrt(pow(points[i - 1].x - x, 2) + pow(points[i - 1].y - y, 2) +
                 pow(points[i - 1].z - z, 2));
        casHarry = potHarry / vp;
        casSnitch = (potSnitch + potSnitchStara) / vs;
        if (casHarry < casSnitch + 1e-11) {
          xk = x;
          yk = y;
          zk = z;
        } else {
          xz = x;
          yz = y;
          zz = z;
        }
      }
      potSnitchStara += potSnitch;
      break;
    }
    potSnitchStara += potSnitch;
  }
  if (ulovljen) {
    cout << "YES\n";
    cout << fixed << setprecision(8) << casHarry << "\n";
    cout << fixed << setprecision(8) << xk << " " << yk << " " << zk;
  } else
    cout << "NO";
  return 0;
}
