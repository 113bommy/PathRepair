#include <bits/stdc++.h>
using namespace std;
static int read() {
  char c = getchar();
  int x = 0;
  for (; (c < '0' || c > '9') && c != '-'; c = getchar())
    ;
  int sig = 1;
  if (c == '-') {
    c = getchar();
    sig = -1;
  }
  for (; c >= '0' && c <= '9'; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  return sig * x;
}
int main() {
  int px, py, vx, vy, a, b, c, d;
  cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
  double nx = vx;
  double ny = vy;
  double len = sqrt(nx * nx + ny * ny);
  nx /= len;
  ny /= len;
  double kx = ny;
  double ky = -nx;
  cout << std::fixed << setprecision(10) << px + nx * b << " " << py + ny * b
       << endl;
  cout << setprecision(10) << px - kx * a / 2.0 << " " << py - ky * a / 2.0
       << endl;
  cout << setprecision(10) << px - kx * c / 2.0 << " " << py - ky * a / 2.0
       << endl;
  cout << setprecision(10) << px - nx * d - kx * c / 2.0 << " "
       << py - ny * d - ky * a / 2.0 << endl;
  cout << setprecision(10) << px - nx * d + kx * c / 2.0 << " "
       << py - ny * d + ky * a / 2.0 << endl;
  cout << setprecision(10) << px + kx * c / 2.0 << " " << py + ky * a / 2.0
       << endl;
  cout << setprecision(10) << px + kx * a / 2.0 << " " << py + ky * a / 2.0
       << endl;
  return 0;
}
