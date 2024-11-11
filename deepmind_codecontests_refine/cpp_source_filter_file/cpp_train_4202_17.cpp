#include <bits/stdc++.h>
using namespace std;
const int maxN = 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  long double a, b, m;
  cin >> a >> b >> m;
  long double vx, vy, vz;
  cin >> vx >> vy >> vz;
  long double ti = m / (-vy);
  long double px = a / 2 + ti * vx;
  while (px > 2 * a) px -= 2 * a;
  while (px + 2 * a < 0) px += 2 * a;
  if (px > a) px = 2 * a - px;
  if (px < 0) px = -px;
  long double pz = 0 + ti * vz;
  while (pz > 2 * b) pz -= 2 * b;
  while (pz + 2 * b < 0) pz += 2 * b;
  if (pz > b) pz = 2 * b - pz;
  if (pz < 0) pz = -pz;
  cout << fixed << setprecision(10) << px << ' ' << pz << endl;
  return 0;
}
